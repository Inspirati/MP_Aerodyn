// This file is part of MatrixPilot.
//
//    http://code.google.com/p/gentlenav/
//
// Copyright 2009-2011 MatrixPilot Team
// See the AUTHORS.TXT file for a list of authors of MatrixPilot.
//
// MatrixPilot is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MatrixPilot is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with MatrixPilot.  If not, see <http://www.gnu.org/licenses/>.


#ifndef AIRSPEED_OPTIONS_H
#define AIRSPEED_OPTIONS_H

// Airspeeds in m/s
#define MINIMUM_GROUNDSPEED 		3.0
#define MINIMUM_AIRSPEED			8.0
#define MAXIMUM_AIRSPEED			25.0
#define CRUISE_AIRSPEED				10.0	// Gliding airspeed when aircraft is level
#define RTL_AIRSPEED				14.0	// return to launch airspeed

// Cruise airspeed may be below minimum airspeed for high drag aircraft.

// Gliding airspeed control
typedef enum
{
	ASP_CNTRL_STANDARD,
	ASP_CNTRL_TOTAL_ENERGY,
} ASPD_CNTRL;

#define AIRSPEED_CONTROL ASP_CNTRL_TOTAL_ENERGY

// When using total energy airsped control, this is the
// time constant used to target airspeed change.
// MUST NEVER BE SMALLER THAN 0.6
#define ASPD_ADJ_TIME_CONSTANT		1.0

// Pitch feedforward for gliding airspeed
// linearly interpolated from cruise airspeed to min and max airspeed
#define AIRSPEED_PITCH_MIN_ASPD		5.0		// Default off, start with 5.0
#define AIRSPEED_PITCH_MAX_ASPD		-10.0		// Default off, start with -10.0

// Maximum rate of pitch demand change in deg/s.  Used to make control smoother.
// Default 10.0, Higher for small aircraft. Too low may cause instability.
// Maximum value is 720deg/s.  
#define AIRSPEED_PITCH_ADJ_RATE		10.0

// Airspeed error integrator
#define AIRSPEED_PITCH_KI			0.04		// Integrataion rate.  High = unstable, low = slow response.
#define AIRSPEED_PITCH_KI_MAX		10.0			// Limit of integration control in degrees.  Start with 5.0.


#endif

