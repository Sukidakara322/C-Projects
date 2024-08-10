#include <iostream>
#include "KlasaGlowna.h"
#include "TrybSymulacji.h"
#include "TrybTestowania.h"
using namespace std;



void KlasaGlowna::uruchom() {
	int* tabela = nullptr; //Wskaznik na tabele elementow typu integer
	float* tabela_float = nullptr; //Wskaznik na tabele typu float
	int liczba_elementow = 0; //Zmienna do przechowywania liczby elementow tabeli int
	int liczba_elementow_float = 0; //Zmienna do przechowywania liczby elementow tabeli float
	int wybor; //Zmienna do przechowywania wyboru w menu truby
	//Implementacja menu trybu
	cout << "|---------------------------|" << endl;
	cout << "|         Menu trybu        |" << endl;
	cout << "|---------------------------|" << endl;
	cout << "| 1 - Tryb symulacji        |" << endl;
	cout << "| 2 - Tryb testowania       |" << endl;
	cout << "|---------------------------|" << endl;
	cout << "| 0 - koniec programu       |" << endl;
	cout << "|---------------------------|" << endl;
	cout << "Podaj numer: " << endl;
	cin >> wybor;
	//W zaleznosci od wyboru trybu uruchomienie odpowiednego trybu pracy
	switch (wybor) {
	case 1:
		TrybSymulacji::uruchomSymulacje(tabela, tabela_float, liczba_elementow, liczba_elementow_float);
		break;
	case 2:
		TrybTestowania::uruchomTestowanie(tabela, tabela_float, liczba_elementow, liczba_elementow_float);
		break;
	case 0:
		break;
	default:
		cerr << "Nieprawidlowy wybor" << endl;
		break;
	}
}