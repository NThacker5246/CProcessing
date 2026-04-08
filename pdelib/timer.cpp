/*
	This file is part of CProcessing.
	CProcessing is free software: you can redistribute it and/or modify it under the terms
	of the GNU General Public License as published by the Free Software Foundation; 
	either version 3 of the License, or (at your option) any later version.
	CProcessing is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the GNU General Public License for more details.
	You should have received a copy of the GNU General Public License along with this program. 
	If not, see <https://www.gnu.org/licenses/>.

	Copyright (C) NThacker5246 2026
*/

#ifndef CPDE_TIMER
#define CPDE_TIMER

#include <time.h>
#include <stdint.h>
#include "PApplet.cpp"

uint32_t PApplet::millis(){
	static clock_t last_tick;
	static bool started = false;
	if(!started){
		last_tick = clock();
		started = true;
	}

	return (uint32_t) ((clock() - last_tick) * 1000 / CLOCKS_PER_SEC);
}

uint32_t PApplet::micros(){
	static clock_t last_tick;
	static bool started = false;
	if(!started){
		last_tick = clock();
		started = true;
	}

	return (uint32_t) ((clock() - last_tick) * 1000000 / CLOCKS_PER_SEC);
}

void PApplet::delay(uint32_t wait_ms){
	static uint32_t last_mil = 0;
	last_mil = millis();
	while(millis() - last_mil < wait_ms){
		PApplet::yield();
	}
	return;
}

void PApplet::delayMicroseconds(uint32_t wait_us){
	static uint32_t last_us = 0;
	last_us = micros();
	while(micros() - last_us < wait_us){
		PApplet::yield();
	}
	return;
}

#endif