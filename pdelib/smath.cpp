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

#ifndef CPDE_MATH
#define CPDE_MATH

#include "PApplet.cpp"
#include <stdint.h>
#include <math.h>

#define QUATER_PI 0.78539816339744830961566084581988
#define HALF_PI 1.5707963267948966192313216916398
#define PI 3.1415926535897932384626433832795
#define TWO_PI 6.283185307179586476925286766559
#define TAU 6.283185307179586476925286766559

#define RAD 0.01745329251994329576923690768489
#define GRAD 57.295779513082320876798154814092

#define EULER_CONST 2.71828182845904525359
#define TAYLOR_ITERATIONS 20

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

double PApplet::map(double x, double a, double b, double c, double d){
	return (x * (d - c) - a * b + c * b) / (b - a);
}

double PApplet::norm(double x, double a, double b){
	return map(x, a, b, 0, 1);
}

double PApplet::lerp(double a, double b, double t){
	return (a + (b - a) * t);
}

double PApplet::constrain(double val, double minV, double maxV){
	return min(max(val, minV), maxV);
}

double PApplet::radians(double a){
	return a * RAD;
}

double PApplet::degrees(double a){
	return a * GRAD;
}

float PApplet::map(float x, float a, float b, float c, float d){
	return (x * (d - c) - a * b + c * b) / (b - a);
}

float PApplet::norm(float x, float a, float b){
	return map(x, a, b, 0, 1);
}

float PApplet::lerp(float a, float b, float t){
	return (a + (b - a) * t);
}

float PApplet::constrain(float val, float minV, float maxV){
	return min(max(val, minV), maxV);
}

float PApplet::radians(float a){
	return a * RAD;
}

float PApplet::degrees(float a){
	return a * GRAD;
}

#endif