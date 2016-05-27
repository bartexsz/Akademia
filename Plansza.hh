/*
 * Plansza.hh
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#ifndef PLANSZA_HH_
#define PLANSZA_HH_

enum color{
	white = 0,
	black = 1
};

class Pionek{
private:
	int _x;
	int _y;
	color _c;
public:
	Pionek(color c, int x, int y){
		_c = c;
		_x = x;
		_y = y;
	}
	void SetColor(color c);
	color GetColor();
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
};




#endif /* PLANSZA_HH_ */
