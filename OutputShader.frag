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

#version 130

uniform int width;
uniform int height;
uniform float[3] obj;
uniform float[3] x;
uniform float[3] y;
uniform float[3] w;
uniform float[3] h;
uniform float[3] colR;
uniform float[3] colG;
uniform float[3] colB;
uniform float[3] colA;

void main() {
	vec2 uv = gl_TexCoord[0].xy;
	float pixelX = (uv.x * width);
	float pixelY = (uv.y * height);

	gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	for (int i = 0; i < 3; ++i) {
		int type = int(obj[i]);
		switch(type){
			case 0:
				if(pixelX - x[i] >= 0 && pixelX - x[i] - w[i] <= 0 && pixelY - y[i] >= 0 && pixelY - y[i] - h[i] <= 0){
					gl_FragColor = vec4(colR[i], colG[i], colB[i], colA[i]);
				}
				break;
			case 1:
				float zeroX = (pixelX - x[i]);
				float zeroY = (pixelY - y[i]);
				if(zeroX * zeroX + zeroY * zeroY <= w[i]*w[i]){
					gl_FragColor = vec4(colR[i], colG[i], colB[i], colA[i]);
				}
				break;
		}
	}
}