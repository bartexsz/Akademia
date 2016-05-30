/*
 * Gra.cpp
 *
 *  Created on: May 28, 2016
 *      Author: damian
 */


#include "Gra.hh"

void Gra::Initiation()
{
	int tmp;
	for(int j = 0; j < 3; j++)
	{
		for(int i = j%2; i < 8; i+=2){
			tab[i][j] = White;
			cout<<"Bialy pionek dla:"<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 0; j < 3; j++)
	{
		if((j%2)==0) tmp=1;
		else tmp=0;
		for(int i =tmp; i < 8; i+=2)
		{
			tab[i][j] = Empty;
			cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 3; j < 5; j++){
		for(int i =0; i < 8; i++){
			tab[i][j] = Empty;
			cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 5; j < 8; j++){
		for(int i = j%2; i < 8; i+=2){
			tab[i][j] = Black;
			cout<<"Czarny pionek dla:"<<"x="<<i<<" y="<<j<<endl;
		}
	}
	for(int j = 5; j < 8; j++){
				if((j%2)==0) tmp=1;
				else tmp=0;
			for(int i =tmp; i < 8; i+=2){

				tab[i][j] = Empty;
				cout<<"Brak pionka dla "<<"x="<<i<<" y="<<j<<endl;
			}
		}
	pionki_biale=12;
	pionki_czarne=12;
}



void Gra::Player_vs_Player()
{
	int x,y, wybor;
	bool good;
	Pole gracz=White;
	Move ruch;
	Initiation();

	list<Possibility> possibilities;
	for(int i=0; i>-1; i++)
	{
		good=true;
		Wyswietl();
		if(gracz==White) cout<<"Gracz nr1\n";
		else if (gracz==Black) cout<<"Gracz nr2\n";
		cout<<"Wybierz pionek\n Podaj wspolrzedna x";
		cin>>x;
		cout<<" Podaj wspolrzedna y";
		cin>>y;
		while(((tab[x][y]==White)&&(gracz==Black))||((tab[x][y]==Black)&&(gracz==White)))
		{
			cout<<"Nie mozesz wybrac figury przeciwnika!\n";
			cout<<"Wybierz pionek\n Podaj wspolrzedna x";
			cin>>x;
			cout<<" Podaj wspolrzedna y";
			cin>>y;

		}
		possibilities.clear();
		if((ruch.CheckLeft(tab, x, y)==Nothing)&&(ruch.CheckRight(tab, x, y)==Nothing))
			{
				possibilities.push_back(Nothing);
				//cout<<"Nie mozna wykonac ruchu!\n";
			}
		else
		{
			if(ruch.CheckRight(tab, x, y)==BeatR)
				{
					possibilities.push_back(BeatR);
					//cout<<"Mozesz bic w prawo\n";
				}
			if(ruch.CheckLeft(tab, x, y)==BeatL)
				{
					possibilities.push_back(BeatL);
					//cout<<"Mozesz bic w lewo\n";
				}
			if(ruch.CheckLeft(tab, x, y)==MoveL)
				{

					possibilities.push_back(MoveL);
					//cout<<"Mozesz przesunac sie w lewo";
				}
			if(ruch.CheckRight(tab, x, y)==MoveR)
				{
					possibilities.push_back(MoveR);
					//cout<<"Mozesz przesunac sie w prawo";
				}
		}


		cout<<"n\n\n Co chcesz zrobic?\n";
		cout<<"Aby wybrac inna figure wybierz 0\n";
		for( list<Possibility>::iterator iter=possibilities.begin(); iter != possibilities.end(); iter++ )
		{
			switch (*iter)
			{
			case MoveL:
				cout<<"Aby przesunac sie w lewo wybierz - 1\n";
				break;
			case BeatL:
				cout<<"Aby bic w lewo wybierz - 2\n";
				break;
			case MoveR:
				cout<<"Aby przesunac sie w prawo wybierz - 3\n";
				break;
			case BeatR:
				cout<<"Aby bic w prawo wybierz - 4\n";
				break;
			default:
				cout<<"Brak mozliwych posunięć\n";
				break;

			}
		}
		cout<<"Podaj swoj wybor: ";
		cin>>wybor;
		switch(wybor)
		{
			case 0:
				good=false;
				break;
			case 1:
				ruch.MoveLeft(tab, x, y);
				break;
			case 2:
				ruch.BeatLeft(tab, x, y);
				if(gracz==White) pionki_czarne--;
				break;
			case 3:
				ruch.MoveRight(tab, x, y);
				break;
			case 4:
				ruch.BeatRight(tab, x, y);
				if(gracz==Black) pionki_czarne--;
				break;
			default:
				cout<<"Zly wybor! \n";
				break;
		}
		if(good==true)
		{

		if (gracz==White) gracz=Black;
		else gracz=White;
		}
	}
}


void Gra::Wyswietl()
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
	for(int j=7; j>=0; j--)
	{
		for(int i=0; i<8; i++)
		{
			if(i==0)
			{
				cout<<j<<"  |";

			}
			if((((j%2)==0)&&((i%2)==1))||(((j%2)==1)&&((i%2)==0))) cout<<"_|";
			else
			{
			if(tab[i][j]==Empty)  cout<<" |";
			else
			{
				if(tab[i][j]==Black) cout<<"c|";
				if(tab[i][j]==White) cout<<"b|";
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


