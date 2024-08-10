#ifndef KRUSKALMST_H
#define KRUSKALMST_H

#include "MacierzIncydencji.h"
#include "ListaSasiedstwa.h"

// Struktura reprezentujaca krawedz w grafie
struct Krawedz {
    int start, koniec, waga;
    // Operator porownania potrzebny do sortowania krawedzi
    bool operator<(const Krawedz& other) const {
        return waga < other.waga;
    }
};

// Klasa implementujaca algorytm Kruskala do znajdowania MST (minimalnego drzewa rozpinajacego)
class KruskalMST {
public:
    // Metoda znajdujaca MST dla grafu reprezentowanego jako macierz incydencji
    void znajdzMST(MacierzIncydencji& graf);

    // Metoda znajdujaca MST dla grafu reprezentowanego jako lista sasiedztwa
    void znajdzMST(ListaSasiedstwa& graf);

    // Metoda wyswietlajaca znalezione MST oraz calkowity koszt
    void wyswietlMST(Krawedz* mst, int n, int totalCost);

private:
    // Metoda do znajdowania przedstawiciela zbioru elementu i (z kompresja sciezki)
    int find(int i, int* parent);

    // Metoda do laczenia dwoch zbiorow
    void union1(int i, int j, int* parent);
};

#endif
