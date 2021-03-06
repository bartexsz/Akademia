/*
 * Move.cpp
 *
 *  Created on: May 29, 2016
 *      Author: damian
 */

#include "Move.hh"

void MoveSequence::push(Possibility P) {
	Sequence.push_back(P);
}

Possibility MoveSequence::pop() {
	Possibility P = Sequence.back();
	Sequence.pop_back();
	return P;
}

void Move::Check(list<Possibility> &possibilities, Pole tab[8][8], int x, int y){
	possibilities.clear();
	if ((CheckLeft(tab, x, y) == Nothing) && (CheckRight(tab, x, y) == Nothing))
	{
		possibilities.push_back(Nothing);
		cout<<"..Nie mozna wykonac ruchu!\n";
	}
	else
	{
		if (CheckRight(tab, x, y) == BeatR)
		{
			possibilities.push_back(BeatR);
			cout<<"..Mozesz bic w prawo\n";
		}

		else if (CheckRight(tab, x, y) == MoveR)
		{
			possibilities.push_back(MoveR);
			cout<<"..Mozesz przesunac sie w prawo\n";
		}

		if (CheckLeft(tab, x, y) == BeatL) {
			possibilities.push_back(BeatL);
			cout<<"Mozesz bic w lewo\n";
		}

		else if (CheckLeft(tab, x, y) == MoveL)
		{

			possibilities.push_back(MoveL);
			cout<<"Mozesz przesunac sie w lewo\n";
		}

	}
}

Possibility Move::CheckLeft(Pole tab[8][8], int x, int y) {
	if (tab[x][y] == White) {
		if (x == 1 || y == 6) {
			if (tab[x - 1][y + 1] == Empty)
				return MoveL;
			else
				return Nothing;
		} else if (x > 1 && y < 6) {
			if (tab[x - 1][y + 1] == Empty)
				return MoveL;
			else {
				if (tab[x - 1][y + 1] == White)
					return Nothing;
				else if (tab[x - 1][y + 1] == Black) {
					if (tab[x - 2][y + 2] == Empty)
						return BeatL;
					else
						return Nothing;
				}
			}
		}
	} else if (tab[x][y] == Black) {
		if (x == 6 || y == 1) {
			if (tab[x + 1][y - 1] == Empty)
				return MoveL;
			else
				return Nothing;
		} else if (x < 6 && y > 1) {
			if (tab[x + 1][y - 1] == Empty)
				return MoveL;
			else {
				if (tab[x + 1][y - 1] == Black)
					return Nothing;
				else if (tab[x + 1][y - 1] == White) {
					if (tab[x + 2][y - 2] == Empty)
						return BeatL;
					else
						return Nothing;
				}
			}
		}
	}
	return Nothing;
}

Possibility Move::CheckRight(Pole tab[8][8], int x, int y) {
	if (tab[x][y] == White) {
		if (x == 6 || y == 6) {
			if (tab[x + 1][y + 1] == Empty)
				return MoveR;
			else
				return Nothing;
		} else if (x < 6 && y < 6) {
			if (tab[x + 1][y + 1] == Empty)
				return MoveR;
			else {
				if (tab[x + 1][y + 1] == White)
					return Nothing;
				else if (tab[x + 1][y + 1] == Black) {
					if (tab[x + 2][y + 2] == Empty)
						return BeatR;
					else
						return Nothing;
				}
			}
		}
	} else if (tab[x][y] == Black) {
		if (x == 1 || y == 1) {
			if (tab[x - 1][y - 1] == Empty)
				return MoveR;
			else
				return Nothing;
		} else if (x > 1 && y > 1) {
			if (tab[x - 1][y - 1] == Empty)
				return MoveR;
			else {
				if (tab[x - 1][y - 1] == Black)
					return Nothing;
				else if (tab[x - 1][y - 1] == White) {
					if (tab[x - 2][y - 2] == Empty)
						return BeatR;
					else
						return Nothing;
				}
			}
		}
	}
	return Nothing;
}

void Move::MoveLeft(Pole tab[8][8], int x, int y) {
	if (tab[x][y] == White) {
		tab[x - 1][y + 1] = tab[x][y];
		tab[x][y] = Empty;
	} else if (tab[x][y] == Black) {
		tab[x + 1][y - 1] = tab[x][y];
		tab[x][y] = Empty;
	}

}

void Move::MoveRight(Pole tab[8][8], int x, int y) {
	if (tab[x][y] == White) {
		tab[x + 1][y + 1] = tab[x][y];
		tab[x][y] = Empty;
	} else if (tab[x][y] == Black) {
		tab[x - 1][y - 1] = tab[x][y];
		tab[x][y] = Empty;
	}

}

void Move::BeatLeft(Pole tab[8][8], int x, int y) {
	if (tab[x][y] == White) {
		tab[x - 2][y + 2] = tab[x][y];
		tab[x - 1][y + 1] = Empty;
		tab[x][y] = Empty;

	} else if (tab[x][y] == Black) {
		tab[x + 2][y - 2] = tab[x][y];
		tab[x + 1][y - 1] = Empty;
		tab[x][y] = Empty;
	}
}

