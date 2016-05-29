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

int MinMax::Value(){
	int wartosc = 0;
	int tmp;
	for(int j = 0; j < 8; j++){
		for(int i = j%2; i < 8; i+=2){
			tmp = 0;
			if(j >= 0 && j < 2)
				wartosc += 1;
			else if(j > 1 && j < 4)
				wartosc += 2;
			else if(j > 3 && j < 6)
				wartosc += 3;
			else if(j > 5 && j < 8)
				wartosc += 4;

			if(j  < 1 || j > 6 || i < 1 || i > 6)
				wartosc += 6;
			else if(j  < 2 || j > 5 || i < 2 || i > 5)
				wartosc += 4;
			else
				wartosc += 2;
			if(tab[i][j] == White)
				tmp = -tmp;
			wartosc += tmp;
		}
	}
	return wartosc;
}

void MinMax::MakeTree(Pole main_tab[8][8]){
	CopyTab(main_tab);
	for(int j = 0; j < 8; j++){
		for(int i = j%2; i < 8; i+=2){
			if(tab[i][j] == Black){
				Possibility = M.CheckLeft(tab, i, j);
				if(Possi)
			}
		}
	}
}
