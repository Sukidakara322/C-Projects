#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include "Sortowanie.h"
#include "OpcjeMenu.h"
using namespace std;

//OpcjeMenu - klasa zawierajaca wszystkie metody dla wczytywania lub generowania danych oraz podsekcje menu do sortowan
//Funkcja do wczytania tabele typu integer z pliku tekstowego
void OpcjeMenu::wczytajTabeleZPliku(int*& tabela, int& liczba_elementow) {
	cout << "Wpisz nazwe pliku do wczytania danych: " << endl;
	string tabela_plik;
	cin >> tabela_plik;
	ifstream plik(tabela_plik);
	//Walidacja na poprawnosc podanej sciezki
	if (!plik) {
		cerr << "Nie mozna otworyc pliku" << endl;
		return;
	}
	//Zwolnienie pamieci
	delete[] tabela;
	plik >> liczba_elementow;
	tabela = new int[liczba_elementow];

	for (int i = 0; i < liczba_elementow; i++) {
		plik >> tabela[i];
	}
	plik.close();
}
//Funkcja do wczytania tabele typu float z pliku tekstowego
void OpcjeMenu::wczytajTabeleZPlikuFloat(float*& tabela, int& liczba_elementow) {
	cout << "Wpisz nazwe pliku do wczytania danych: " << endl;
	string tabela_plik;
	cin >> tabela_plik;
	ifstream plik(tabela_plik);
	//Walidacja na poprawnosc sciezki
	if (!plik) {
		cerr << "Nie mozna otworyc pliku" << endl;
		return;
	}
	//Zwolnienie pamieci
	delete[] tabela;
	plik >> liczba_elementow;
	tabela = new float[liczba_elementow];

	for (int i = 0; i < liczba_elementow; i++) {
		plik >> tabela[i];
	}
	plik.close();
}
//Funkcja do generowania calkowicie losowej tabeli typu int
void OpcjeMenu::generujTabeleLosowo(int*& tabela, int liczba_elementow) {
	//Zwolnienie pamieci
	delete[] tabela;
	tabela = new int[liczba_elementow];
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < liczba_elementow; i++) {
		tabela[i] = rand() % (liczba_elementow + 1); //Generowanie liczby losowej z zakresu 0 - liczba elementow
	}
}
//Funkcja do generowania calkowicie losowej tabeli typu float
void OpcjeMenu::generujTabeleLosowoFloat(float*& tabela, int liczba_elementow) {
	//Zwolnienie pamieci
	delete[] tabela;
	tabela = new float[liczba_elementow];
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < liczba_elementow; i++) {
		tabela[i] = static_cast<float>(rand()) / RAND_MAX * liczba_elementow;//Generowanie liczby losowej z zakresu 0 - licba_elementow typu float
	}
}
//Funkcja do generowania tabeli liczb typu integer posortowanej rosnaco z zakresu od 0 do wprowadzonej liczby elementow
void OpcjeMenu::generujTabeleRosnaco(int*& tabela, int liczba_elementow) {
	delete[] tabela;
	tabela = new int[liczba_elementow];
	for (int i = 0; i < liczba_elementow; i++) {
		tabela[i] = i;
	}
}
//Funkcja do generowania tebeli liczb typu float posortowanej rosnaco z zakresu od 0 do wprowadzonej liczby elementow
void OpcjeMenu::generujTabeleRosnacoFloat(float*& tabela, int liczba_elementow) {
	delete[] tabela;
	tabela = new float[liczba_elementow];
	for (int i = 0; i < liczba_elementow; ++i) {
		tabela[i] = static_cast<float>(i) * 1.5f; //Pomnazamy kazdy element przez 1.5 dla lepszej widocznosci typu float
	}
}
//Funkcja do generowania tabeli liczb typu integer posortowanej malejaco z zakresu od 0 do wprowadzonej liczby elementow
void OpcjeMenu::generujTabeleMalejaco(int*& tabela, int liczba_elementow) {
	delete[] tabela;
	tabela = new int[liczba_elementow];
	for (int i = 0; i < liczba_elementow; i++) {
		tabela[i] = (liczba_elementow - i - 1);
	}
}
//Funkcja do generowania tabeli liczb typu float posortowanej malejaco z zakresu od 0 do wprowadzonej liczby elementow
void OpcjeMenu::generujTabeleMalejacoFloat(float*& tabela, int liczba_elementow) {
	delete[] tabela;
	tabela = new float[liczba_elementow];
	for (int i = 0; i < liczba_elementow; i++) {
		tabela[i] = static_cast<float>(liczba_elementow - i - 1) * 1.5f; //Pomnazamy kazdy element przez 1.5 dla lepszej widocznosci typu float
	}
}
//Funkcja do generowania tabele liczb typu integer, gdzie pierwsze 33% elementow sa posortowane, a ostatnie sa losowymi
void OpcjeMenu::generujTabele33Posortowana(int*& tabela, int liczba_elementow) {
	delete[] tabela;
	tabela = new int[liczba_elementow];
	//Obliczanie indeksu do ktorego trzeba wprowadzic posortowane elementy tabeli
	int posortowana_czesc =(int) (liczba_elementow * 0.33);
	for (int i = 0; i < posortowana_czesc; ++i) {
		tabela[i] = i;
	}
	//Wprowadzanie losowych elementow do konca tabeli
	for (int i = posortowana_czesc; i < liczba_elementow; ++i) {
		tabela[i] = rand() % (liczba_elementow + 1);
	}
}
//Funkcja do generowania tabele liczb typu float, gdzie pierwsze 33% elementow sa posortowane, a ostatnie sa losowymi
void OpcjeMenu::generujTabele33PosortowanaFloat(float*& tabela, int liczba_elementow) {
	delete[] tabela;
	tabela = new float[liczba_elementow];
	//Obliczanie indeksu do ktorego trzeba wprowadzic posortowane elementy tabeli
	int posortowana_czesc = (int)(liczba_elementow * 0.33);
	for (int i = 0; i < posortowana_czesc; ++i) {
		tabela[i] = static_cast<float>(i);
	}
	//Wprowadzanie losowych elementow do konca tabeli
	for (int i = posortowana_czesc; i < liczba_elementow; ++i) {
		tabela[i] = static_cast<float>(rand()) / RAND_MAX * liczba_elementow;
	}
}
//Funkcja do generowania tabele liczb typu integer, gdzie pierwsze 66% elementow sa posortowane, a ostatnie sa losowymi
void OpcjeMenu::generujTabele66Posortowana(int*& tabela, int liczba_elementow) {
	delete[] tabela;
	tabela = new int[liczba_elementow];
	//Obliczanie indeksu do ktorego trzeba wprowadzic posortowane elementy tabeli
	int posortowana_czesc = (int)(liczba_elementow * 0.66);
	for (int i = 0; i < posortowana_czesc; ++i) {
		tabela[i] = i;
	}
	//Wprowadzanie losowych elementow do konca tabeli
	for (int i = posortowana_czesc; i < liczba_elementow; ++i) {
		tabela[i] = rand() % (liczba_elementow + 1);
	}
}
//Funkcja do generowania tabele liczb typu float, gdzie pierwsze 66% elementow sa posortowane, a ostatnie sa losowymi
void OpcjeMenu::generujTabele66PosortowanaFloat(float*& tabela, int liczba_elementow) {
	delete[] tabela;
	tabela = new float[liczba_elementow];
	//Obliczanie indeksu do ktorego trzeba wprowadzic posortowane elementy tabeli
	int posortowana_czesc = (int)(liczba_elementow * 0.66);
	for (int i = 0; i < posortowana_czesc; ++i) {
		tabela[i] = static_cast<float>(i);
	}
	//Wprowadzanie losowych elementow do konca tabeli
	for (int i = posortowana_czesc; i < liczba_elementow; ++i) {
		tabela[i] = static_cast<float>(rand()) / RAND_MAX * liczba_elementow;
	}
}
//Funkcja do wyswietlenia ostatnio przechowywanej tabeli liczb typu integer w pamieci
void OpcjeMenu::wyswietlOstatnioUzywanaTabele(int* tabela, int liczba_elementow) {
	//Walidacja na dostepnosc tabeli
	if (tabela == nullptr) {
		cout << "Brak tabeli do wyswietlenia" << endl;
		return;
	}
	//Wyswietlenie
	cout << "Ostatnio uzywana tabela: " << endl;
	for (int i = 0; i < liczba_elementow; i++) {
		cout << tabela[i] << " ";
	}
	cout << endl;
}
//Funkcja do wyswietlenia ostatnio przechowywanej tabeli liczb typu float w pamieci
void OpcjeMenu::wyswietlOstatnioUzywanaTabeleFloat(float* tabela, int liczba_elementow) {
	//Walidacja na dostepnosc tabeli
	if (tabela == nullptr) {
		cout << "Brak tabeli do wyswietlenia" << endl;
		return;
	}
	//Wyswietlenie
	cout << "Ostatnio uzywana tabela: " << endl;
	for (int i = 0; i < liczba_elementow; i++) {
		cout << tabela[i] << " ";
	}
	cout << endl;
}
//Menu dla pracy z generowaniem tabeli roznych typow
void OpcjeMenu::wyswietlMenuGlowne() {
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "|               Wybor danych do wczytywania                     |" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "|***************************** INT *****************************|" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "| 1 - wczytanie tabeli z pliku                                  |" << endl;
	cout << "| 2 - generowanie tabeli z calkowicie lososwymi wartosciami     |" << endl;
	cout << "| 3 - generowanie tabeli posortowanej rosnaco                   |" << endl;
	cout << "| 4 - generowanie tabeli posortowanej malejaco                  |" << endl;
	cout << "| 5 - generowanie tabeli posortowanej czesciowo 33%             |" << endl;
	cout << "| 6 - generowanie tabeli posortowanej czesciowo 66%             |" << endl;
	cout << "| 7 - wyswietlienie ostatnio uzywanej tabeli                    |" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "|**************************** FLOAT ****************************|" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "| 8 - wczytanie tabeli float z pliku                            |" << endl;
	cout << "| 9 - generowanie tabeli z losowymi wartosciami typu float      |" << endl;
	cout << "| 10 - generowanie tabeli typu float posortowanej rosnaco       |" << endl;
	cout << "| 11 - generowanie tabeli typu float posortowanej malejaco      |" << endl;
	cout << "| 12 - generowanie tabeli typu float posortowanej czesciowo 33% |" << endl;
	cout << "| 13 - generowanie tabeli typu float posortowanej czesciowo 66% |" << endl;
	cout << "| 14 - wyswietlienie ostatnio uzywanej tabeli typu float        |" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "| 15 - kontynuj ze stara tabela  INT                            |" << endl;
	cout << "| 16 - kontynuj ze stara tabela FLOAT                           |" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "| 0 - koniec programu                                           |" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "Wprowadz numer: " << endl;
}

