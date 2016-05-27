/*
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
				cout<<8-i<<" |";

			}

			if(tab[i][j]==0)  cout<<" |";
			if((tab[i][j]->GetColor())=='black')  cout<<"b|";
			if((tab[i][j]->GetColor())=='white') cout<<"c|";

		}
		cout<<endl;
		cout<< "_______________________\n";
	}
}


