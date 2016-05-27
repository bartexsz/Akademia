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


int Tablica::CheckLeft(Pionek P){
	if(P.GetX() == 1 || P.GetY() == 6){
		if(tab[P.GetX()-1][P.GetY()+1] == 0)
			return 1;
		else
			return 0;
	}else if(P.GetX() > 1 && P.GetY() < 6){
		if(tab[P.GetX()-1][P.GetY()+1] == 0)
			return 1;
		else{
			if(tab[P.GetX()-1][P.GetY()+1]->GetColor() == black)
				return 0;
			else if(tab[P.GetX()-1][P.GetY()+1]->GetColor() == white){
				if(tab[P.GetX()-2][P.GetY()+2] == 0)
					return 2;
				else
					return 0;
			}
		}
	}
	return 0;
}

int Tablica::CheckRight(Pionek P){
	if(P.GetX() == 6 || P.GetY() == 6){
		if(tab[P.GetX()+1][P.GetY()+1] == 0)
			return 1;
		else
			return 0;
	}else if(P.GetX() < 6 && P.GetY() < 6){
		if(tab[P.GetX()+1][P.GetY()+1] == 0)
			return 1;
		else{
			if(tab[P.GetX()+1][P.GetY()+1]->GetColor() == black)
				return 0;
			else if(tab[P.GetX()+1][P.GetY()+1]->GetColor() == white){
				if(tab[P.GetX()+2][P.GetY()+2] == 0)
					return 2;
				else
					return 0;
			}
		}
	}
	return 0;
}

void Tablica::MoveLeft(Pionek *P){
	tab[P->GetX()-1][P->GetY()+1] = P;
	tab[P->GetX()][P->GetY()] = 0;
	P->SetX(P->GetX()-1);
	P->SetY(P->GetY()+1);
}

void Tablica::MoveRight(Pionek *P){
	tab[P->GetX()+1][P->GetY()+1] = P;
	tab[P->GetX()][P->GetY()] = 0;
	P->SetX(P->GetX()+1);
	P->SetY(P->GetY()+1);
}

void Tablica::BeatLeft(Pionek *P){
	tab[P->GetX()-2][P->GetY()+2] = P;
	tab[P->GetX()-1][P->GetY()+1] = 0;
	tab[P->GetX()][P->GetY()] = 0;
	P->SetX(P->GetX()-2);
	P->SetY(P->GetY()+2);
}

void Tablica::BeatRight(Pionek *P){
	tab[P->GetX()+2][P->GetY()+2] = P;
	tab[P->GetX()+1][P->GetY()+1] = 0;
	tab[P->GetX()][P->GetY()] = 0;
	P->SetX(P->GetX()+2);
	P->SetY(P->GetY()+2);
}
