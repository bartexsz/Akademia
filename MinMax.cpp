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




int MinMax::MinMaxRecursion(int depth, Pole player){
	cout<<"depth="<<depth<<endl;
	Pole next_player;
	int v;
	int best_value;
	int next_depth;

	if(depth = 0)
		return Value();

	if(depth == main_depth)
		tmp_move.clear();
	if(player == Black){
		cout<<"player == Black"<<endl;
		best_value = -INT_MAX;
		Possibility P;
		for(int j = 0; j < 8; j++){
			for(int i = j%2; i < 8; i+=2){
				//cout<<"i="<<i<<", j="<<j<<endl;
				if(tab[i][j] == player){
					if((P = M.CheckLeft(tab,i,j)) == MoveL)
						M.MoveLeft(tab,i,j);
					else if((P = M.CheckLeft(tab,i,j)) == BeatL)
						M.BeatLeft(tab,i,j);
					if((P = M.CheckLeft(tab,i,j)) == Nothing){
							next_player = White;
							next_depth = depth-1;
					}else{
						if(depth == main_depth){
							tmp_move.push_back(P);
							tmp_x = i;
							tmp_y = j;
						}
					}
					v = MinMaxRecursion(next_depth,next_player);
					cout<<"after recursion, depth="<<depth<<endl;
					if(P == MoveL)
						M.ReturnMoveLeft(tab,i,j);
					else if(P == BeatL)
						M.ReturnBeatLeft(tab,i,j);
					if(v>best_value){
						best_value = v;
						CopyMove();
					}
				}
			}
		}
		return best_value;
	}else if(player == White){
		cout<<"player == White"<<endl;
		best_value = INT_MAX;
		Possibility P;
		for(int j = 0; j < 8; j++){
			for(int i = j%2; i < 8; i+=2){
				if(tab[i][j] == player){
					//cout<<"i="<<i<<", j="<<j<<endl;
					if((P = M.CheckLeft(tab,i,j)) == MoveL)
						M.MoveLeft(tab,i,j);
					else if((P = M.CheckLeft(tab,i,j)) == BeatL)
						M.BeatLeft(tab,i,j);
					if((P = M.CheckLeft(tab,i,j)) == Nothing){
						next_player = Black;
						next_depth = depth-1;
					}else{
						if(depth == main_depth){
							tmp_move.push_back(P);
							tmp_x = i;
							tmp_y = j;
						}
					}
					v = MinMaxRecursion(next_depth,next_player);
					cout<<"after recursion, depth="<<depth<<endl;
					if(P == MoveR)
						M.ReturnMoveRight(tab,i,j);
					else if(P == BeatR)
						M.ReturnBeatRight(tab,i,j);
					if(v>best_value){
						best_value = v;
						CopyMove();
					}
				}
			}
		}
		return best_value;
	}
}


void MinMax::Algorithm(Pole main_tab[8][8],int depth, list<Possibility> &Lista, int &xx, int &yy){
	CopyTab(main_tab);
	main_depth = depth;
	MinMaxRecursion(depth,Black);
	for(list<Possibility>::iterator it = move.begin(); it != move.end(); it++)
		Lista.push_back(*it);
	xx=x;
	yy=y;
}

void MinMax::CopyMove(){
	for(list<Possibility>::iterator it = tmp_move.begin(); it != tmp_move.end(); it++)
		move.push_back(*it);
	x = tmp_x;
	y = tmp_y;

}

