#include <stdio.h>
#include <iostream>
#include <chrono>
#include "Sortowanie.h"

using namespace std;
//Sortowanie - klasa dla uzycia algorytmow sortowania dla tabeli
//Funkcja dla wyswietlenia elementow tabeli typu integer
void Sortowanie::wyswietlicTabela(int tabela[], int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		cout << tabela[i] << " ";
	}
}
//Funkcja dla wyswietlenia elementow tabeli typu float
void Sortowanie::wyswietlicTabelaFloat(float tabela[], int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		cout << tabela[i] << " ";
	}
}
//Algorytm sortowania przez wstawianie oraz obliczenie czasu sortowania tabeli
void Sortowanie::sortowanie_przez_wstawianie(int tabela[], int rozmiar, double& czas_sortowania) {
	auto start = chrono::high_resolution_clock::now(); //Rozpoczecie pomiaru czasu
	for (int i = 1; i < rozmiar; i++) {
		int klucz = tabela[i];
		int j = i - 1;
		//Przenosimy elementy, ktorzy sa wieksze niz klucz na jedna pozycja do przodu
		while (j >= 0 && tabela[j] > klucz) {
			tabela[j + 1] = tabela[j];
			j = j - 1;
		}
		tabela[j + 1] = klucz;
	}
	auto stop = chrono::high_resolution_clock::now(); // Zakonczenie pomiaru czasu
	chrono::duration<double> czas_trwania = stop - start; // Obliczenie czasu trwania w secundach
	czas_sortowania = round(czas_trwania.count() * 1000.0 * 100.0) / 100.0;//Przeliczenie na milisecundy oraz zaokraglenie do dwoch miejsc po przecinku
}
//Algorytm sortowania przez wstawianie dla liczb typu float oraz obliczenie czasu sortowania tabeli
void Sortowanie::sortowanie_float_przez_wstawianie(float tabela[], int rozmiar, double& czas_sortowania) {
	auto start = chrono::high_resolution_clock::now(); //Rozpoczecie pomiaru czasu
	for (int i = 1; i < rozmiar; i++) {
		float klucz = tabela[i];
		int j = i - 1;
		//Przenosimy elementy, ktorzy sa wieksze niz klucz na jedna pozycja do przodu
		while (j >= 0 && tabela[j] > klucz) {
			tabela[j + 1] = tabela[j];
			j = j - 1;
		}
		tabela[j + 1] = klucz;
	}
	auto stop = chrono::high_resolution_clock::now(); // Zakonczenie pomiaru czasu
	chrono::duration<double> czas_trwania = stop - start; // Obliczenie czasu trwania w secundach
	czas_sortowania = round(czas_trwania.count() * 1000.0 * 100.0) / 100.0;//Przeliczenie na milisecundy oraz zaokraglenie do dwoch miejsc po przecinku
}
//Algorytm sortowanie przez kopcowanie oraz obliczenie czasu sortowania tabeli
void Sortowanie::sortowanie_przez_kopcowanie(int tabela[], int rozmiar, double& czas_sortowania) {
	auto start = chrono::high_resolution_clock::now(); //Rozpoczecie pomiaru czasu
	//Budujemy kopiec
	for (int i = rozmiar / 2 - 1; i >= 0; i--) {
		heapify(tabela, rozmiar, i);
	}
	//Jeden za drugim bierzemy element z kopca, zaczynajac od ostatniego
	for (int i = rozmiar - 1; i > 0; i--) {
		//Przenosimy biezacy korzen w koniec
		swap(tabela[0], tabela[i]);
		// Przywracamy wlasnosci kopca na zmniejszonym kopcu.
		heapify(tabela, i, 0);
	}
	auto stop = chrono::high_resolution_clock::now(); // Zakonczenie pomiaru czasu
	chrono::duration<double> czas_trwania = stop - start; // Obliczenie czasu trwania w secundach
	czas_sortowania = round(czas_trwania.count() * 1000.0 * 100.0) / 100.0;//Przeliczenie na milisecundy oraz zaokraglenie do dwoch miejsc po przecinku
}
// Algorytm sortowania binarnego przez wstawianie oraz obliczenie czasu sortowania tabeli
void Sortowanie::sortowanie_binarne_przez_wstawianie(int tabela[], int rozmiar, double& czas_sortowania) {
	auto start = chrono::high_resolution_clock::now();
	for (int i = 1; i < rozmiar; i++) {
		int wybrany = tabela[i];
		int j = i - 1;

		//Poszuk poprawnej pozycji do wstawiania wybranego elementu uzywajac wyszukiwanie binarne
		int pozycja = binarne_wyszukiwanie(tabela, wybrany, 0, j);
		//Przeniesienie elementow dla wstawiania wybranego elementu
		while (j >= pozycja) {
			tabela[j + 1] = tabela[j];
			j--;
		}
		tabela[j + 1] = wybrany;
	}
	auto stop = chrono::high_resolution_clock::now(); // Zakonczenie pomiaru czasu
	chrono::duration<double> czas_trwania = stop - start; // Obliczenie czasu trwania w secundach
	czas_sortowania = round(czas_trwania.count() * 1000.0 * 100.0) / 100.0;//Przeliczenie na milisecundy oraz zaokraglenie do dwoch miejsc po przecinku
}
//Pomiar czasu wykonania algorytmu szybkiego sortowania
void Sortowanie::sortowanie_szybkie_pomiar_czasu(int tabela[], int rozmiar, int pivot_option, double& czas_sortowania) {
	auto start = chrono::high_resolution_clock::now(); //Rozpoczecie pomiaru czasu
	sortowanie_szybkie(tabela, 0, rozmiar - 1, pivot_option);

	auto stop = chrono::high_resolution_clock::now(); // Zakonczenie pomiaru czasu
	chrono::duration<double> czas_trwania = stop - start; // Obliczenie czasu trwania w secundach
	czas_sortowania = round(czas_trwania.count() * 1000.0 * 100.0) / 100.0;//Przeliczenie na milisecundy oraz zaokraglenie do dwoch miejsc po przecinku
}
// Algorytm szybkiego sortowania z mozliwoscia wyboru pivota.
void Sortowanie::sortowanie_szybkie(int tabela[], int lewy, int prawy, int pivot_option) {
	if (lewy < prawy) {
		int pi = partycjonowanie(tabela, lewy, prawy, pivot_option);
		sortowanie_szybkie(tabela, lewy, pi - 1, pivot_option);
		sortowanie_szybkie(tabela, pi + 1, prawy, pivot_option);
	}
}
// Algorytm sortowania Shella z wykorzystaniem sekwencji Hibbarda
void Sortowanie::ShellaSortHibbard(int tabela[], int n, double& czas_sortowania) {
	auto start = chrono::high_resolution_clock::now();
	for (int przerwa = n / 2; przerwa > 0; przerwa /= 2) {
		for (int i = przerwa; i < n; i++) {
			int temp = tabela[i];
			int j;
			for (j = i; j >= przerwa && tabela[j - przerwa] > temp; j -= przerwa) {
				tabela[j] = tabela[j - przerwa];
			}
			tabela[j] = temp;
		}
	}
	auto stop = chrono::high_resolution_clock::now(); // Zakonczenie pomiaru czasu
	chrono::duration<double> czas_trwania = stop - start; // Obliczenie czasu trwania w secundach
	czas_sortowania = round(czas_trwania.count() * 1000.0 * 100.0) / 100.0;//Przeliczenie na milisecundy oraz zaokraglenie do dwoch miejsc po przecinku
}
// Algorytm sortowania Shella z wykorzystaniem sekwencji Sedgewicka.
void Sortowanie::ShellaSortSedgewick(int tabela[], int n, double& czas_sortowania) {
	auto start = chrono::high_resolution_clock::now();
	int przerwy[] = { 1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001, 36289, 64769, 146305 };
	int przerwaIndex = 0;
	// Szukamy najwiekszej przerwy mniejszej niz rozmiar tablicy
	while (przerwy[przerwaIndex] < n) {
		przerwaIndex++;
	}
	// Wykonujemy sortowanie Shella dla kazdej z przerw
	for (; przerwaIndex >= 0; przerwaIndex--) {
		int przerwa = przerwy[przerwaIndex];
		for (int i = przerwa; i < n; i++) {
			int temp = tabela[i];
			int j;
			for (j = i; j >= przerwa && tabela[j - przerwa] > temp; j -= przerwa) {
				tabela[j] = tabela[j - przerwa];
			}
			tabela[j] = temp;
		}
	}
	auto stop = chrono::high_resolution_clock::now(); // Zakonczenie pomiaru czasu
	chrono::duration<double> czas_trwania = stop - start; // Obliczenie czasu trwania w secundach
	czas_sortowania = round(czas_trwania.count() * 1000.0 * 100.0) / 100.0;//Przeliczenie na milisecundy oraz zaokraglenie do dwoch miejsc po przecinku
}


