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
			tmp=0;
			if(tab[i][j] == Black ){
				if(j >= 0 && j < 2)
					tmp += 4;
				else if(j > 1 && j < 4)
					tmp += 3;
				else if(j > 3 && j < 6)
					tmp += 2;
				else if(j > 5 && j < 8)
					tmp += 1;

				if(j  < 1 || j > 6 || i < 1 || i > 6)
					tmp += 6;
				else if(j  < 2 || j > 5 || i < 2 || i > 5)
					tmp += 4;
				else
					tmp += 2;
			}else if(tab[i][j] == White){
				if(j >= 0 && j < 2)
					tmp -= 1;
				else if(j > 1 && j < 4)
					tmp -= 2;
				else if(j > 3 && j < 6)
					tmp -= 3;
				else if(j > 5 && j < 8)
					tmp -= 4;

				if(j  < 1 || j > 6 || i < 1 || i > 6)
					tmp -= 6;
				else if(j  < 2 || j > 5 || i < 2 || i > 5)
					tmp -= 4;
				else
					tmp -= 2;
			}
			wartosc += tmp;
		}
	}
	return wartosc;
}




int MinMax::MinMaxRecursion(int depth, Pole player){
	Pole next_player;
	int v;
	int next_depth = depth-1;
	int best_value_min;
	int best_value_max;
	if(licznik>190)
		//return 0;
	licznik++;
	cout<<"***** START MINMAXRECURSION *****"<<endl;
	Wyswietl(White);
	cout<<"x: "<<x<<",y: "<<y<<endl;
	for(list<Possibility>::iterator it = move.begin(); it != move.end(); it++){
		cout<<"Move: "<<*it<<endl;
	}
	for(list<Possibility>::iterator it = tmp_move.begin(); it != tmp_move.end(); it++){
		cout<<"TmpMove: "<<*it<<endl;
	}
	cout<<"depth="<<depth<<endl;
	cout<<"Value: "<<Value()<<endl;
	//cout<<"best_value: "<<best_value<<endl;
	LiczPionki();
	if(pionki_biale < 12 - main_depth/2 || pionki_czarne < 12 - main_depth/2){
		cout<<"ZA malo pionkow!!!!"<<endl;
		return 0;
	}

	if(depth == 0)
		return Value();


	if(player == Black){
		next_player = White;
		cout<<"player == Black"<<endl;
		best_value_max = -INT_MAX;
		list<Possibility> P;
		for(int j = 0; j < 8; j++){
			for(int i = j%2; i < 8; i+=2){
				if(tab[i][j] == player){
					cout<<"i="<<i<<", j="<<j<<endl;
					M.Check(P,tab,i,j);
						if(P.front() != Nothing){
							for(list<Possibility>::iterator it = P.begin(); it != P.end(); it++){
								cout<<"best_value_max: "<<best_value_max<<endl;
								if(depth == main_depth){
									tmp_move.clear();
									tmp_x = i;
									tmp_y = j;
								}
								if(*it == BeatL || *it == BeatR)
									MultipleMove(depth,player,i,j,best_value_max);
								else{
									cout<<"Ruch"<<endl;
									if(depth == main_depth)
										tmp_move.push_back(*it);
									M.Action(*it,tab,i,j);
								}

								v = MinMaxRecursion(next_depth,next_player);
								cout<<"after recursion, depth="<<depth<<endl;
								if(v>best_value_max){
									cout<<"!!!!!!!Nowa wartosc - max: "<<v<<endl;
									best_value_max = v;
									if(depth==main_depth)
										CopyMove();
								}
								if(*it != BeatL && *it != BeatR)
									M.ReturnAction(*it, tab, i, j,player);
							}
					}
				}
			}
		}
		return best_value_max;
	}else if(player == White){
		next_player = Black;
		cout<<"player == White"<<endl;
		best_value_min = INT_MAX;
		list<Possibility> P;
		for(int j = 0; j < 8; j++){
			for(int i = j%2; i < 8; i+=2){
				if(tab[i][j] == player){
					cout<<"i="<<i<<", j="<<j<<endl;
					M.Check(P,tab,i,j);
					if(P.front() != Nothing){
						for(list<Possibility>::iterator it = P.begin(); it != P.end(); it++){
							cout<<"best_value_min: "<<best_value_min<<endl;
							if(depth == main_depth){
								tmp_move.clear();
								tmp_x = i;
								tmp_y = j;
							}
							if(*it == BeatL || *it == BeatR)
								MultipleMove(depth,player,i,j,best_value_min);
							else{
								cout<<"Ruch"<<endl;
								if(depth == main_depth)
									tmp_move.push_back(*it);
								M.Action(*it,tab,i,j);
							}

							v = MinMaxRecursion(next_depth,next_player);
							cout<<"after recursion, depth="<<depth<<endl;
							if(v<best_value_min){
								cout<<"!!!!!!!Nowa wartosc - min: "<<v<<endl;
								best_value_min = v;
								if(depth==main_depth)
									CopyMove();
							}
							if(*it != BeatL && *it != BeatR)
								M.ReturnAction(*it, tab, i, j,player);
						}
					}
				}
			}
		}
		return best_value_min;
	}
	cout<<"ENDRecursionfunction\n"<<endl;
}


