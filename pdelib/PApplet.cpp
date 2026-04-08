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

#ifndef CPDE_PA
#define CPDE_PA

#include "gui.cpp"

#define WINDOWS 1
#define RWINDOWS 2
#define BACKSPACE 8
#define TAB 9
#define ENTER 10
#define RETURN 13
#define SHIFT 16
#define CONTROL 17
#define ALT 18
#define RSHIFT 19
#define RCONTROL 20
#define RALT 21
#define ESC 27
#define MENU 28

#define LEFT 37
#define UP 38
#define RIGHT 39
#define DOWN 40

#define DELETE 127
#define CODED 255

class PApplet
{
public:
	PApplet(){}
	~PApplet(){}
	int mouseX, mouseY, pmouseX, pmouseY;
	char key, keyCode;
	int width, height;
	bool _resizable; 
	sf::RenderWindow *win;
	sf::Shader *shad;
	List *l;
	
	int main(int argc, char const *argv[])
	{
		std::cout << argv[1] << "\n\0";
		width = 640;
		height = 360;
		millis();
		sf::Clock clock;

		sf::RenderWindow window(sf::VideoMode(width, height), "PApplet sample", sf::Style::Titlebar | sf::Style::Close | (_resizable ? sf::Style::Resize : sf::Style::None)); 
		window.setFramerateLimit(60);
		win = &window;

		sf::RenderTexture emptyTexture;
		emptyTexture.create(width, height);
		sf::Sprite emptySprite = sf::Sprite(emptyTexture.getTexture());
		sf::Shader shader;
		shad = &shader;
		
		l = new List(shad);
		setup(argv[1]);
		l->flush();

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close(); 
				}
				if (event.type == sf::Event::Resized)
				{
					width = event.size.width;
					height = event.size.height;
				}
			}

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			sf::Vector2i pmousePos = sf::Mouse::getPosition(window);
			mouseX = mousePos.x;
			mouseY = mousePos.y;
			pmouseX = pmousePos.x;
			pmouseY = pmousePos.y;

			for(int a = 0; a < 110; ++a){
				if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key) a)){
					switch(a){
						case 0 ... 25:
							key = 'A' + a;
							keyCode = 0;
							break;
						case 26 ... 35:
							key = '0' + (a-26);
							keyCode = 0;
							break;
						case 36:
							key = CODED;
							keyCode = ESC;
							break;
						case 37:
							key = CODED;
							keyCode = CONTROL;
							break;
						case 38:
							key = CODED;
							keyCode = SHIFT;
							break;
						case 39:
							key = CODED;
							keyCode = ALT;
							break;
						case 40:
							key = CODED;
							keyCode = WINDOWS;
							break;
						case 41:
							key = CODED;
							keyCode = RCONTROL;
							break;
						case 42:
							key = CODED;
							keyCode = RSHIFT;
							break;
						case 43:
							key = CODED;
							keyCode = RALT;
							break;
						case 44:
							key = CODED;
							keyCode = RWINDOWS;
							break;
						case 45:
							key = CODED;
							keyCode = MENU; 
						case 46:
							key = '[';
							keyCode = 0;
							break;
						case 47:
							key = ']';
							keyCode = 0;
							break;
						case 48:
							key = ';';
							keyCode = 0;
							break;
						case 49:
							key = ',';
							keyCode = 0;
							break;
						case 50:
							key = '.';
							keyCode = 0;
							break;
						case 51:
							key = '\'';
							keyCode = 0;
							break;
						case 52:
							key = '/';
							keyCode = 0;
							break;
						case 53:
							key = '\\';
							keyCode = 0;
							break;
						case 54:
							key = '`';
							keyCode = 0;
							break;
						case 55:
							key = '=';
							keyCode = 0;
							break;
						case 56:
							key = '-';
							keyCode = 0;
							break;
						case 57:
							key = ' ';
							keyCode = 0;
							break;
						case 58:
							key = '\n';
							keyCode = ENTER;
							break;
						case 60:
							key = '\b';
							keyCode = BACKSPACE;
							break;
						case 61:
							key = '\t';
							keyCode = TAB;
							break;
						case 62 ... 66:
							// key = '\n';
							break;
						case 67:
							key = '+';
							keyCode = 0;
							break;
						case 68:
							key = '-';
							keyCode = 0;
							break;
						case 69:
							key = '*';
							keyCode = 0;
							break;
						case 70:
							key = '/';
							keyCode = 0;
							break;
						case 71:
							key = CODED;
							keyCode = LEFT;
						case 72:
							key = CODED;
							keyCode = RIGHT;
						case 73:
							key = CODED;
							keyCode = UP;
						case 74:
							key = CODED;
							keyCode = DOWN;
							break;
						case 75 ... 85:
							key = '0' + (a - 75);
							break;
					}
				}
			}

			draw();

			// std::cout << "x: " << mousePos.x << "; y: " << mousePos.y << "\n\0";
			// std::cout << millis();
			shader.setUniform("width", width);
			shader.setUniform("height", height);
			shader.setUniformArray("x", l->x, l->count);
			shader.setUniformArray("y", l->y, l->count);
			shader.setUniformArray("w", l->w, l->count);
			shader.setUniformArray("h", l->h, l->count);
			shader.setUniformArray("colR", l->cRn, l->count);
			shader.setUniformArray("colG", l->cGn, l->count);
			shader.setUniformArray("colB", l->cBn, l->count);
			shader.setUniformArray("colA", l->cAn, l->count);
			shader.setUniformArray("obj", l->ids, l->count);
			window.draw(emptySprite, shad);
			window.display();
		}
		return 0;
	}

	void setup(const char *args){
		l->add(0, 20, 30, 50, 50, 0.7, 0.7, 0.7, 0.8);
		l->add(1, 130, 30, 50, 50, 0.2, 0.2, 0.7, 0.8);
		l->add(0, 240, 30, 50, 50, 0.7, 0.2, 0.2, 0.8);
		l->add(0, 20, 90, 100, 50, 0.7, 0.2, 0.2, 0.8);
		l->add(0, 130, 90, 100, 50, 0.2, 0.8, 0.8, 0.8);
		l->add(0, 240, 90, 100, 50, 0.2, 0.8, 0.9, 0.8);
		l->add(0, 370, 90, 100, 50, 0.2, 0.8, 0.9, 0.8);
	}

	void draw(){
		static uint32_t tmr = millis();
		if(millis() - tmr <= 1000){
			tmr = millis();
			l->set(2, 0, constrain((float) mouseX, 0, (float) width), constrain((float) mouseY, 0, (float) height), 50, 50, 0.7, 0.2, 0.2, 0.8);
			// l->flush();
		}

		std::cout << key << "as" << (keyCode-'\0') << "\n\0";

	}

	uint32_t millis();
	uint32_t micros();
	void delay(uint32_t ms);
	void delayMicroseconds(uint32_t us);
	
	double map(double x, double a, double b, double c, double d);
	double norm(double x, double a, double b);
	double lerp(double a, double b, double t);
	double constrain(double val, double minV, double maxV);
	double radians(double a);
	double degrees(double a);

	float map(float x, float a, float b, float c, float d);
	float norm(float x, float a, float b);
	float lerp(float a, float b, float t);
	float constrain(float val, float minV, float maxV);
	float radians(float a);
	float degrees(float a);

	void windowTitle(const char *title);
	void windowResize(uint32_t w, uint32_t h);
	void windowResizable(bool rs);
	void windowMove(uint32_t x, uint32_t y);

	void yield(){
	
	}
};

#endif