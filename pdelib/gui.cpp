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

#ifndef CPDE_GUI
#define CPDE_GUI
struct li_em
{
	float id;
	float x;
	float y;
	float w;
	float h;

	float cR;
	float cG;
	float cB;
	float cA;
	li_em *prev;
};

class List
{
public:
	li_em *current;
	float *ids;
	float *x;
	float *y;
	float *w;
	float *h;

	float *cRn;
	float *cGn;
	float *cBn;
	float *cAn;
	int count, last_count,set_count;
	sf::Shader *shad;
	List(sf::Shader *sha){
		this->current = new li_em();
		this->current->id = 1;
		count = 0;
		last_count = 0;
		x = nullptr;
		shad = sha;
	}

	void clear(){
		set_count = 0;
	}

	void set(float id, float ax, float ay, float aw, float ah, float cR, float cG, float cB, float cA){
		if(set_count >= count) {add(id, ax, ay, aw, ah, cR, cG, cB, cA); ++set_count; return;}

		ids[set_count] = id;
		x[set_count] = ax;
		y[set_count] = ay;
		w[set_count] = aw;
		h[set_count] = ah;
		cRn[set_count] = cA;
		cGn[set_count] = cG;
		cBn[set_count] = cB;
		cAn[set_count] = cA;
		++set_count;
	}

	void set(int i, float id, float ax, float ay, float aw, float ah, float cR, float cG, float cB, float cA){
		ids[i] = id;
		x[i] = ax;
		y[i] = ay;
		w[i] = aw;
		h[i] = ah;
		cRn[i] = cA;
		cGn[i] = cG;
		cBn[i] = cB;
		cAn[i] = cA;
	}

	void add(float id, float ax, float ay, float aw, float ah, float cR, float cG, float cB, float cA){
		li_em *o = new li_em();
		o->id = id;
		o->x = ax;
		o->y = ay;
		o->w = aw;
		o->h = ah;
		
		o->cR = cR;
		o->cG = cG;
		o->cB = cB;
		o->cA = cA;

		o->prev = current;
		this->current = o;
		++count;
	}

	void flush(){
		if(last_count == count) return;
		li_em *nc = current;
		float *_ids = new float[count];
		float *_x = new float[count];
		float *_y = new float[count];
		float *_w = new float[count];
		float *_h = new float[count];
		float *_cRn = new float[count];
		float *_cGn = new float[count];
		float *_cBn = new float[count];
		float *_cAn = new float[count];

		bool isNew = false;

		if(x != nullptr){
			for (int i = 0; i < last_count; ++i)
			{
				_ids[i] = ids[i];
				_x[i] = x[i];
				_y[i] = y[i];
				_w[i] = w[i];
				_h[i] = h[i];
				_cRn[i] = cRn[i];
				_cGn[i] = cGn[i];
				_cBn[i] = cBn[i];
				_cAn[i] = cAn[i];
			}
		} else {
			x = _x;
			y = _y;
			w = _w;
			h = _h;
			ids = _ids;
			cRn = _cRn;
			cGn = _cGn;
			cBn = _cBn;
			cAn = _cAn;
			isNew = true;
		}

		if(!isNew){
			// delete[] ids;
			// delete[] x;
			// delete[] y;
			// delete[] w;
			// delete[] h;
			// delete[] cRn;
			// delete[] cGn;
			// delete[] cBn;
			// delete[] cAn;

			x = _x;
			y = _y;
			w = _w;
			h = _h;
			ids = _ids;
			cRn = _cRn;
			cGn = _cGn;
			cBn = _cBn;
			cAn = _cAn;
		}


		int i = count;
		while(nc != nullptr){
			--i;
			std::cout << nc->id << "\n\0";
			ids[i] = nc->id;
			x[i] = nc->x;
			y[i] = nc->y;
			w[i] = nc->w;
			h[i] = nc->h;

			cRn[i] = nc->cR;
			cGn[i] = nc->cG;
			cBn[i] = nc->cB;
			cAn[i] = nc->cA;
			nc = nc->prev;
		}
		for (int k = 0; k < count; ++k)
		{
			std::cout << x[k] << " " << y[k] << " " << w[k] << " " << h[k] << " " << cRn[k]  << " " << cGn[k]  << " " << cBn[k]  << " " << cAn[k] << "\n\0";
		}
		std::fstream fs("shader.frag", std::ios::out);
		fs << "#version 130\n\n"
		<< "uniform int width;\n"
		<< "uniform int height;\n"
		<< "uniform float[" << count << "] obj;\n"
		<< "uniform float[" << count << "] x;\n"
		<< "uniform float[" << count << "] y;\n"
		<< "uniform float[" << count << "] w;\n"
		<< "uniform float[" << count << "] h;\n"
		<< "uniform float[" << count << "] colR;\n"
		<< "uniform float[" << count << "] colG;\n"
		<< "uniform float[" << count << "] colB;\n"
		<< "uniform float[" << count << "] colA;\n\n"
		<< "void main() {\n"
		<< "\tvec2 uv = gl_TexCoord[0].xy;\n"
		<< "\tfloat pixelX = (uv.x * width);\n"
		<< "\tfloat pixelY = (uv.y * height);\n\n"
		<< "\tgl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
		<< "\tfor (int i = 0; i < " << count << "; ++i) {\n"
		<< "\t\tint type = int(obj[i]);\n"
		<< "\t\tswitch(type){\n"
		<< "\t\t\tcase 0:\n"
		<< "\t\t\t\tif(pixelX - x[i] >= 0 && pixelX - x[i] - w[i] <= 0 && pixelY - y[i] >= 0 && pixelY - y[i] - h[i] <= 0){\n"
		<< "\t\t\t\t\tgl_FragColor = vec4(colR[i], colG[i], colB[i], colA[i]);\n"
		<< "\t\t\t\t}\n"
		<< "\t\t\t\tbreak;\n"
		<< "\t\t\tcase 1:\n"
		<< "\t\t\t\tfloat zeroX = (pixelX - x[i]);\n"
		<< "\t\t\t\tfloat zeroY = (pixelY - y[i]);\n"
		<< "\t\t\t\tif(zeroX * zeroX + zeroY * zeroY <= w[i]*w[i]){\n"
		<< "\t\t\t\t\tgl_FragColor = vec4(colR[i], colG[i], colB[i], colA[i]);\n"
		<< "\t\t\t\t}\n"
		<< "\t\t\t\tbreak;\n"
		<< "\t\t}\n"
		<< "\t}\n"
		<< "}";

		last_count = count;

		fs.close();
		shad->loadFromFile("shader.frag", sf::Shader::Fragment);
	}
	~List();
	
};
#endif

