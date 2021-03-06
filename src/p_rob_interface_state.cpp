/*
 /*!
 *****************************************************************
 * \file
 *
 * \note
 * Copyright (c) 2017 \n
 * Fraunhofer Institute for Manufacturing Engineering
 * and Automation (IPA) \n\n
 *
 *****************************************************************
 *
 * \note
 * ROS stack name: schunk_ft_sensor
 * \note
 * ROS package name: schunk_ft_sensor
 *
 * \author
 * Author: Turan Elchuev email: turan.elchuev@ipa.fraunhofer.de
 *
 * \date Date of creation: October, 2017
 *
 * \brief
 *
 * *****************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer. \n
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution. \n
 * - Neither the name of the Fraunhofer Institute for Manufacturing
 * Engineering and Automation (IPA) nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission. \n
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License LGPL for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 *
 ******************************************************************/

#include <p_rob_interface/p_rob_interface.h>

using namespace p_rob_interface;

bool PRobInterface::initialize()
{
	initialized = false;

	std::string status = get_state();

	if(status == RESP_FAILURE) return err(ERR_INIT);

	if(status == STATE_DISCONNECTED	&& (!connect() || !calibrate())) return err(ERR_INIT);

	initialized = true;

	return success(MES_INIT_SUCCESS);
}

bool PRobInterface::finalize()
{
	// TODO improve finalization
	initialized = false;
	return true;
}

bool PRobInterface::err(std::string mes)
{
	ROS_ERROR_STREAM("PRobInterface::error --> " << mes);
	return false;
}

bool PRobInterface::success(std::string mes)
{
	ROS_INFO_STREAM("PRobInterface::success --> " << mes);
	return true;
}
