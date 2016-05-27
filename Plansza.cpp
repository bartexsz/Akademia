/*
 * Plansza.cpp
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#include "Plansza.hh"

void Pionek::SetColor(color c){
	_c = c;
}
color Pionek::GetColor(){
	return _c;
}
void Pionek::SetX(int x){
	_x = x;
}
int Pionek::GetX(){
	return _x;
}
void Pionek::SetY(int y){
	_y = y;
}
int Pionek::GetY(){
	return _y;
}



