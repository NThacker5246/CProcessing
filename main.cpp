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

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <time.h>
#include <stdint.h>
#include <fstream>

#include "pdelib/PApplet.cpp"
#include "pdelib/win.cpp"
#include "pdelib/timer.cpp"
#include "pdelib/smath.cpp"


int main(int argc, char const *argv[])
{
	PApplet *applet = new PApplet();
	applet->main(argc, argv);
	return 0;
}



//int argc, char const *argv[]