/*
 * Move.hh
 *
 *  Created on: May 29, 2016
 *      Author: damian
 */

#ifndef MOVE_HH_
#define MOVE_HH_
#include<iostream>
using namespace std;

enum Pole{
	Empty=0, White=1, Black=2, WhiteQueen=3, BlackQueen=4
};

enum Possibility{
	Nothing=0, MoveL=1, MoveR=2, BeatL=3, BeatR=4
};

class Move{
public:
	Possibility CheckLeft(Pole tab[8][8], int x, int y); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	Possibility CheckRight(Pole tab[8][8], int x, int y); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	void MoveLeft(Pole tab[8][8], int x, int y);
	void MoveRight(Pole tab[8][8], int x, int y);
	void BeatLeft(Pole tab[8][8], int x, int y);
	void BeatRight(Pole tab[8][8], int x, int y);
	void ReturnMoveLeft(Pole tab[8][8], int x, int y);
	void ReturnMoveRight(Pole tab[8][8], int x, int y);
	void ReturnBeatLeft(Pole tab[8][8], int x, int y);
	void ReturnBeatRight(Pole tab[8][8], int x, int y);
};



#endif /* MOVE_HH_ */
