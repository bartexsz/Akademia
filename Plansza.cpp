/*
 * Plansza.cpp
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */
/*
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

void Pionek::SetWartosc(int w){
	_wartosc = w;
}
int Pionek::GetWartosc(){
	return _wartosc;
}

void Tablica::Wyswietl()
{

	cout<<"jou\n";
	for(int j=0; j<8; j++)
	{
		for(int i=0;i<8;i++)
		{
			cout<<"dla x:"<<i<<" i y:"<<j<<"->";
			if (tab[i][j]==0) cout<<"0"<<endl;
			else
				{
					if((tab[i][j]->GetColor())==black) cout<<"czarny\n";
					else cout<<"bialy\n";
				}
		}
	}


	for(int j=7; j>=0; j--)
	{
		for(int i=0; i<8; i++)
		{
			if(i==0)
			{
				cout<<j<<"  |";

			}
			if((((j%2)==0)&&((i%2)==1))||(((j%2)==1)&&((i%2)==0))) cout<<"_|";
			else
			{
			if(tab[i][j]==0)  cout<<" |";
			else
			{
				if(tab[i][j]==Black) cout<<"c|";
				if(tab[i][j]==White) cout<<"b|";
			}
			}

		}
		cout<<endl;
	}
	cout<<"    ";
	for (int i=0; i<8; i++)
	{
		cout<<i<<" ";
	}
}


void Tablica::Initiation()
{
	int tmp;
	for(int j = 0; j < 3; j++)
	{
		for(int i = j%2; i < 8; i+=2){
			Pionek P(white,i,j);
			WhiteList.push_back(P);
			tab[i][j] = &WhiteList.back();
			SetWartosc(tab[i][j]);
			cout<<"Bialy pionek dla:"<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 0; j < 3; j++)
	{
		if((j%2)==0) tmp=1;
		else tmp=0;
		for(int i =tmp; i < 8; i+=2)
		{
			tab[i][j] = 0;
			cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 3; j < 5; j++){
		for(int i =0; i < 8; i++){
			tab[i][j] = 0;
			cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 5; j < 8; j++){
		for(int i = j%2; i < 8; i+=2){
			Pionek P(black,i,j);
			BlackList.push_back(P);
			tab[i][j] = &BlackList.back();
			SetWartosc(tab[i][j]);
			cout<<"Czarny pionek dla:"<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 5; j < 8; j++){
				if((j%2)==0) tmp=1;
				else tmp=0;
			for(int i =tmp; i < 8; i+=2){

				tab[i][j] = 0;
				cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
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

void Tablica::SetWartosc(Pionek *P){
	int wartosc = 0;
	if(P->GetY() >= 0 && P->GetY() < 2)
		wartosc += 1;
	else if(P->GetY() > 1 && P->GetY() < 4)
		wartosc += 2;
	else if(P->GetY() > 3 && P->GetY() < 6)
		wartosc += 3;
	else if(P->GetY() > 5 && P->GetY() < 8)
		wartosc += 4;

	if(P->GetY()  < 1 || P->GetY() > 6 || P->GetX() < 1 || P->GetX() > 6)
		wartosc += 6;
	else if(P->GetY()  < 2 || P->GetY() > 5 || P->GetX() < 2 || P->GetX() > 5)
		wartosc += 4;
	else
		wartosc += 2;
	P->SetWartosc(wartosc);
}

int Move::CheckLeft(Pionek *tab[8][8], Pionek P){
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

int Move::CheckRight(Pionek *tab[8][8],Pionek P){
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

void Move::MoveLeft(Pionek *tab[8][8], Pionek *P){
	tab[P->GetX()-1][P->GetY()+1] = P;
	tab[P->GetX()][P->GetY()] = 0;
	P->SetX(P->GetX()-1);
	P->SetY(P->GetY()+1);
}

void Move::MoveRight(Pionek *tab[8][8], Pionek *P){
	tab[P->GetX()+1][P->GetY()+1] = P;
	tab[P->GetX()][P->GetY()] = 0;
	P->SetX(P->GetX()+1);
	P->SetY(P->GetY()+1);
}

void Move::BeatLeft(Pionek *tab[8][8], Pionek *P){
	tab[P->GetX()-2][P->GetY()+2] = P;
	tab[P->GetX()-1][P->GetY()+1] = 0;
	tab[P->GetX()][P->GetY()] = 0;
	P->SetX(P->GetX()-2);
	P->SetY(P->GetY()+2);
}

void Move::BeatRight(Pionek *tab[8][8], Pionek *P){
	tab[P->GetX()+2][P->GetY()+2] = P;
	tab[P->GetX()+1][P->GetY()+1] = 0;
	tab[P->GetX()][P->GetY()] = 0;
	P->SetX(P->GetX()+2);
	P->SetY(P->GetY()+2);
}

int Move::GetWartosc(Pionek P){
	int wartosc = 0;
	if(P.GetY() >= 0 && P.GetY() < 2)
		wartosc += 1;
	else if(P.GetY() > 1 && P.GetY() < 4)
		wartosc += 2;
	else if(P.GetY() > 3 && P.GetY() < 6)
		wartosc += 3;
	else if(P.GetY() > 5 && P.GetY() < 8)
		wartosc += 4;

	if(P.GetY()  < 1 || P.GetY() > 6 || P.GetX() < 1 || P.GetX() > 6)
		wartosc += 6;
	else if(P.GetY()  < 2 || P.GetY() > 5 || P.GetX() < 2 || P.GetX() > 5)
		wartosc += 4;
	else
		wartosc += 2;
	return wartosc;
}
*/
