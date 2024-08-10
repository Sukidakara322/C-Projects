#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "MacierzIncydencji.h"
#include "ListaSasiedstwa.h"

// Deklaracja klasy BellmanFord, implementujacej algorytm Bellmana-Forda
class BellmanFord {
public:
    // Metoda do znajdowania najkrotszej sciezki od startowego wierzcholka do wszystkich pozostalych wierzcholkow
    void znajdzNajkrotszaSciezke(MacierzIncydencji& graf, int start);

    // Metoda do znajdowania najkrotszej sciezki od startowego wierzcholka do zadanego wierzcholka cel
    void znajdzNajkrotszaSciezkeDoCel(MacierzIncydencji& graf, int start, int cel);

    // Metoda do znajdowania najkrotszej sciezki od startowego wierzcholka do wszystkich pozostalych wierzcholkow
    // dla grafu reprezentowanego za pomoca listy sasiedztwa
    void znajdzNajkrotszaSciezke(ListaSasiedstwa& graf, int start);

    // Metoda do znajdowania najkrotszej sciezki od startowego wierzcholka do zadanego wierzcholka cel
    // dla grafu reprezentowanego za pomoca listy sasiedztwa
    void znajdzNajkrotszaSciezkeDoCel(ListaSasiedstwa& graf, int start, int cel);
private:

    // Prywatna metoda do wyswietlania najkrotszej sciezki od wierzcholka startowego do wszystkich pozostalych
    void wyswietlSciezke(int odleglosci[], int parent[], int V, int start);

    // Prywatna metoda do rekurencyjnego wyswietlania sciezki od wierzcholka startowego do wierzcholka v
    void printPath(int parent[], int v);
};

#endif
