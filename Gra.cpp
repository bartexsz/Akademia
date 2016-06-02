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

void Gra::Wybor(int &x, int &y, Pole gracz)
{
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
}
void Gra::Odejmij_pionka(Pole pionek)
{
	if(pionek==White) pionki_biale--;
	else if(pionek==Black) pionki_czarne--;
}

void Gra::Player_vs_Player()
{
	int x,y, co;
	bool good, bylobicie=false, bicie=false;
	Pole gracz=White;
	Move ruch;
	Initiation();
	Possibility wybor;
	list<Possibility> possibilities, cobylo;
	while(CzyKoniec()==false)
	{
		good=true;
		Wyswietl(gracz);
		if(gracz==White) cout<<"Gracz nr1\n";
		else if (gracz==Black) cout<<"Gracz nr2\n";
		if(bylobicie==true)
		{
			cout<<"\nniby bylo bicie\n";
			ruch.Check(possibilities, tab, x, y);
			cout<<"\nwspolrzedne tera to:"<<x<<" oraz "<<y<<endl;
			for( list<Possibility>::iterator iter=possibilities.begin(); iter != possibilities.end(); iter++ )
			{
				cout<<"\n\nwszedlwfora\n\n";
				switch(*iter)
				{
					case BeatL:
						cout<<"Aby bic w lewo wybierz - 2\n";
						cobylo.push_back(BeatL);
						break;
					case BeatR:
						cout << "Aby bic w prawo wybierz - 4\n";
						cobylo.push_back(BeatR);
						break;
					default:
						cout<<"nic nie wybral";
						break;
				}
				bicie=false;
				for( list<Possibility>::iterator iter=cobylo.begin(); iter != cobylo.end(); iter++ )
					{
						if((*iter==BeatR)||(*iter==BeatL)) bicie=true;
						cout<<"\nSZYBKA OBCZAJKA\n";
					}
				if(bicie!=true) bicie=false;
				bylobicie=true;

			}

		}
		else if(bylobicie==false)
		{
			Wybor(x, y, gracz);
			ruch.Check(possibilities, tab, x, y);
			cout<<"n\n\n Co chcesz zrobic?\n";
			cout<<"Aby wybrac inna figure wybierz 0\n";
			for( list<Possibility>::iterator iter=possibilities.begin(); iter != possibilities.end(); iter++ )
			{
				cout<<"\n\n>>>>"<<*iter<<"\n\n\n";
				switch (*iter)
				{
					case MoveL:
						cout<<"Aby przesunac sie w lewo wybierz - 1\n";
						cobylo.push_back(MoveL);
						break;
					case BeatL:
						cout<<"Aby bic w lewo wybierz - 2\n";
						cobylo.push_back(BeatL);
						bicie=true;
						break;
					case MoveR:
						cout<<"Aby przesunac sie w prawo wybierz - 3\n";
						cobylo.push_back(MoveR);
						break;
					case BeatR:
						cout<<"Aby bic w prawo wybierz - 4\n";
						cobylo.push_back(BeatR);
						bicie=true;
						break;
					default:
						cout<<"Brak mozliwych posunięć\n";
						break;

				}
			}
		}
		cout<<"przedwatunkiem\n\n";
		if((bylobicie==false)||(bicie==true))
		{
			cout<<"\n\nwwarunku\n\n";

			do
			{
				cout<<"Podaj swoj wybor: ";
				cin>>co;
				wybor=CoKcesz(co);
			}while((CzyMozna(cobylo, wybor)==false)&&(co!=0));





			cout<<"Wyszedlwszy\n\n";
			if(ruch.Action(wybor, tab, x, y)==false)
			{
				if((wybor==BeatL)||(wybor==BeatR))
					{
					cout<"\n\ntujestem!!\n\n";
					bylobicie=true;
					good=false;
					}
				else if((wybor!=MoveL)&&(wybor!=MoveR)) good=false;
			}
		}
		else
			{
			cobylo.clear();
			bylobicie=false;
			good=true;
			}
		if(good==true)
		{
			cout<<"\n\nZmieniam!!\n\n";
			if (gracz==White) gracz=Black;
			else gracz=White;
			bicie=false;
			bylobicie=false;
		}

		if(gracz==Black)
						{
							if(wybor==BeatR)
							{
								cout<<"robie to gowno \n\n\n";
								x=x-2;
								y=y-2;
							}
							else if(wybor==BeatL)
							{
								x=x+2;
								y=y-2;
							}
						}
					else if(gracz==White)
					{
						if(wybor==BeatR)
						{
							x=x+2;
							y=y+2;
						}
						else if(wybor==BeatL)
						{
							x=x-2;
							y=y+2;
						}
					}
		cobylo.clear();
	}
}


