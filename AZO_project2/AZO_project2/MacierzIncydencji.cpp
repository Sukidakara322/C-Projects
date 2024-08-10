#include "MacierzIncydencji.h"
#include <iostream>
using namespace std;

// Konstruktor klasy MacierzIncydencji, inicjalizuje macierz incydencji
MacierzIncydencji::MacierzIncydencji(int V, int E) : liczbaWierzcholkow(V), liczbaKrawedzi(0) {
    macierz = new int* [V];
    for (int i = 0; i < V; i++) {
        macierz[i] = new int[E];
        for (int j = 0; j < E; j++) {
            macierz[i][j] = 0;
        }
    }
}

// Metoda dodajaca krawedz do macierzy incydencji
void MacierzIncydencji::dodaj_krawedz(int poczatek, int koniec, int waga, bool nieskierowana) {
    if (poczatek >= 0 && poczatek < liczbaWierzcholkow && koniec >= 0 && koniec < liczbaWierzcholkow) {
        macierz[poczatek][liczbaKrawedzi] = waga;
        macierz[koniec][liczbaKrawedzi] = nieskierowana ? waga : -waga;
        cout << "Dodano krawedz: " << poczatek << " -> " << koniec << " o wadze: " << waga << endl;
        if (nieskierowana) {
            cout << "Dodano krawedz: " << koniec << " -> " << poczatek << " o wadze: " << waga << endl;
        }
        liczbaKrawedzi++;
    }
    else {
        cerr << "Blad: indeks wierzcholka poza zakresem. (" << poczatek << ", " << koniec << ")" << endl;
    }
}

// Metoda wyswietlajaca macierz incydencji
void MacierzIncydencji::wyswietl() {
    cout << "Macierz Incydencji:\n";
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        for (int j = 0; j < liczbaKrawedzi; j++) {
            cout << macierz[i][j] << " ";
        }
        cout << "\n";
    }
}

// Metoda zwracajaca liczbe wierzcholkow w grafie
int MacierzIncydencji::getLiczbaWierzcholkow() const {
    return liczbaWierzcholkow;
}

// Metoda zwracajaca liczbe krawedzi w grafie
int MacierzIncydencji::getLiczbaKrawedzi() const {
    return liczbaKrawedzi;
}

// Metoda zwracajaca macierz incydencji
int** MacierzIncydencji::getMacierz() const {
    return macierz;
}

// Metoda zwracajaca macierz wag
int** MacierzIncydencji::getWagi() const {
    return macierz;
}

// Metoda sprawdzajaca, czy istnieje krawedz pomiedzy dwoma wierzcholkami
bool MacierzIncydencji::czyIstniejeKrawedz(int poczatek, int koniec) const {
    for (int j = 0; j < liczbaKrawedzi; j++) {
        if (macierz[poczatek][j] != 0 && macierz[koniec][j] != 0) {
            return true;
        }
    }
    return false;
}

// Metoda sprawdzajaca, czy graf jest spojny
bool MacierzIncydencji::czySpojny() const {
    if (liczbaWierzcholkow == 0) return true;  // Pusty graf uznajemy za spojny

    bool* odwiedzone = new bool[liczbaWierzcholkow]();
    int startowyWierzcholek = 0;  // Mozemy zaczac od dowolnego wierzcholka, tutaj wybieramy 0

    // Wywolujemy DFS
    dfs(odwiedzone, startowyWierzcholek);

    // Sprawdzamy, czy wszystkie wierzcholki zostaly odwiedzone
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        if (!odwiedzone[i]) {
            delete[] odwiedzone;
            return false;
        }
    }
    delete[] odwiedzone;
    return true;
}

// Prywatna metoda DFS do przeszukiwania grafu w glab
void MacierzIncydencji::dfs(bool* odwiedzone, int wierzcholek) const {
    odwiedzone[wierzcholek] = true;
    for (int j = 0; j < liczbaKrawedzi; j++) {
        if (macierz[wierzcholek][j] != 0) {
            for (int i = 0; i < liczbaWierzcholkow; i++) {
                if (macierz[i][j] != 0 && !odwiedzone[i]) {
                    dfs(odwiedzone, i);
                }
            }
        }
    }
}
