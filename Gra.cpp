/*
 * Gra.cpp
 *
 *  Created on: May 28, 2016
 *      Author: damian
 */


#include "Gra.hh"

void Gra::Initiation()
{
	int tmp;
	for(int j = 0; j < 3; j++)
	{
		for(int i = j%2; i < 8; i+=2){
			tab[i][j] = White;
			cout<<"Bialy pionek dla:"<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 0; j < 3; j++)
	{
		if((j%2)==0) tmp=1;
		else tmp=0;
		for(int i =tmp; i < 8; i+=2)
		{
			tab[i][j] = Empty;
			cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 3; j < 5; j++){
		for(int i =0; i < 8; i++){
			tab[i][j] = Empty;
			cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 5; j < 8; j++){
		for(int i = j%2; i < 8; i+=2){
			tab[i][j] = Black;
			cout<<"Czarny pionek dla:"<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 5; j < 8; j++){
				if((j%2)==0) tmp=1;
				else tmp=0;
			for(int i =tmp; i < 8; i+=2){

				tab[i][j] = Empty;
				cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
			}
		}
}
