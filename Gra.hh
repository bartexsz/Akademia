/*
 * Gra.hh
 *
 *  Created on: May 28, 2016
 *      Author: damian
 */

#ifndef GRA_HH_
#define GRA_HH_

#include <iostream>
#include "Move.hh"
#include <list>

using namespace std;

class Gra{
private:
	Pole tab[8][8];
public:
	void Initiation();
	void Wyswietl();
	void Player_vs_Player();
};


#endif /* GRA_HH_ */
