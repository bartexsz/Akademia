/*
 * MinMax.cpp
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#include "MinMax.hh"

void MinMax::CopyTab(Pole main_tab[8][8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++)
			tab[i][j] = main_tab[i][j];
	}
}

int MinMax::Value(int x, int y){
	int wartosc = 0;
	if(y >= 0 && y < 2)
		wartosc += 1;
	else if(y > 1 && y < 4)
		wartosc += 2;
	else if(y > 3 && y < 6)
		wartosc += 3;
	else if(y > 5 && y < 8)
		wartosc += 4;

	if(y  < 1 || y > 6 || x < 1 || x > 6)
		wartosc += 6;
	else if(y  < 2 || y > 5 || x < 2 || x > 5)
		wartosc += 4;
	else
		wartosc += 2;
	return wartosc;
}

void MinMax::MakeTree(Pole main_tab[8][8]){
	CopyTab(main_tab);
	for(int j = 0; j < 8; j++){
		for(int i = j%2; i < 8; i+=2){
			if(tab[i][j] == Black){
				M.CheckLeft(tab, i, j);
			}
		}
	}
}
