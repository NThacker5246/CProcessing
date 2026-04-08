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

#include <cstdint>
#include <iostream>

class String
{
	char *reference;
	uint32_t _length, _maxlen;

public:
	String(char *into){
		reference = into;
		for (uint32_t i = 0;; ++i){
			if(reference[i] == '\0'){
				_length = i;
				_maxlen = i;
				break;
			}
		}
	}
	String(char *into, int ma){
		reference = into;
		for (uint32_t i = 0;; ++i){
			if(reference[i] == '\0'){
				_length = i;
				_maxlen = ma;
				break;
			}
		}
	}
	String(const char *into){
		reference = (char*) into;		
		for (uint32_t i = 0;; ++i){
			if(reference[i] == '\0'){
				_length = i;
				_maxlen = i; 
				break;
			}
		}
	}

	void print(){
		for (uint32_t i = 0; i < _length; ++i){
			std::cout << reference[i];
		}
	}
	void println(){
		for (uint32_t i = 0; i < _length; ++i){
			std::cout << reference[i];
		}
		std::cout << "\n";
	}

	void reserve(uint32_t add){
		_maxlen += add;
		char *nstr = new char[_maxlen];
		for(int i = 0; i < _length; ++i){
			nstr[i] = reference[i];
		}
		delete[] reference; //cleanup
		reference = nstr;
	}

	void operator+=(String *other){
		if(_maxlen - _length >= other->_length){
			for(int i = _length; i < other->_length + _length; ++i){
				reference[i] = other->reference[i - _length];
			}
		} else {
			_maxlen = other->_length + _length + 1; 
			char *nstr = new char[_maxlen];
			for(int i = 0; i < _length; ++i){
				nstr[i] = reference[i];
			}
			for(int i = 0; i < other->_length; ++i){
				nstr[_length + i] = other->reference[i];
			}
			nstr[_maxlen - 1] = '\0';
			_length = _maxlen;
			delete[] reference;
			reference = nstr;
			other->~String();
		}
	}
	void operator+=(char *other){
		uint32_t len = 0;
		for (uint32_t i = 0;; ++i){
			if(other[i] == '\0'){
				len = i;
				break;
			}
		}

		if(_maxlen - _length > len){
			for(int i = _length; i < len + _length; ++i){
				reference[i] = other[i - _length];
			} 
			reference[_length + len] = '\0';
			_length += len;
		} else {
			_maxlen = len + _length + 1; 
			char *nstr = new char[_maxlen];
			for(int i = 0; i < _length; ++i){
				nstr[i] = reference[i];
			}
			for(int i = 0; i < _length; ++i){
				nstr[_length + i] = other[i];
			}
			nstr[_maxlen - 1] = '\0';
			_length = _maxlen;
			delete[] reference;
			reference = nstr;
		}
	}

	void operator+=(const char *other){
		uint32_t len = 0;
		for (uint32_t i = 0;; ++i){
			if(other[i] == '\0'){
				len = i;
				break;
			}
		}

		if(_maxlen - _length > len){
			for(int i = _length; i < len + _length; ++i){
				reference[i] = other[i - _length];
			} 
			reference[_length + len] = '\0';
			_length += len;
		} else {
			_maxlen = len + _length + 1; 
			char *nstr = new char[_maxlen];
			for(int i = 0; i < _length; ++i){
				nstr[i] = reference[i];
			}
			for(int i = 0; i < len; ++i){
				nstr[_length + i] = other[i];
			}
			nstr[_maxlen - 1] = '\0';
			_length = _maxlen;
			delete[] reference;
			reference = nstr;
		}
	}
	
	String *operator+(){
		char
	}

	~String(){
		delete[] reference;
	}
};
