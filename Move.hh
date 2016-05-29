/*
 * Move.hh
 *
 *  Created on: May 29, 2016
 *      Author: damian
 */

#ifndef MOVE_HH_
#define MOVE_HH_

using namespace std;

enum Pole{
	Empty, White, Black, WhiteQueen, BlackQueen
};

enum Possibility{
	Nothing, MoveL, MoveR, BeatL, BeatR
};

class Move{
public:
	Possibility CheckLeftWhite(Pole tab[8][8], int x, int y); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	Possibility CheckRightWhite(Pole tab[8][8], int x, int y); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	void MoveLeftWhite(Pole tab[8][8], int x, int y);
	void MoveRightWhite(Pole tab[8][8], int x, int y);
	void BeatLeftWhite(Pole tab[8][8], int x, int y);
	void BeatRightWhite(Pole tab[8][8], int x, int y);
	void ReturnMoveLeftWhite(Pole tab[8][8], int x, int y);
	void ReturnMoveRightWhite(Pole tab[8][8], int x, int y);
	void ReturnBeatLeftWhite(Pole tab[8][8], int x, int y);
	void ReturnBeatRightWhite(Pole tab[8][8], int x, int y);
	Possibility CheckLeftBlack(Pole tab[8][8], int x, int y); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	Possibility CheckRightBlack(Pole tab[8][8], int x, int y); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	void MoveLeftBlack(Pole tab[8][8], int x, int y);
	void MoveRightBlack(Pole tab[8][8], int x, int y);
	void BeatLeftBlack(Pole tab[8][8], int x, int y);
	void BeatRightBlack(Pole tab[8][8], int x, int y);
	void ReturnMoveLeftBlack(Pole tab[8][8], int x, int y);
	void ReturnMoveRightBlack(Pole tab[8][8], int x, int y);
	void ReturnBeatLeftBlack(Pole tab[8][8], int x, int y);
	void ReturnBeatRightBlack(Pole tab[8][8], int x, int y);
};



#endif /* MOVE_HH_ */
