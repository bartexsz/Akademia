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

void Tablica::Wyswietl()
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			if(j==0)
			{
				//cout<<8-i<<" |";

			}

			//if(tab[i][j]=='pusty')  cout<<" |";
			//if(tab[i][j]=='bialy')  cout<<"b|";
			//if(tab[i][j]=='czarny') cout<<"c|";


		}
	}
}

void Tablica::Initiation(){
	for(int j = 0; j < 3; j++){
		for(int i = i%2; i < 8; i+=2){
			Pionek P(white,i,0);
			WhiteList.push_back(P);
			tab[i][j] = &WhiteList.back();
		}
	}
	for(int j = 3; j < 3; j++){
		for(int i = i%2; i < 8; i+=2){
			tab[i][j] = 0;
		}
	}
	for(int j = 0; j < 3; j++){
		for(int i = i%2; i < 8; i+=2){
			Pionek P(black,i,0);
			BlackList.push_back(P);
			tab[i][j] = &BlackList.back();
		}
	}
}
