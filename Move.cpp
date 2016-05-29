/*
 * Move.cpp
 *
 *  Created on: May 29, 2016
 *      Author: damian
 */

#include "Move.hh"

Possibility Move::CheckLeft(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
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
	}else if(tab[x][y] == Black){
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
	}
	return Nothing;
}

Possibility Move::CheckRight(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
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
	}else if(tab[x][y] == Black){
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
	}
	return Nothing;
}

void Move::MoveLeft(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
		tab[x-1][y+1] = tab[x][y];
		tab[x][y] = Empty;
	}else if(tab[x][y] == Black){
		tab[x+1][y-1] = tab[x][y];
		tab[x][y] = Empty;
	}

}

void Move::MoveRight(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
		tab[x+1][y+1] = tab[x][y];
		tab[x][y] = Empty;
	}else if(tab[x][y] == Black){
		tab[x-1][y-1] = tab[x][y];
		tab[x][y] = Empty;
	}

}

void Move::BeatLeft(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
		tab[x-2][y+2] = tab[x][y];
		tab[x-1][y+1] = Empty;
		tab[x][y] = Empty;
	}else if(tab[x][y] == Black){
		tab[x+2][y-2] = tab[x][y];
		tab[x+1][y-1] = Empty;
		tab[x][y] = Empty;
	}
}

void Move::BeatRight(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
		tab[x+2][y+2] = tab[x][y];
		tab[x+1][y+1] = Empty;
		tab[x][y] = Empty;
	}else if(tab[x][y] == Black){
		tab[x-2][y-2] = tab[x][y];
		tab[x-1][y-1] = Empty;
		tab[x][y] = Empty;
	}
}

void Move::ReturnMoveLeft(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
		tab[x+1][y-1] = tab[x][y];
		tab[x][y] = Empty;
	}else if(tab[x][y] == Black){
		tab[x-1][y+1] = tab[x][y];
		tab[x][y] = Empty;
	}
}

void Move::ReturnMoveRight(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
		tab[x-1][y-1] = tab[x][y];
		tab[x][y] = Empty;
	}else if(tab[x][y] == Black){
		tab[x+1][y+1] = tab[x][y];
		tab[x][y] = Empty;
	}

}

void Move::ReturnBeatLeft(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
		tab[x+2][y-2] = tab[x][y];
		if(tab[x][y] == White)
			tab[x+1][y-1] = Black;
		else if(tab[x][y] == Black)
			tab[x+1][y-1] = White;
		tab[x][y] = Empty;
	}else if(tab[x][y] == Black){
		tab[x-2][y+2] = tab[x][y];
		if(tab[x][y] == White)
			tab[x-1][y+1] = Black;
		else if(tab[x][y] == Black)
			tab[x-1][y+1] = White;
		tab[x][y] = Empty;
	}
}

void Move::ReturnBeatRight(Pole tab[8][8], int x, int y){
	if(tab[x][y] == White){
		tab[x-2][y-2] = tab[x][y];
		if(tab[x][y] == White)
			tab[x-1][y-1] = Black;
		else if(tab[x][y] == Black)
			tab[x-1][y-1] = White;
		tab[x][y] = Empty;
	}else if(tab[x][y] == Black){
		tab[x+2][y+2] = tab[x][y];
		if(tab[x][y] == White)
			tab[x+1][y+1] = Black;
		else if(tab[x][y] == Black)
			tab[x+1][y+1] = White;
		tab[x][y] = Empty;
	}
}

