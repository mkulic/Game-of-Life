#include "game_of_life.h"


bool game_of_life::slucajna_vrijednost()
{
	return rand() % 100<25;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	bool value = false;
	if ((i >= 0 && i < REDAKA) && (j >= 0 && j < STUPACA))
		 value = _generacija[i][j];
		return value;
	return value;
	
}

game_of_life::game_of_life()
{
}

void game_of_life::sljedeca_generacija()
{
	
	for (int i = 0; i < REDAKA; i++)
	{ 
		
		for (int j = 0; j < STUPACA; j++)	
		
		{
			int zcelija = 0;
			
			if (celija_zauzeta(i - 1,j - 1)) {
				zcelija++;
			}
			
			if (celija_zauzeta(i -1, j)) {
				zcelija++;
			}
			
			if (celija_zauzeta(i - 1, j +1) ) {
				zcelija++;
			}
			
			if (celija_zauzeta(i , j - 1) ) {
				zcelija++;
			}
			
			if (celija_zauzeta(i , j +1)) {
				zcelija++;
			}
			
			
			if (celija_zauzeta(i + 1, j - 1)) {
				zcelija++;
			}
			
			if (celija_zauzeta(i + 1, j ) ) {
				zcelija++;
			}
			
			if (celija_zauzeta(i + 1, j + 1) ) {
				zcelija++;
			}
			//pravila

			if (zcelija==2){
				_sljedeca_generacija[i][j] = _generacija[i][j];;
			
			}


			else if (zcelija==3)
			 {
				_sljedeca_generacija[i][j] = true;
			}
			else
			{
				_sljedeca_generacija[i][j] = false;
			}
		}
	}

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
	

}

void game_of_life::nova_ploca()
		{
			for (int i = 0; i < REDAKA; i++)
			{
				for (int j = 0; j < STUPACA; j++)
				{
					_generacija[i][ j] = slucajna_vrijednost();
					_sljedeca_generacija[i][j] = false;
				}
			}
		}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j]) {
				cout << "*";
			}

			else
			{
				cout << "-";
			}

		}
		cout << endl;

	}
}
