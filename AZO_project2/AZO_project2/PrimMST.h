#ifndef PRIMMST_H
#define PRIMMST_H

#include "MacierzIncydencji.h"
#include "ListaSasiedstwa.h"

// Klasa implementujaca algorytm Prima dla znajdowania minimalnego drzewa rozpinajacego (MST)
class PrimMST {
public:
    // Funkcja do znajdowania MST w grafie reprezentowanym za pomoca macierzy incydencji
    void znajdzMST(MacierzIncydencji& graf);

    // Funkcja do znajdowania MST w grafie reprezentowanym za pomoca listy sasiedztwa
    void znajdzMST(ListaSasiedstwa& graf);

private:
    // Funkcja pomocnicza do znajdowania wierzcholka z minimalnym kluczem, ktory nie jest jeszcze w MST
    int minKey(int* key, bool* mstSet, int V);

    // Funkcja do wyswietlania MST dla grafu reprezentowanego za pomoca macierzy incydencji
    void wyswietlMST(int* parent, int* key, int n);

    // Funkcja do wyswietlania MST dla grafu reprezentowanego za pomoca listy sasiedztwa
    void wyswietlMST(int* parent, int V, const ListaSasiedstwa& graf);
};

#endif
