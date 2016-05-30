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



void MinMax::MinMaxRecursion(int depth, Pole player){
	if(depth <= DEPTH){
		Possibility pos;
		Pole next_player;
		if(player == White)
			next_player = Black;
		else if(player == Black)
			next_player = White;
		if(depth == 1)
			tmp_move.clear();
		for(int j = 0; j < 8; j++){
			for(int i = j%2; i < 8; i+=2){
				if(tab[i][j] == player){
					while((pos = M.CheckLeft(tab,i,j)) != Nothing){
						if(pos == MoveL){
							M.MoveLeft(tab,i,j);
							if(depth == 1)
								tmp_move.push_back(MoveL);
							stos.push(MoveL);
						}else if(pos == BeatL){
							M.BeatLeft(tab,i,j);
							if(depth == 1)
								tmp_move.push_back(BeatL);
							stos.push(BeatL);
						}
					}
					MinMaxRecursion(depth+1,next_player);
					while((pos = M.CheckRight(tab,i,j)) != Nothing){
						if(pos == MoveR){
							M.MoveRight(tab,i,j);
							if(depth == 1)
								tmp_move.push_back(MoveR);
							stos.push(MoveR);
						}
						else if(pos == BeatR){
							M.BeatRight(tab,i,j);
							if(depth == 1)
								tmp_move.push_back(BeatR);
							stos.push(BeatR);
						}
					}
					MinMaxRecursion(depth+1,next_player);
				}
			}
		}
	}else{
		if(Value()<value){
			value = Value();
			for(list<Possibility>::iterator it = tmp_move.begin(); it != tmp_move.end(); it++)
				move.push_back(*it);
		}
	}
}

void MinMax::Algorithm(Pole main_tab[8][8]){
	CopyTab(main_tab);
	value = INT_MAX;
}