void Gra::Wyswietl(Pole gracz)
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

bool Gra::CzyKoniec()
{
	Move ruch;
	bool czarny_rucha=false, bialy_rucha=false;
	if(pionki_biale==0)
	{
		cout<<"\n\n\n **** KONIEC GRY ****\n\n Wygrały czarne";
		return true;
	}
	else if(pionki_czarne==0)
		{
			cout<<"\n\n\n **** KONIEC GRY ****\n\n Wygrały białe";
			return true;
		}

	for(int j=0; j<8; j++)
	{
		for (int i=0; i<8; i++)
		{

			if(czarny_rucha==false)
			{
				if((tab[i][j]==Black)&&(ruch.CheckLeft(tab, i ,j)!=Nothing)) czarny_rucha=true;
				if((tab[i][j]==Black)&&(ruch.CheckRight(tab, i ,j)!=Nothing)) czarny_rucha=true;
			}

			if (bialy_rucha==false)
			{
				if((tab[i][j]==White)&&(ruch.CheckRight(tab, i ,j)!=Nothing)) bialy_rucha=true;
				if((tab[i][j]==White)&&(ruch.CheckLeft(tab, i ,j)!=Nothing)) bialy_rucha=true;
			}


		}
	}
	if((bialy_rucha==true)&&(czarny_rucha==true)) return false;
	else
	{
		if(bialy_rucha==false)
		{
			cout<<"\n\n\n **** KONIEC GRY ****\n\n Wygrały czarne";
			return true;
		}

		else if(czarny_rucha==false)
		{
			cout<<"\n\n\n **** KONIEC GRY ****\n\n Wygrały białe";
			return true;
		}
	}
}

void Gra::TestDamian(){
	list<Possibility> lista;
	int x, y;
	Initiation();
	Wyswietl(White);
	minmax.Algorithm(tab,2,lista,x,y);
	cout<<lista.back()<<endl;
}


void Gra::Test()
{
	Move ruch;
	MinMax computer;
	int xx, yy;
	list<Possibility> possibilities;
	Pole gracz=White;
	Initiation();
	Wyswietl(gracz);
	computer.Algorithm(tab, 4, possibilities, xx, yy);
	for( list<Possibility>::iterator iter=possibilities.begin(); iter != possibilities.end(); iter++ )
								{
		cout<<"CHUJE";
									switch (*iter)
									{

									case MoveL:
										ruch.MoveLeft(tab, xx, yy);
										cout<<"\nAA1\n";
										break;
									case BeatL:
										ruch.BeatLeft(tab, xx, yy);
										cout<<"\nAA2\n";
										break;
									case MoveR:
										ruch.MoveRight(tab,xx, yy);
										cout<<"\nAA3\n";
										break;
									case BeatR:
										ruch.BeatRight(tab, xx, yy);
										cout<<"\nAA4\n";
										break;
									default:
										cout<<"SPIERDOLONDO";

										break;

									}
								}
	Wyswietl(gracz);


}









Possibility Gra::CoKcesz(int co)
{
	switch(co)
	{
		case 0:
		return Nothing;
		break;
		case 1:
			return MoveL;
			break;
		case 2:
			return BeatL;
			break;
		case 3:
			return MoveR;
			break;
		case 4:
			return BeatR;
			break;
		default:
			cout<<"COS SIE SPIERDOLILOLOLOLOLO!!!!!!\n";
			return Nothing;
			break;
	}
}


bool Gra::CzyMozna(list<Possibility> &cobylo, Possibility wybor)
{
	for( list<Possibility>::iterator iter=cobylo.begin(); iter != cobylo.end(); iter++ )
		{
			if(*iter==wybor) return true;
		}
		cout<<"Nie mozesz dokonac takiego wyboru!\n";
		return false;
}
