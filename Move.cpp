/*
 * Move.cpp
 *
 *  Created on: May 29, 2016
 *      Author: damian
 */

#include "Move.hh"

int Move::CheckLeft(Pole tab[8][8], int x, int y){
	if(x == 1 || y == 6){
		if(tab[x-1][y+1] == 0)
			return 1;
		else
			return 0;
	}else if(x > 1 && y < 6){
		if(tab[x-1][y+1] == 0)
			return 1;
		else{
			if(tab[x-1][y+1] == Black)
				return 0;
			else if(tab[x-1][y+1] == White){
				if(tab[x-2][y+2] == 0)
					return 2;
				else
					return 0;
			}
		}
	}
	return 0;
}

int Move::CheckRight(Pole tab[8][8], int x, int y){
	if(x == 6 || y == 6){
		if(tab[x+1][y+1] == 0)
			return 1;
		else
			return 0;
	}else if(x < 6 && y < 6){
		if(tab[x+1][y+1] == 0)
			return 1;
		else{
			if(tab[x+1][y+1] == Black)
				return 0;
			else if(tab[x+1][y+1] == White){
				if(tab[x+2][y+2] == 0)
					return 2;
				else
					return 0;
			}
		}
	}
	return 0;
}

void Move::MoveLeft(Pole tab[8][8], int x, int y){
	tab[x-1][y+1] = tab[x][y];
	tab[x][y] = 0;

}

void Move::MoveRight(Pole tab[8][8], int x, int y){
	tab[x+1][y+1] = tab[x][y];
	tab[x][y] = 0;

}

void Move::BeatLeft(Pole tab[8][8], int x, int y){
	tab[x-2][y+2] = tab[x][y];
	tab[x-1][y+1] = 0;
	tab[x][y] = 0;
}

void Move::BeatRight(Pole tab[8][8], int x, int y){
	tab[x+2][y+2] = tab[x][y];
	tab[x+1][y+1] = 0;
	tab[x][y] = 0;
}

int Move::GetWartosc(int x, int y){
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

