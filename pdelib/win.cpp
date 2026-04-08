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

#ifndef CPDE_WIN
#define CPDE_WIN
#include "PApplet.cpp"
#include <stdint.h>

void PApplet::windowTitle(const char *title){
	(*win).setTitle(title);
}

void PApplet::windowResize(uint32_t w, uint32_t h){
	width = w;
	height = h;
	(*win).setSize(sf::Vector2u(w, h));
}

void PApplet::windowResizable(bool rs){
	_resizable = rs;
}

void PApplet::windowMove(uint32_t x, uint32_t y){
	(*win).setPosition(sf::Vector2i(x, y));
}

#endif