//Funkcja pomocnicza dla algorytmu sortowania przez kopcowanie, ktora przywraca wlasciwosci kopca dla danego wezla
void Sortowanie::heapify(int tabela[], int rozmiar, int i) {
	// Zakladamy, ze korzen jest najwiekszym elementem
	int najwieksza = i;
	//Lewe dziecko
	int lewo = 2 * i + 1;
	//Prawe dziecko
	int prawo = 2 * i + 2;

	//Jesli lewo dziecko jest wieksze niz korzen
	if (lewo < rozmiar && tabela[lewo] > tabela[najwieksza]) {
		najwieksza = lewo;
	}
	
	//Jesli prawo dziecko jest wieksze niz niniejsza najwieksza
	if (prawo < rozmiar && tabela[prawo] > tabela[najwieksza]) {
		najwieksza = prawo;
	}
	
	//Jesli najwieksza nie jest korzeniem, dokonujemy zamiany
	if (najwieksza != i) {
		swap(tabela[i], tabela[najwieksza]);
		//Rekursywnie kopiujemy poddrzewo, ktorego dotyczy problem
		heapify(tabela, rozmiar, najwieksza);
	}
}
// Funkcja pomocnicza do wyszukiwania binarnego w algorytmie sortowania binarnego przez wstawianie,
//ona zwraca indeks, pod ktory nalezy wstawic element
int Sortowanie::binarne_wyszukiwanie(int tabela[], int rzecz, int niski, int wysoki) {
	if (wysoki <= niski) {
		return (rzecz > tabela[niski]) ? (niski + 1) : niski;
	}
	int sredni = (niski + wysoki) / 2;
	if (rzecz == tabela[sredni]) {
		return sredni + 1;
	}
	if (rzecz > tabela[sredni]) {
		return binarne_wyszukiwanie(tabela, rzecz, sredni + 1, wysoki);
	}
	return binarne_wyszukiwanie(tabela, rzecz, niski, sredni - 1);
}
//Funkcja pomocnicza do wyboru pivota w algorytmie szybkiego sortowania,
//ona zwraca indeks wybranego pivota na podstawie wybranej opcji
int Sortowanie::wyborPivota(int tabela[], int lewy, int prawy, int pivot_option) {
switch (pivot_option) {
	case 1:
		return lewy; //Pivot jako pierwszy element tabeli
	case 2:
		return prawy; //Pivot jako ostatni element tabeli
	case 3:
		return lewy + (prawy - lewy) / 2; //Pivot jako element srodkowy
	case 4:
		return lewy + rand() % (prawy - lewy + 1); //Pivot jako element losowy
	default:
		return lewy; //Domyslnie pivot jako pierwszy element
	}
}
//Funkcja do partycjonowania tablicy w algorytmie szybkiego sortowania,
//ona dzieli tablice na dwie czesci: mniejsze od pivota i wieksze od pivota
int Sortowanie::partycjonowanie(int tabela[], int lewy, int prawy, int pivot_option) {
	int pivot_index = wyborPivota(tabela, lewy, prawy, pivot_option); //Wybor pivota
	swap(tabela[pivot_index], tabela[prawy]); //Zamiana pivota z ostatnim elementem
	int pivot = tabela[prawy]; //Pivot
	int i = lewy - 1; //Indeks mniejszego elementu

	for (int j = lewy; j <= prawy - 1; j++) {
		//Jesli aktualny element jest mniejszy lub rowny pivotowi, zamieniamy go z elementem o indeksie i
		if (tabela[j] <= pivot) {
			i++;
			swap(tabela[i], tabela[j]);
		}
	}
	swap(tabela[i + 1], tabela[prawy]); //Wstawiamy pivota na wlasciwe miejsce
	return i + 1; //Zwracamy indeks podzialu
}