int MinMax::Algorithm(Pole main_tab[8][8],int depth, list<Possibility> &Lista, int &xx, int &yy){
	pionki_biale=pionki_czarne=12;
	CopyTab(main_tab);
	main_depth = depth;
	int value = MinMaxRecursion(depth,Black);
	for(list<Possibility>::iterator it = move.begin(); it != move.end(); it++)
		Lista.push_back(*it);
	xx=x;
	yy=y;
	return value;
}

void MinMax::CopyMove(){
	move.clear();
	for(list<Possibility>::iterator it = tmp_move.begin(); it != tmp_move.end(); it++)
		move.push_back(*it);
	x = tmp_x;
	y = tmp_y;

}

void MinMax::MultipleMove(int depth, Pole player,int x, int y, int &best_value){
	Pole next_player;
	int v;
	if(player == Black) next_player = White;
	else if(player == White) next_player = Black;
	list<Possibility> lista;
	M.Check(lista,tab,x,y);
	if(lista.front() == Nothing || (lista.front() != BeatR && lista.back() != BeatR
			&& lista.front() != BeatL && lista.back() != BeatL)){
		cout<<"###########################################################"<<endl;
		v = MinMaxRecursion(depth-1, next_player);
		if(player == Black){
			if(v>best_value){
				cout<<"!!!!!!!Nowa wartosc: "<<v<<endl;
				best_value = v;
				if(depth==main_depth)
					CopyMove();
			}
		}else if(player == White){
			if(v<best_value){
				cout<<"!!!!!!!Nowa wartosc: "<<v<<endl;
				best_value = v;
				if(depth==main_depth)
					CopyMove();
			}
		}
	}else{
		for(list<Possibility>::iterator it = lista.begin(); it != lista.end(); it++){
			if(*it != MoveL && *it != MoveR){
				cout<<"Bicie"<<endl;
				if(depth == main_depth)
					tmp_move.push_back(*it);
				M.Action(*it,tab,x,y);
				if(*it == BeatL){
					if(player == White)
						MultipleMove(depth,player,x-2,y+2,best_value);
					else if(player == Black)
						MultipleMove(depth,player,x+2,y-2,best_value);
				}else if(*it == BeatR){
					if(player == White)
						MultipleMove(depth,player,x+2,y+2,best_value);
					else if(player == Black)
						MultipleMove(depth,player,x-2,y-2,best_value);
				}
				M.ReturnAction(*it,tab,x,y,player);
			}
		}
	}
}

void MinMax::Wyswietl(Pole gracz)
{
/*
	cout<<"jou\n";
	for(int j=0; j<8; j++)
	{
		for(int i=0;i<8;i++)
		{
			cout<<"dla x:"<<i<<" i y:"<<j<<"->";
			if (tab[i][j]==Empty) cout<<"0"<<endl;
			else
				{
					if(tab[i][j]==Black) cout<<"czarny\n";
					else cout<<"bialy\n";
				}
		}
	}

*/
	if(gracz==White)
	{
	for(int j=7; j>=0; j--)
	{
		for(int i=0; i<8; i++)
		{
			if(i==0)
			{
				cout<<j<<"  |";

			}
			if((((j%2)==0)&&((i%2)==1))||(((j%2)==1)&&((i%2)==0))) cout<<"x|";
			else
			{
			if(tab[i][j]==Empty)  cout<<" |";
			else
			{
				if(tab[i][j]==Black) cout<<"♟|";
				if(tab[i][j]==White) cout<<"♙|";
			}
			}

		}
		cout<<endl;
	}
	cout<<"    ";
	for (int i=0; i<8; i++)
	{
		cout<<i<<" ";
	}

	cout<<"\nPozostalo "<<pionki_biale<<" pionkow bialych oraz "<<pionki_czarne<<" pionkow czarnych\n";
	}



	else if(gracz==Black)
	{
		for(int j=0; j<8; j++)
		{
			for(int i=7; i>=0; i--)
			{
				if(i==7)
				{
					cout<<j<<"  |";

				}
				if((((j%2)==0)&&((i%2)==1))||(((j%2)==1)&&((i%2)==0))) cout<<"x|";
				else
				{
				if(tab[i][j]==Empty)  cout<<" |";
				else
				{
					if(tab[i][j]==Black) cout<<"♟|";
					if(tab[i][j]==White) cout<<"♙|";
				}
				}

			}
			cout<<endl;
	}
	cout<<"    ";
	for (int i=7; i>=0; i--)
	{
		cout<<i<<" ";
	}

	cout<<"\nPozostalo "<<pionki_biale<<" pionkow bialych oraz "<<pionki_czarne<<" pionkow czarnych\n";
	}


}

int MinMax::LiczPionki(){
	pionki_biale = pionki_czarne =0;
	for(int j = 0; j < 8; j++){
		for(int i = j%2; i < 8; i+=2){
			if(tab[i][j] == Black)
				pionki_czarne++;
			else if(tab[i][j] == White)
				pionki_biale++;
		}
	}
}