//Funkjca do uzycia podsekcji menu dla sortowania tabeli typu float przez wstawianie
bool OpcjeMenu::sortujTabeleFloat(float* tabela, int liczba_elementow) {
	//Zmienna do przechowywania kopii tabeli typu float
	float* tabela_kopia = new float[liczba_elementow];
	//Deklaracja zmiennej do przechowywania czasu sortowania pojedynczego sortowania
	double czas_sortowania;
	int opcja;
	//Implementacja prostej podsekcji glownego menu dla sortowania
	while (true) {
		for (int i = 0; i < liczba_elementow; i++) {
			tabela_kopia[i] = tabela[i];
		}
		cout << "|----------------------------------------|" << endl;
		cout << "|           Menu sortowania FLOAT        |" << endl;
		cout << "|----------------------------------------|" << endl;
		cout << "| 1 - sortowanie przez wstawianie float  |" << endl;
		cout << "| 2 - zmiena danych wejsciowych tabeli   |" << endl;
		cout << "|----------------------------------------|" << endl;
		cout << "| 0 - koniec programu                    |" << endl;
		cout << "|----------------------------------------|" << endl;
		cout << "Wprowadz numer: " << endl;
		cin >> opcja;
		switch (opcja) {
		case 1:
			cout << "Tabela float przed sortowaniem przez wstawianie: " << endl;
			Sortowanie::wyswietlicTabelaFloat(tabela_kopia, liczba_elementow);
			cout << endl;
			Sortowanie::sortowanie_float_przez_wstawianie(tabela_kopia, liczba_elementow, czas_sortowania);
			cout << "Tabela po sortowaniu: " << endl;
			Sortowanie::wyswietlicTabelaFloat(tabela_kopia, liczba_elementow);
			cout << endl;
			cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
			break;
		case 2:
			//Zwolnienie pamieci
			delete[] tabela_kopia;
			return true;
		case 0:
			delete[] tabela_kopia;
			return false;
		}
	}
}
//Funkcja dla sortowania tabeli typu integer wybranym poprzez menu sortowania algorytmem 
bool OpcjeMenu::sortujTabele(int* tabela,  int liczba_elementow) {
menu:
	//Zmienne do przechowywania kopii tabeli do posortowania, a nastepnie ich sortowanie
	int* tabela_kopia = new int[liczba_elementow];
	int* tabela_kopia_szybkie = new int[liczba_elementow];
	int* tabela_kopia_shella = new int[liczba_elementow];
	//Deklaracja zmiennej do przechowywania czasu sortowania pojedynczego sortowania
	double czas_sortowania;
	int opcja;
	//Implementacja menu dla wyboru metod sortowania
	while (true) {
		//Kopiowanie tabeli
		for (int i = 0; i < liczba_elementow; i++) {
			tabela_kopia[i] = tabela[i];
		}
		cout << "|-----------------------------------------|" << endl;
		cout << "|                  Menu                   |" << endl;
		cout << "|-----------------------------------------|" << endl;
		cout << "| 1 - sortowanie przez wstawianie         |" << endl;
		cout << "| 2 - sortowanie binarne przez wstawianie |" << endl;
		cout << "| 3 - sortowanie przez kopcowanie         |" << endl;
		cout << "| 4 - szybkie sortowanie                  |" << endl;
		cout << "| 5 - sortowanie Shella (wybor wzoru)     |" << endl;
		cout << "| 6 - zmiena danych wejsciowych tabeli    |" << endl;
		cout << "|-----------------------------------------|" << endl;
		cout << "| 0 - koniec programu                     |" << endl;
		cout << "|-----------------------------------------|" << endl;
		cout << "Wprowadz numer: " << endl;
		cin >> opcja;
		switch (opcja) {
		case 1:
			//Wyswietlenie tabeli przed sortowaniem
			cout << "Tabela przed sortowaniem przez wstawianie: " << endl;
			Sortowanie::wyswietlicTabela(tabela_kopia, liczba_elementow);
			cout << endl;
			//Uzycie algorytmu dla sortowania tabeli typu integer przez wstawianie oraz zmierzenia czasu tego sortowania
			Sortowanie::sortowanie_przez_wstawianie(tabela_kopia, liczba_elementow, czas_sortowania);
			//Wyswietlenie tabeli po sortowaniu oraz czasu na pojedyncze sortowanie
			cout << "Tabela po sortowaniu: " << endl;
			Sortowanie::wyswietlicTabela(tabela_kopia, liczba_elementow);
			cout << endl;
			cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
			break;
		case 2:
			cout << "Tabela przed sortowaniem binarnym przez wstawianie: " << endl;
			Sortowanie::wyswietlicTabela(tabela_kopia, liczba_elementow);
			cout << endl;
			//Uzycie algorytmu dla sortowania binarnego przez wstawianie tabeli typu integer oraz zmierzenia czasu tego sortowania
			Sortowanie::sortowanie_binarne_przez_wstawianie(tabela_kopia, liczba_elementow, czas_sortowania);
			cout << "Tabela po sortowaniu: " << endl;
			Sortowanie::wyswietlicTabela(tabela_kopia, liczba_elementow);
			cout << endl;
			cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
			break;
		case 3:
			cout << "Tabela przed sortowaniem przez kopcowanie: " << endl;
			Sortowanie::wyswietlicTabela(tabela_kopia, liczba_elementow);
			cout << endl;
			//Uzycie algorytmu dla sortowania przez kopcowanie tabeli typu integer oraz zmierzenia czasu tego sortowania
			Sortowanie::sortowanie_przez_kopcowanie(tabela_kopia, liczba_elementow, czas_sortowania);
			cout << "Tabela po sortowaniu: " << endl;
			Sortowanie::wyswietlicTabela(tabela_kopia, liczba_elementow);
			cout << endl;
			cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
			break;
		case 4:
			int opcja2;
			while (true) {
				//Kopiowanie tabeli dla algorytmu szybkiego
				for (int i = 0; i < liczba_elementow; i++) {
					tabela_kopia_szybkie[i] = tabela[i];
				}
				//Menu wyboru pivota dla algorytmu szybkiego
				cout << "|---------------------------------------------------------------------------|" << endl;
				cout << "|                                 Wybor pivota                              |" << endl;
				cout << "|---------------------------------------------------------------------------|" << endl;
				cout << "| 1 - Sortowanie szybkie z wyborem skrajnego lewego elementu jako pivota    |" << endl;
				cout << "| 2 - Sortowanie szybkie z wyborem skrajnego prawego elementu jako pivota   |" << endl;
				cout << "| 3 - Sortowanie szybkie z wyborem srodkowego elementu jako pivota          |" << endl;
				cout << "| 4 - Sortowanie szybkie z wyborem lososwegp elementu jako pivota           |" << endl;
				cout << "|---------------------------------------------------------------------------|" << endl;
				cout << "| 0 - wyjscie do Menu                                                       |" << endl;
				cout << "|---------------------------------------------------------------------------|" << endl;
				cout << "Wprowadz numer: " << endl;
				cin >> opcja2;
				switch (opcja2) {
				case 1:
					cout << "Tabela przed sortowaniem szybkim z wyborem skrajnego lewego elementu jako pivota: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_szybkie, liczba_elementow);
					cout << endl;
					//Uzycie algorytmu dla sortowania szybkiego tabeli typu integer oraz zmierzenia czasu tego sortowania
					//Parametr 1 oznacza, ze pivotem jest skrajny lewy element tabeli
					Sortowanie::sortowanie_szybkie_pomiar_czasu(tabela_kopia_szybkie, liczba_elementow, 1, czas_sortowania);
					cout << "Tabela po sortowaniu: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_szybkie, liczba_elementow);
					cout << endl;
					cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
					break;
				case 2:
					cout << "Tabela przed sortowaniem szybkim z wyborem skrajnego prawego elementu jako pivota: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_szybkie, liczba_elementow);
					cout << endl;
					//Uzycie algorytmu dla sortowania szybkiego tabeli typu integer oraz zmierzenia czasu tego sortowania
					//Parametr 2 oznacza, ze pivotem jest skrajny prawy element tabeli
					Sortowanie::sortowanie_szybkie_pomiar_czasu(tabela_kopia_szybkie, liczba_elementow, 2, czas_sortowania);
					cout << "Tabela po sortowaniu: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_szybkie, liczba_elementow);
					cout << endl;
					cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
					break;
				case 3:
					cout << "Tabela przed sortowaniem szybkim z wyborem srodkowego elementu jako pivota: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_szybkie, liczba_elementow);
					cout << endl;
					//Uzycie algorytmu dla sortowania szybkiego tabeli typu integer oraz zmierzenia czasu tego sortowania
					//Parametr 3 oznacza, ze pivotem jest srodkowy element tabeli
					Sortowanie::sortowanie_szybkie_pomiar_czasu(tabela_kopia_szybkie, liczba_elementow, 3, czas_sortowania);
					cout << "Tabela po sortowaniu: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_szybkie, liczba_elementow);
					cout << endl;
					cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
					break;
				case 4:
					cout << "Tabela przed sortowaniem szybkim z wyborem losowego elementu jako pivota" << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_szybkie, liczba_elementow);
					cout << endl;
					//Uzycie algorytmu dla sortowania szybkiego tabeli typu integer oraz zmierzenia czasu tego sortowania
					//Parametr 4 oznacza, ze pivotem jest losowy element tabeli
					Sortowanie::sortowanie_szybkie_pomiar_czasu(tabela_kopia_szybkie, liczba_elementow, 4, czas_sortowania);
					cout << "Tabela po sortowaniu: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_szybkie, liczba_elementow);
					cout << endl;
					cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
					break;
				case 0:
					delete[] tabela_kopia_szybkie;
					goto menu;
				}
			}
			break;
		case 5:
			int opcja1;
			while (true) {
				//Kopiowanie tabeli dla algorytmu Shella
				for (int i = 0; i < liczba_elementow; i++) {
					tabela_kopia_shella[i] = tabela[i];
				}
				//Menu wyboru wzoru dla sortowania poprzez algorytm Shella
				cout << "|-----------------------------------------------------------------------|" << endl;
				cout << "|                                Wybor wzoru                            |" << endl;
				cout << "|-----------------------------------------------------------------------|" << endl;
				cout << "| 1 - Sortowanie Shella z wyborem odstepow na podstawie wzoru Hibbarda  |" << endl;
				cout << "| 2 - Sortowanie Shella z wyborem odstepow na podstawie wzoru Sedgewicka|" << endl;
				cout << "|-----------------------------------------------------------------------|" << endl;
				cout << "| 0 - wyjscie do Menu                                                   |" << endl;
				cout << "|-----------------------------------------------------------------------|" << endl;
				cout << "Wprowadz numer: " << endl;
				cin >> opcja1;
				switch (opcja1) {
				case 1:
					cout << "Tabela przed sortowaniem na podstawie wzoru Hibbarda: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_shella, liczba_elementow);
					cout << endl;
					//Uzycie algorytmu sortowania Shella wzorem Hibbarda dla tabeli typu integer
					Sortowanie::ShellaSortHibbard(tabela_kopia_shella, liczba_elementow, czas_sortowania);
					cout << "Tabela po sortowaniu: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_shella, liczba_elementow);
					cout << endl;
					cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
					break;
				case 2:
					cout << "Tabela przed sortowaniem na podstawie wzoru Sedgewicka: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_shella, liczba_elementow);
					cout << endl;
					//Uzycie algorytmu sortowania Shella wzorem Sedgewicka dla tabeli typu integer
					Sortowanie::ShellaSortSedgewick(tabela_kopia_shella, liczba_elementow, czas_sortowania);
					cout << "Tabela po sortowaniu: " << endl;
					Sortowanie::wyswietlicTabela(tabela_kopia_shella, liczba_elementow);
					cout << endl;
					cout << fixed << setprecision(2) << "Czas sortowania: " << czas_sortowania << " [ms]" << endl;
					break;
				case 0:
					delete[] tabela_kopia_shella;
					goto menu;
				}
			}
			break;
		case 6:
			//Zwolnienie pamieci
			delete[] tabela_kopia;
			delete[] tabela_kopia_szybkie;
			delete[] tabela_kopia_shella;
			return true;
		case 0:
			delete[] tabela_kopia;
			delete[] tabela_kopia_szybkie;
			delete[] tabela_kopia_shella;
			return false;
		}
	}
	delete[] tabela_kopia;
	delete[] tabela_kopia_szybkie;
	delete[] tabela_kopia_shella;
	return false;
}