void Move::BeatRight(Pole tab[8][8], int x, int y) {
	if (tab[x][y] == White) {
		tab[x + 2][y + 2] = tab[x][y];
		tab[x + 1][y + 1] = Empty;
		tab[x][y] = Empty;
	} else if (tab[x][y] == Black) {
		tab[x - 2][y - 2] = tab[x][y];
		tab[x - 1][y - 1] = Empty;
		tab[x][y] = Empty;
	}
}

void Move::ReturnMoveLeft(Pole tab[8][8], int x, int y, Pole player) {
	/*if (tab[x][y] == White) {
		tab[x + 1][y - 1] = tab[x][y];
		tab[x][y] = Empty;
	} else if (tab[x][y] == Black) {
		tab[x - 1][y + 1] = tab[x][y];
		tab[x][y] = Empty;
	}*/
	if (player == White) {
		tab[x - 1][y + 1] = Empty;
		tab[x][y] = White;
	} else if (player == Black) {
		tab[x + 1][y - 1] = Empty;
		tab[x][y] = Black;
	}
}

void Move::ReturnMoveRight(Pole tab[8][8], int x, int y, Pole player) {
	/*if (tab[x][y] == White) {
		tab[x - 1][y - 1] = tab[x][y];
		tab[x][y] = Empty;
	} else if (tab[x][y] == Black) {
		tab[x + 1][y + 1] = tab[x][y];
		tab[x][y] = Empty;
	}*/
	if (player == White) {
		tab[x + 1][y + 1] = Empty;
		tab[x][y] = White;
	} else if (player == Black) {
		tab[x - 1][y - 1] = Empty;
		tab[x][y] = Black;
	}

}

void Move::ReturnBeatLeft(Pole tab[8][8], int x, int y, Pole player) {
	/*if (tab[x][y] == White) {
		tab[x + 2][y - 2] = tab[x][y];
		if (tab[x][y] == White)
			tab[x + 1][y - 1] = Black;
		else if (tab[x][y] == Black)
			tab[x + 1][y - 1] = White;
		tab[x][y] = Empty;
	} else if (tab[x][y] == Black) {
		tab[x - 2][y + 2] = tab[x][y];
		if (tab[x][y] == White)
			tab[x - 1][y + 1] = Black;
		else if (tab[x][y] == Black)
			tab[x - 1][y + 1] = White;
		tab[x][y] = Empty;
	}*/
	if (player == White) {
		tab[x - 2][y + 2] = Empty;
		tab[x - 1][y + 1] = Black;
		tab[x][y] = White;

	} else if (player == Black) {
		tab[x + 2][y - 2] = Empty;
		tab[x + 1][y - 1] = White;
		tab[x][y] = Black;
	}
}

void Move::ReturnBeatRight(Pole tab[8][8], int x, int y, Pole player) {
	/*if (tab[x][y] == White) {
		tab[x - 2][y - 2] = tab[x][y];
		if (tab[x][y] == White)
			tab[x - 1][y - 1] = Black;
		else if (tab[x][y] == Black)
			tab[x - 1][y - 1] = White;
		tab[x][y] = Empty;
	} else if (tab[x][y] == Black) {
		tab[x + 2][y + 2] = tab[x][y];
		if (tab[x][y] == White)
			tab[x + 1][y + 1] = Black;
		else if (tab[x][y] == Black)
			tab[x + 1][y + 1] = White;
		tab[x][y] = Empty;
	}*/
	if (player == White) {
		tab[x + 2][y + 2] = Empty;
		tab[x + 1][y + 1] = Black;
		tab[x][y] = White;
	} else if (player == Black) {
		tab[x - 2][y - 2] = Empty;
		tab[x - 1][y - 1] = White;
		tab[x][y] = Black;
	}
}

bool Move::Action(Possibility wybor, Pole tab[8][8], int x, int y) {
	switch (wybor) {
	case Nothing:
		return false;
		break;
	case MoveL:
		MoveLeft(tab, x, y);
		cout<<"MoveLeft"<<endl;
		return true;
		break;
	case BeatL:
		BeatLeft(tab, x, y);
		cout<<"BeatLeft"<<endl;
		return false;
		break;
	case MoveR:
		MoveRight(tab, x, y);
		cout<<"MoveRight"<<endl;
		return true;
		break;
	case BeatR:
		BeatRight(tab, x, y);
		cout<<"BeatRight"<<endl;
		return false;
		break;
	default:
		cout << "Zly wybor! \n";
		return false;
		break;
	}
}

bool Move::ReturnAction(Possibility wybor, Pole tab[8][8], int x, int y, Pole player){
	switch (wybor) {
	case Nothing:
		return false;
		break;
	case MoveL:
		ReturnMoveLeft(tab, x, y,player);
		cout<<"ReturnMoveLeft"<<"x:"<<x<<",y: "<<y<<endl;
		return true;
		break;
	case BeatL:
		ReturnBeatLeft(tab, x, y,player);
		cout<<"ReturnBeatLeft"<<"x:"<<x<<",y: "<<y<<endl;
		return false;
		break;
	case MoveR:
		ReturnMoveRight(tab, x, y,player);
		cout<<"ReturnMoveRight"<<"x:"<<x<<",y: "<<y<<endl;
		return true;
		break;
	case BeatR:
		ReturnBeatRight(tab, x, y,player);
		cout<<"ReturnBeatRight"<<"x:"<<x<<",y: "<<y<<endl;
		return false;
		break;
	default:
		cout << "Zly wybor! \n";
		return false;
		break;
	}
}

