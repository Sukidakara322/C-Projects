#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Sortowanie.h"
#include "OpcjeMenu.h"
#include "TrybSymulacji.h"
using namespace std;

//TrybSymulacji - klasa do uzycia menu do trybu symulacyjnego programu
//Implementacja menu dla pracy z generowanymi danymi
void TrybSymulacji::uruchomSymulacje(int *&tabela, float *&tabela_float, int &liczba_elementow, int &liczba_elementow_float) {
		poczatek:
		int wybor;
		while (true) {
			//Wyswietlenie menu
			OpcjeMenu::wyswietlMenuGlowne();
			cin >> wybor;
			switch (wybor) {
			case 1:
				//Wczytanie tabeli typu integer z pliku
				OpcjeMenu::wczytajTabeleZPliku(tabela, liczba_elementow);
				break;
			case 2:
				//Generowanie calkowicie losowej tabeli typu integer
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow;
				OpcjeMenu::generujTabeleLosowo(tabela, liczba_elementow);
				break;
			case 3:
				//Generowanie tabeli typu integer posortowanej rosnaco
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow;
				OpcjeMenu::generujTabeleRosnaco(tabela, liczba_elementow);
				break;
			case 4:
				//Generowanie tabeli typu integer posortowanej malejaco
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow;
				OpcjeMenu::generujTabeleMalejaco(tabela, liczba_elementow);
				break;
			case 5:
				//Generowanie tabeli typu integer posortowanej na 33%
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow;
				OpcjeMenu::generujTabele33Posortowana(tabela, liczba_elementow);
				break;
			case 6:
				//Generowanie tabeli typu integer posortowanej na 66%
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow;
				OpcjeMenu::generujTabele66Posortowana(tabela, liczba_elementow);
				break;
			case 7:
				//Wyswietlenie ostatnio uzywanej tabeli typu integer
				OpcjeMenu::wyswietlOstatnioUzywanaTabele(tabela, liczba_elementow);
				break;
			case 8:
				//Wczytanie tabeli typu float z pliku
				OpcjeMenu::wczytajTabeleZPlikuFloat(tabela_float, liczba_elementow_float);
				break;
			case 9:
				//Generowanie calkowicie losowej tabeli typu float
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow_float;
				OpcjeMenu::generujTabeleLosowoFloat(tabela_float, liczba_elementow_float);
				break;
			case 10:
				//Generowanie tabeli tpyu float posortowanej rosnaco
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow_float;
				OpcjeMenu::generujTabeleRosnacoFloat(tabela_float, liczba_elementow_float);
				break;
			case 11:
				//Generowanie tabeli typu float posortowanej malejaco
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow_float;
				OpcjeMenu::generujTabeleMalejacoFloat(tabela_float, liczba_elementow_float);
				break;
			case 12:
				//Generowanie tabeli typu float posortowanej na 33%
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow_float;
				OpcjeMenu::generujTabele33PosortowanaFloat(tabela_float, liczba_elementow_float);
				break;
			case 13:
				//Generowanie tabeli typu float posortowanej na 66%
				cout << "Podaj rozmiar tabeli: " << endl;
				cin >> liczba_elementow_float;
				OpcjeMenu::generujTabele66PosortowanaFloat(tabela_float, liczba_elementow_float);
				break;
			case 14:
				//Wyswietlenie ostatnio uzywanej tabeli typu float
				OpcjeMenu::wyswietlOstatnioUzywanaTabeleFloat(tabela_float, liczba_elementow_float);
				break;
			case 15:
				//Kontynuacja ze stara tabela typu integer
				if (liczba_elementow == 0) {
					cerr << "Tabela jest pusta. Najperw wczytaj tabele." << endl;
					goto poczatek;
				}
				else {
					break;
				}
			case 16:
				//Kontynuacja ze stara tabela typu float
				if (liczba_elementow_float == 0) {
					cerr << "Tabela float jest pusta. Najperw wczytaj tabele." << endl;
					goto poczatek;
				}
				else {
					break;
				}
			case 0:
				//Zwolnienie pamieci
				delete[] tabela;
				delete[] tabela_float;
				return;
			default:
				cerr << "Nieprawidlowy wybor. Sprobuj ponownie" << endl;
				break;
			}
			//Uzycie sortowania dla odpowiednich przypadkow dla tabeli typu integer
			if (wybor == 1 || wybor == 2 || wybor == 3 || wybor == 4 || wybor == 5 || wybor == 6 || wybor == 15) {
				bool kontynuj = OpcjeMenu::sortujTabele(tabela, liczba_elementow);
				if (!kontynuj) {
					break;
				}
			}
			//Uzycie sortowania dla odpowiednich przypadkow dla tabeli typu float
			if (wybor == 8 || wybor == 9 || wybor == 10 || wybor == 11 || wybor == 12 || wybor == 13 || wybor == 16) {
				bool kontynuj = OpcjeMenu::sortujTabeleFloat(tabela_float, liczba_elementow_float);
				if (!kontynuj) {
					break;
				}
			}
		}
		delete[] tabela;
		delete[] tabela_float;
}
