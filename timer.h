//
//  Created by Jean-Luc Deltombe (LX3JL) on 05/11/2015.
//  Copyright © 2015 Jean-Luc Deltombe (LX3JL). All rights reserved.
//  Copyright © 2020 Thomas A. Early N7TAE
//
// ----------------------------------------------------------------------------
//    This file is part of mrefd.
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    with this software.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#pragma once

#include <ctime>
#include <chrono>

#define STREAM_TIMEOUT 1.6

class CTimer
{
public:
	CTimer()
	{
		Start();
	}

	void Start()
	{
		starttime = std::chrono::steady_clock::now();
	}

	double Time() const
	{
		std::chrono::duration<double> elapsed(std::chrono::steady_clock::now() - starttime);
		return elapsed.count();
	}

private:
	std::chrono::steady_clock::time_point starttime;
};
