#include "GrafLoader.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Funkcja wczytujaca graf z pliku do reprezentacji macierzy incydencji
bool GrafLoader::wczytajZPliku(const string& nazwaPliku, MacierzIncydencji& macierzGraf, MacierzIncydencji& macierzGraf_skierowany) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cerr << "Nie mozna otworzyc pliku: " << nazwaPliku << endl;
        return false;
    }

    int liczbaKrawedzi, liczbaWierzcholkow;
    plik >> liczbaKrawedzi >> liczbaWierzcholkow;

    cout << "Liczba krawedzi: " << liczbaKrawedzi << ", Liczba wierzcholkow: " << liczbaWierzcholkow << endl;

    macierzGraf = MacierzIncydencji(liczbaWierzcholkow, liczbaKrawedzi);
    macierzGraf_skierowany = MacierzIncydencji(liczbaWierzcholkow, liczbaKrawedzi);

    int poczatek, koniec, waga;
    while (plik >> poczatek >> koniec >> waga) {
        cout << "Czytam krawedz: " << poczatek << " -> " << koniec << " o wadze: " << waga << endl;
        macierzGraf.dodaj_krawedz(poczatek, koniec, waga, true);
        macierzGraf_skierowany.dodaj_krawedz(poczatek, koniec, waga, false);
    }

    plik.close();
    return true;
}

// Funkcja wczytujaca graf z pliku do reprezentacji listy sasiedztwa
bool GrafLoader::wczytajZPliku(const string& nazwaPliku, ListaSasiedstwa& listaGraf, ListaSasiedstwa& listaGraf_skierowany) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cerr << "Nie mozna otworzyc pliku: " << nazwaPliku << endl;
        return false;
    }

    int liczbaKrawedzi, liczbaWierzcholkow;
    plik >> liczbaKrawedzi >> liczbaWierzcholkow;
    listaGraf = ListaSasiedstwa(liczbaWierzcholkow);
    listaGraf_skierowany = ListaSasiedstwa(liczbaWierzcholkow);

    int poczatek, koniec, waga;
    while (plik >> poczatek >> koniec >> waga) {
        listaGraf.dodaj_krawedz(poczatek, koniec, waga, true);
        listaGraf_skierowany.dodaj_krawedz(poczatek, koniec, waga, false);
    }

    plik.close();
    return true;
}

// Funkcja generujaca losowy graf w reprezentacji macierzy incydencji
void GrafLoader::generujLosowyGraf(MacierzIncydencji& macierzGraf, MacierzIncydencji& macierzGraf_skierowany, int liczbaWierzcholkow, double gestosc) {
    int maksKrawedzi = liczbaWierzcholkow * (liczbaWierzcholkow - 1) / 2;
    macierzGraf = MacierzIncydencji(liczbaWierzcholkow, maksKrawedzi);
    macierzGraf_skierowany = MacierzIncydencji(liczbaWierzcholkow, maksKrawedzi);
    srand((unsigned int)time(0));

    // Utworzenie drzewa rozpinajacego MST (Minimal Spanning Tree)
    for (int i = 1; i < liczbaWierzcholkow; i++) {
        int waga = rand() % 100 + 1; // losowa waga
        macierzGraf.dodaj_krawedz(i - 1, i, waga, true);
        macierzGraf_skierowany.dodaj_krawedz(i - 1, i, waga, false);
    }

    // Dodanie dodatkowych krawedzi do osiagniecia zadanej gestosci
    int liczbaKrawedzi = static_cast<int>(maksKrawedzi * gestosc);
    int obecnaLiczbaKrawedzi = liczbaWierzcholkow - 1;

    while (obecnaLiczbaKrawedzi < liczbaKrawedzi) {
        int poczatek = rand() % liczbaWierzcholkow;
        int koniec = rand() % liczbaWierzcholkow;
        int waga = rand() % 100 + 1;

        if (poczatek != koniec && !macierzGraf.czyIstniejeKrawedz(poczatek, koniec)) {
            macierzGraf.dodaj_krawedz(poczatek, koniec, waga, true);
            macierzGraf_skierowany.dodaj_krawedz(poczatek, koniec, waga, false);
            obecnaLiczbaKrawedzi++;
        }
    }
}

// Funkcja generujaca losowy graf w reprezentacji listy sasiedztwa
void GrafLoader::generujLosowyGraf(ListaSasiedstwa& listaGraf, ListaSasiedstwa& listaGraf_skierowany, int liczbaWierzcholkow, double gestosc) {
    listaGraf = ListaSasiedstwa(liczbaWierzcholkow);
    listaGraf_skierowany = ListaSasiedstwa(liczbaWierzcholkow);
    srand((unsigned int)time(0));

    // Utworzenie drzewa rozpinajacego MST (Minimal Spanning Tree)
    for (int i = 1; i < liczbaWierzcholkow; i++) {
        int waga = rand() % 100 + 1;
        listaGraf.dodaj_krawedz(i - 1, i, waga, true);
        listaGraf_skierowany.dodaj_krawedz(i - 1, i, waga, false);
    }

    // Dodawanie dodatkowych krawedzie
    int maksKrawedzi = liczbaWierzcholkow * (liczbaWierzcholkow - 1) / 2;
    int liczbaKrawedzi = static_cast<int>(maksKrawedzi * gestosc);
    int obecnaLiczbaKrawedzi = liczbaWierzcholkow - 1;

    while (obecnaLiczbaKrawedzi < liczbaKrawedzi) {
        int poczatek = rand() % liczbaWierzcholkow;
        int koniec = rand() % liczbaWierzcholkow;
        int waga = rand() % 100 + 1;

        if (poczatek != koniec && !listaGraf.czyIstniejeKrawedz(poczatek, koniec)) {
            listaGraf.dodaj_krawedz(poczatek, koniec, waga, true);
            listaGraf_skierowany.dodaj_krawedz(poczatek, koniec, waga, false);
            obecnaLiczbaKrawedzi++;
        }
    }

    // Debugowanie: Wyswietlanie losowo wygenerowanego grafu
    cout << "Losowy graf (ListaSasiedstwa):" << endl;
    listaGraf.wyswietl();
    cout << "Losowy graf skierowany: " << endl;
    listaGraf_skierowany.wyswietl();
}
