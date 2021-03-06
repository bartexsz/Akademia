/*
 * Move.hh
 *
 *  Created on: May 29, 2016
 *      Author: damian
 */

#ifndef MOVE_HH_
#define MOVE_HH_

#include<iostream>

#include<list>

using namespace std;

enum Pole{
	Empty, White, Black, WhiteQueen, BlackQueen
};

enum Possibility{
	Nothing, MoveL, MoveR, BeatL, BeatR
};


class MoveSequence{
private:
	list<Possibility> Sequence;
public:
	void push(Possibility P);
	Possibility pop();
	~MoveSequence(){
		Sequence.clear();
	}
};


class Move{
public:
	void Check(list<Possibility> &possibilities, Pole tab[8][8], int x, int y); //
	Possibility CheckLeft(Pole tab[8][8], int x, int y); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	Possibility CheckRight(Pole tab[8][8], int x, int y); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	void MoveLeft(Pole tab[8][8], int x, int y);
	void MoveRight(Pole tab[8][8], int x, int y);
	void BeatLeft(Pole tab[8][8], int x, int y);
	void BeatRight(Pole tab[8][8], int x, int y);
	void ReturnMoveLeft(Pole tab[8][8], int x, int y, Pole player);
	void ReturnMoveRight(Pole tab[8][8], int x, int y, Pole player);
	void ReturnBeatLeft(Pole tab[8][8], int x, int y, Pole player);
	void ReturnBeatRight(Pole tab[8][8], int x, int y, Pole player);
	bool Action(Possibility wybor, Pole tab[8][8], int x, int y);
	bool ReturnAction(Possibility wybor, Pole tab[8][8], int x, int y, Pole player);
};

#endif /* MOVE_HH_ */
