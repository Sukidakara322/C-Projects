#include "ListaSasiedstwa.h"
#include <iostream>
#include <stack>
using namespace std;

// Konstruktor klasy ListaSasiedstwa, inicjalizuje liczbe wierzcholkow oraz liste sasiedztwa
ListaSasiedstwa::ListaSasiedstwa(int wierzcholki) : liczbaWierzcholkow(wierzcholki) {
    listaSasiedztwa = new list<pair<int, int>>[wierzcholki];
}

// Metoda dodajaca krawedz do grafu
void ListaSasiedstwa::dodaj_krawedz(int poczatek, int koniec, int waga, bool nieskierowana) {
    if (poczatek >= 0 && poczatek < liczbaWierzcholkow && koniec >= 0 && koniec < liczbaWierzcholkow) {
        listaSasiedztwa[poczatek].emplace_back(koniec, waga);
        if (nieskierowana) {
            listaSasiedztwa[koniec].emplace_back(poczatek, waga);  // Dodaj krawedz w przeciwnym kierunku
        }
    }
    else {
        cerr << "Blad: Indeks wierzcholka poza zakresem." << endl;
    }
}

// Metoda wyswietlajaca liste sasiedztwa
void ListaSasiedstwa::wyswietl() const {
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        cout << "Wierzcholek " << i << " laczy sie z: ";
        for (const auto& krawedz : listaSasiedztwa[i]) {
            cout << "[" << krawedz.first << " waga: " << krawedz.second << "] ";
        }
        cout << endl;
    }
}

// Metoda zwracajaca liczbe wierzcholkow w grafie
int ListaSasiedstwa::getLiczbaWierzcholkow() const {
    return liczbaWierzcholkow;
}

// Metoda zwracajaca liste sasiedztwa dla danego wierzcholka
const list<pair<int, int>>& ListaSasiedstwa::getSasiedzi(int wierzcholek) const {
    return listaSasiedztwa[wierzcholek];
}

// Metoda sprawdzajaca, czy istnieje krawedz pomiedzy dwoma wierzcholkami
bool ListaSasiedstwa::czyIstniejeKrawedz(int poczatek, int koniec) const {
    if (poczatek < 0 || koniec < 0 || poczatek >= liczbaWierzcholkow || koniec >= liczbaWierzcholkow) {
        cerr << "Blad: Indeks wierzcholka poza zakresem przy sprawdzaniu krawedzi." << endl;
        return false;
    }
    const list<pair<int, int>>& sasiedzi = listaSasiedztwa[poczatek];
    for (const auto& sasiedziPara : sasiedzi) {
        if (sasiedziPara.first == koniec) {
            return true;  // Krawedz istnieje
        }
    }
    return false;  // Krawedz nie istnieje
}

// Metoda sprawdzajaca, czy graf jest spojny
bool ListaSasiedstwa::czySpojny() const {
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
void ListaSasiedstwa::dfs(bool* odwiedzone, int wierzcholek) const {
    odwiedzone[wierzcholek] = true;
    for (const auto& sasiedzi : listaSasiedztwa[wierzcholek]) {
        if (!odwiedzone[sasiedzi.first]) {
            dfs(odwiedzone, sasiedzi.first);
        }
    }
}
