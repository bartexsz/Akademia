/*
 * Move.cpp
 *
 *  Created on: May 29, 2016
 *      Author: damian
 */

#include "Move.hh"

Possibility Move::CheckLeftWhite(Pole tab[8][8], int x, int y){
	if(x == 1 || y == 6){
		if(tab[x-1][y+1] == Empty)
			return MoveL;
		else
			return 0;
	}else if(x > 1 && y < 6){
		if(tab[x-1][y+1] == Empty)
			return MoveL;
		else{
			if(tab[x-1][y+1] == Black)
				return Nothing;
			else if(tab[x-1][y+1] == White){
				if(tab[x-2][y+2] == Empty)
					return BeatL;
				else
					return Nothing;
			}
		}
	}
	return Nothing;
}

Possibility Move::CheckRightWhite(Pole tab[8][8], int x, int y){
	if(x == 6 || y == 6){
		if(tab[x+1][y+1] == Empty)
			return MoveR;
		else
			return Nothing;
	}else if(x < 6 && y < 6){
		if(tab[x+1][y+1] == Empty)
			return MoveR;
		else{
			if(tab[x+1][y+1] == Black)
				return Nothing;
			else if(tab[x+1][y+1] == White){
				if(tab[x+2][y+2] == Empty)
					return BeatR;
				else
					return Nothing;
			}
		}
	}
	return Nothing;
}

void Move::MoveLeftWhite(Pole tab[8][8], int x, int y){
	tab[x-1][y+1] = tab[x][y];
	tab[x][y] = Empty;

}

void Move::MoveRightWhite(Pole tab[8][8], int x, int y){
	tab[x+1][y+1] = tab[x][y];
	tab[x][y] = Empty;

}

void Move::BeatLeftWhite(Pole tab[8][8], int x, int y){
	tab[x-2][y+2] = tab[x][y];
	tab[x-1][y+1] = Empty;
	tab[x][y] = Empty;
}

void Move::BeatRightWhite(Pole tab[8][8], int x, int y){
	tab[x+2][y+2] = tab[x][y];
	tab[x+1][y+1] = Empty;
	tab[x][y] = Empty;
}

void Move::ReturnMoveLeftWhite(Pole tab[8][8], int x, int y){
	tab[x+1][y-1] = tab[x][y];
	tab[x][y] = Empty;

}

void Move::ReturnMoveRightWhite(Pole tab[8][8], int x, int y){
	tab[x-1][y-1] = tab[x][y];
	tab[x][y] = Empty;

}

void Move::ReturnBeatLeftWhite(Pole tab[8][8], int x, int y){
	tab[x+2][y-2] = tab[x][y];
	if(tab[x][y] == White)
		tab[x+1][y-1] = Black;
	else if(tab[x][y] == Black)
		tab[x+1][y-1] = White;
	tab[x][y] = Empty;
}

void Move::ReturnBeatRightWhite(Pole tab[8][8], int x, int y){
	tab[x-2][y-2] = tab[x][y];
	if(tab[x][y] == White)
		tab[x-1][y-1] = Black;
	else if(tab[x][y] == Black)
		tab[x-1][y-1] = White;
	tab[x][y] = Empty;
}


Possibility Move::CheckLeftBlack(Pole tab[8][8], int x, int y){
	if(x == 6 || y == 1){
		if(tab[x+1][y-1] == Empty)
			return MoveL;
		else
			return Nothing;
	}else if(x < 6 && y > 1){
		if(tab[x+1][y-1] == Empty)
			return MoveL;
		else{
			if(tab[x+1][y-1] == Black)
				return Nothing;
			else if(tab[x+1][y-1] == White){
				if(tab[x+2][y-2] == Empty)
					return BeatL;
				else
					return Nothing;
			}
		}
	}
	return Nothing;
}

Possibility Move::CheckRightBlack(Pole tab[8][8], int x, int y){
	if(x == 1 || y == 1){
		if(tab[x-1][y-1] == Empty)
			return MoveR;
		else
			return Nothing;
	}else if(x > 1 && y > 1){
		if(tab[x-1][y-1] == Empty)
			return MoveR;
		else{
			if(tab[x-1][y-1] == Black)
				return Nothing;
			else if(tab[x-1][y-1] == White){
				if(tab[x-2][y-2] == Empty)
					return BeatR;
				else
					return Nothing;
			}
		}
	}
	return Nothing;
}

void Move::MoveLeftBlack(Pole tab[8][8], int x, int y){
	tab[x+1][y-1] = tab[x][y];
	tab[x][y] = Empty;

}

void Move::MoveRightBlack(Pole tab[8][8], int x, int y){
	tab[x-1][y-1] = tab[x][y];
	tab[x][y] = Empty;

}

void Move::BeatLeftBlack(Pole tab[8][8], int x, int y){
	tab[x+2][y-2] = tab[x][y];
	tab[x+1][y-1] = Empty;
	tab[x][y] = Empty;
}

void Move::BeatRightBlack(Pole tab[8][8], int x, int y){
	tab[x-2][y-2] = tab[x][y];
	tab[x-1][y-1] = Empty;
	tab[x][y] = Empty;
}

void Move::ReturnMoveLeftBlack(Pole tab[8][8], int x, int y){
	tab[x-1][y+1] = tab[x][y];
	tab[x][y] = Empty;

}

void Move::ReturnMoveRightBlack(Pole tab[8][8], int x, int y){
	tab[x+1][y+1] = tab[x][y];
	tab[x][y] = Empty;

}

void Move::ReturnBeatLeftBlack(Pole tab[8][8], int x, int y){
	tab[x-2][y+2] = tab[x][y];
	if(tab[x][y] == White)
		tab[x-1][y+1] = Black;
	else if(tab[x][y] == Black)
		tab[x-1][y+1] = White;
	tab[x][y] = Empty;
}

void Move::ReturnBeatRightBlack(Pole tab[8][8], int x, int y){
	tab[x+2][y+2] = tab[x][y];
	if(tab[x][y] == White)
		tab[x+1][y+1] = Black;
	else if(tab[x][y] == Black)
		tab[x+1][y+1] = White;
	tab[x][y] = Empty;
}


