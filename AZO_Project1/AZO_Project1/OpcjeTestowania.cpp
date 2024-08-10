#include "OpcjeMenu.h"
#include "Sortowanie.h"
#include "OpcjeTestowania.h"
#include <iostream>
#include <iomanip>

using namespace std;
//OpcjeTestowania - klasa dla uzycia algorytmow sortowania oraz zmierzenia czasu sortowania w testowym formacie
//Funkcja dla kilkakrotnego uzycia algorytmow sortowania w zaleznosci od wybranej generacji tabeli
bool OpcjeTestowania::sortujTabeleTestowanie(int* tabela, int liczba_elementow, int liczba_sortowan, int wybor) {
menu:
	//Zmienne do przechowywania kopii tabeli do posortowania, a nastepnie ich sortowanie
	int* tabela_kopia = new int[liczba_elementow];
	int* tabela_kopia_szybkie = new int[liczba_elementow];
	int* tabela_kopia_shella = new int[liczba_elementow];
	//Deklaracja zmiennych dla obliczenia czasu sortowania pojedynczego sortowania oraz sredniego czasu
	double czas_sortowania;
	double suma_czasow = 0.0;
	double sredni_czas = 0.0;
	int opcja;
	while (true) {
		for (int i = 0; i < liczba_elementow; i++) {
			tabela_kopia[i] = tabela[i];
		}
		//Menu algorytmow sortowania
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
			//Sortowanie przez wstawianie tabeli typu integer za kazdym razem generujac nowy zestaw danych
			for (int i = 1; i <= liczba_sortowan; i++) {
				Sortowanie::sortowanie_przez_wstawianie(tabela_kopia, liczba_elementow, czas_sortowania);
				//Sumowanie czasow pojedynczego sortowania
				suma_czasow += czas_sortowania;
				cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
				//Uzycie odpowednego algorytmu generowania danych w zaleznosci od wybranego typu w menu wyboru danych do wczytywania
				if (wybor == 1) {
					for (int i = 0; i < liczba_elementow; i++) {
						tabela_kopia[i] = tabela[i];
					}
				}
				if (wybor == 2) {
					OpcjeMenu::generujTabeleLosowo(tabela_kopia, liczba_elementow);
				}
				if (wybor == 3) {
					OpcjeMenu::generujTabeleRosnaco(tabela_kopia, liczba_elementow);
				}
				if (wybor == 4) {
					OpcjeMenu::generujTabeleMalejaco(tabela_kopia, liczba_elementow);
				}
				if (wybor == 5) {
					OpcjeMenu::generujTabele33Posortowana(tabela_kopia, liczba_elementow);
				}
				if (wybor == 6) {
					OpcjeMenu::generujTabele66Posortowana(tabela_kopia, liczba_elementow);
				}
			}
			cout << endl;
			if (liczba_sortowan > 0) {
				sredni_czas = suma_czasow / liczba_sortowan; // Obliczanie sredniego czasu sortowania przez wstawianie
				cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
			}
			sredni_czas = 0.0;
			suma_czasow = 0.0;
			break;
		case 2:
			//Sortowanie binarne przez wstawianie tabeli typu integer za kazdym razem generujac nowy zestaw danych
			for (int i = 1; i <= liczba_sortowan; i++) {
				Sortowanie::sortowanie_binarne_przez_wstawianie(tabela_kopia, liczba_elementow, czas_sortowania);
				suma_czasow += czas_sortowania;
				cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
				if (wybor == 1) {
					for (int i = 0; i < liczba_elementow; i++) {
						tabela_kopia[i] = tabela[i];
					}
				}
				if (wybor == 2) {
					OpcjeMenu::generujTabeleLosowo(tabela_kopia, liczba_elementow);
				}
				if (wybor == 3) {
					OpcjeMenu::generujTabeleRosnaco(tabela_kopia, liczba_elementow);
				}
				if (wybor == 4) {
					OpcjeMenu::generujTabeleMalejaco(tabela_kopia, liczba_elementow);
				}
				if (wybor == 5) {
					OpcjeMenu::generujTabele33Posortowana(tabela_kopia, liczba_elementow);
				}
				if (wybor == 6) {
					OpcjeMenu::generujTabele66Posortowana(tabela_kopia, liczba_elementow);
				}
			}
			cout << endl;
			if (liczba_sortowan > 0) {
				sredni_czas = suma_czasow / liczba_sortowan;
				cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
			}
			sredni_czas = 0.0;
			suma_czasow = 0.0;
			break;
		case 3:
			//Sortowanie przez kopcowanie tabeli typu integer za kazdym razem generujac nowy zestaw danych
			for (int i = 1; i <= liczba_sortowan; i++) {
				Sortowanie::sortowanie_przez_kopcowanie(tabela_kopia, liczba_elementow, czas_sortowania);
				suma_czasow += czas_sortowania;
				cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
				if (wybor == 1) {
					for (int i = 0; i < liczba_elementow; i++) {
						tabela_kopia[i] = tabela[i];
					}
				}
				if (wybor == 2) {
					OpcjeMenu::generujTabeleLosowo(tabela_kopia, liczba_elementow);
				}
				if (wybor == 3) {
					OpcjeMenu::generujTabeleRosnaco(tabela_kopia, liczba_elementow);
				}
				if (wybor == 4) {
					OpcjeMenu::generujTabeleMalejaco(tabela_kopia, liczba_elementow);
				}
				if (wybor == 5) {
					OpcjeMenu::generujTabele33Posortowana(tabela_kopia, liczba_elementow);
				}
				if (wybor == 6) {
					OpcjeMenu::generujTabele66Posortowana(tabela_kopia, liczba_elementow);
				}
			}
			cout << endl;
			if (liczba_sortowan > 0) {
				sredni_czas = suma_czasow / liczba_sortowan;
				cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
			}
			sredni_czas = 0.0;
			suma_czasow = 0.0;
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
					for (int i = 1; i <= liczba_sortowan; i++) {
						Sortowanie::sortowanie_szybkie_pomiar_czasu(tabela_kopia_szybkie, liczba_elementow, 1, czas_sortowania);
						suma_czasow += czas_sortowania;
						cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
						if (wybor == 1) {
							for (int i = 0; i < liczba_elementow; i++) {
								tabela_kopia_szybkie[i] = tabela[i];
							}
						}
						if (wybor == 2) {
							OpcjeMenu::generujTabeleLosowo(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 3) {
							OpcjeMenu::generujTabeleRosnaco(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 4) {
							OpcjeMenu::generujTabeleMalejaco(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 5) {
							OpcjeMenu::generujTabele33Posortowana(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 6) {
							OpcjeMenu::generujTabele66Posortowana(tabela_kopia_szybkie, liczba_elementow);
						}
					}
					cout << endl;
					if (liczba_sortowan > 0) {
						sredni_czas = suma_czasow / liczba_sortowan;
						cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
					}
					sredni_czas = 0.0;
					suma_czasow = 0.0;
					break;
				case 2:
					for (int i = 1; i <= liczba_sortowan; i++) {
						Sortowanie::sortowanie_szybkie_pomiar_czasu(tabela_kopia_szybkie, liczba_elementow, 2, czas_sortowania);
						suma_czasow += czas_sortowania;
						cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
						if (wybor == 1) {
							for (int i = 0; i < liczba_elementow; i++) {
								tabela_kopia_szybkie[i] = tabela[i];
							}
						}
						if (wybor == 2) {
							OpcjeMenu::generujTabeleLosowo(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 3) {
							OpcjeMenu::generujTabeleRosnaco(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 4) {
							OpcjeMenu::generujTabeleMalejaco(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 5) {
							OpcjeMenu::generujTabele33Posortowana(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 6) {
							OpcjeMenu::generujTabele66Posortowana(tabela_kopia_szybkie, liczba_elementow);
						}
					}
					cout << endl;
					if (liczba_sortowan > 0) {
						sredni_czas = suma_czasow / liczba_sortowan;
						cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
					}
					sredni_czas = 0.0;
					suma_czasow = 0.0;
					break;
				case 3:
					for (int i = 1; i <= liczba_sortowan; i++) {
						Sortowanie::sortowanie_szybkie_pomiar_czasu(tabela_kopia_szybkie, liczba_elementow, 3, czas_sortowania);
						suma_czasow += czas_sortowania;
						cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
						if (wybor == 1) {
							for (int i = 0; i < liczba_elementow; i++) {
								tabela_kopia_szybkie[i] = tabela[i];
							}
						}
						if (wybor == 2) {
							OpcjeMenu::generujTabeleLosowo(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 3) {
							OpcjeMenu::generujTabeleRosnaco(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 4) {
							OpcjeMenu::generujTabeleMalejaco(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 5) {
							OpcjeMenu::generujTabele33Posortowana(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 6) {
							OpcjeMenu::generujTabele66Posortowana(tabela_kopia_szybkie, liczba_elementow);
						}
					}
					cout << endl;
					if (liczba_sortowan > 0) {
						sredni_czas = suma_czasow / liczba_sortowan;
						cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
					}
					sredni_czas = 0.0;
					suma_czasow = 0.0;
					break;
				case 4:
					for (int i = 1; i <= liczba_sortowan; i++) {
						Sortowanie::sortowanie_szybkie_pomiar_czasu(tabela_kopia_szybkie, liczba_elementow, 4, czas_sortowania);
						suma_czasow += czas_sortowania;
						cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
						if (wybor == 1) {
							for (int i = 0; i < liczba_elementow; i++) {
								tabela_kopia_szybkie[i] = tabela[i];
							}
						}
						if (wybor == 2) {
							OpcjeMenu::generujTabeleLosowo(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 3) {
							OpcjeMenu::generujTabeleRosnaco(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 4) {
							OpcjeMenu::generujTabeleMalejaco(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 5) {
							OpcjeMenu::generujTabele33Posortowana(tabela_kopia_szybkie, liczba_elementow);
						}
						if (wybor == 6) {
							OpcjeMenu::generujTabele66Posortowana(tabela_kopia_szybkie, liczba_elementow);
						}
					}
					cout << endl;
					if (liczba_sortowan > 0) {
						sredni_czas = suma_czasow / liczba_sortowan;
						cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
					}
					sredni_czas = 0.0;
					suma_czasow = 0.0;
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
				//Menu wyboru wzoru dla algorytmu Shella
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
					for (int i = 1; i <= liczba_sortowan; i++) {
						Sortowanie::ShellaSortHibbard(tabela_kopia_shella, liczba_elementow, czas_sortowania);
						suma_czasow += czas_sortowania;
						cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
						if (wybor == 1) {
							for (int i = 0; i < liczba_elementow; i++) {
								tabela_kopia_shella[i] = tabela[i];
							}
						}
						if (wybor == 2) {
							OpcjeMenu::generujTabeleLosowo(tabela_kopia_shella, liczba_elementow);
						}
						if (wybor == 3) {
							OpcjeMenu::generujTabeleRosnaco(tabela_kopia_shella, liczba_elementow);
						}
						if (wybor == 4) {
							OpcjeMenu::generujTabeleMalejaco(tabela_kopia_shella, liczba_elementow);
						}
						if (wybor == 5) {
							OpcjeMenu::generujTabele33Posortowana(tabela_kopia_shella, liczba_elementow);
						}
						if (wybor == 6) {
							OpcjeMenu::generujTabele66Posortowana(tabela_kopia_shella, liczba_elementow);
						}
					}
					cout << endl;
					if (liczba_sortowan > 0) {
						sredni_czas = suma_czasow / liczba_sortowan;
						cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
					}
					sredni_czas = 0.0;
					suma_czasow = 0.0;
					break;
				case 2:
					for (int i = 1; i <= liczba_sortowan; i++) {
						Sortowanie::ShellaSortSedgewick(tabela_kopia_shella, liczba_elementow, czas_sortowania);
						suma_czasow += czas_sortowania;
						cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
						if (wybor == 1) {
							for (int i = 0; i < liczba_elementow; i++) {
								tabela_kopia_shella[i] = tabela[i];
							}
						}
						if (wybor == 2) {
							OpcjeMenu::generujTabeleLosowo(tabela_kopia_shella, liczba_elementow);
						}
						if (wybor == 3) {
							OpcjeMenu::generujTabeleRosnaco(tabela_kopia_shella, liczba_elementow);
						}
						if (wybor == 4) {
							OpcjeMenu::generujTabeleMalejaco(tabela_kopia_shella, liczba_elementow);
						}
						if (wybor == 5) {
							OpcjeMenu::generujTabele33Posortowana(tabela_kopia_shella, liczba_elementow);
						}
						if (wybor == 6) {
							OpcjeMenu::generujTabele66Posortowana(tabela_kopia_shella, liczba_elementow);
						}
					}
					cout << endl;
					if (liczba_sortowan > 0) {
						sredni_czas = suma_czasow / liczba_sortowan;
						cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
					}
					sredni_czas = 0.0;
					suma_czasow = 0.0;
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
//Funkcja dla kilkakrotnego uzycia algorytmu sortowania przez wstawianie dla tabeli typu float w zaleznosci od wybranej generacji tabeli
bool OpcjeTestowania::sortujTabeleFloatTestowanie(float* tabela_float, int liczba_elementow_float, int liczba_sortowan, int wybor) {
	float* tabela_kopia = new float[liczba_elementow_float];
	double czas_sortowania;
	double suma_czasow = 0.0;
	double sredni_czas = 0.0;
	int opcja;
	while (true) {
		for (int i = 0; i < liczba_elementow_float; i++) {
			tabela_kopia[i] = tabela_float[i];
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
			for (int i = 1; i <= liczba_sortowan; i++) {
				Sortowanie::sortowanie_float_przez_wstawianie(tabela_kopia, liczba_elementow_float, czas_sortowania);
				suma_czasow += czas_sortowania;
				cout << fixed << setprecision(2) << "Sortowanie nr." << i << " - Czas sortowania: " << czas_sortowania << " [ms]" << endl;
				if (wybor == 8) {
					for (int i = 0; i < liczba_elementow_float; i++) {
						tabela_kopia[i] = tabela_float[i];
					}
				}
				if (wybor == 9) {
					OpcjeMenu::generujTabeleLosowoFloat(tabela_kopia, liczba_elementow_float);
				}
				if (wybor == 10) {
					OpcjeMenu::generujTabeleRosnacoFloat(tabela_kopia, liczba_elementow_float);
				}
				if (wybor == 11) {
					OpcjeMenu::generujTabeleMalejacoFloat(tabela_kopia, liczba_elementow_float);
				}
				if (wybor == 12) {
					OpcjeMenu::generujTabele33PosortowanaFloat(tabela_kopia, liczba_elementow_float);
				}
				if (wybor == 13) {
					OpcjeMenu::generujTabele66PosortowanaFloat(tabela_kopia, liczba_elementow_float);
				}
			}
			cout << endl;
			if (liczba_sortowan > 0) {
				sredni_czas = suma_czasow / liczba_sortowan;
				cout << "Sredni czas sortowania: " << sredni_czas << " [ms]" << endl;
			}
			sredni_czas = 0.0;
			suma_czasow = 0.0;
			break;
		case 2:
			delete[] tabela_kopia;
			return true;
		case 0:
			delete[] tabela_kopia;
			return false;
		}
	}
}