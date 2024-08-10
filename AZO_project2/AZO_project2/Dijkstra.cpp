#include "Dijkstra.h"
#include <iostream>
#include <climits>
#include <list>
#include <utility>


using namespace std;

// Implementacja algorytmu Dijkstry dla reprezentacji grafu za pomoca macierzy incydencji
void Dijkstra::znajdzNajkrotszaSciezke(MacierzIncydencji& graf, int start) {
    int V = graf.getLiczbaWierzcholkow(); // Liczba wierzcholkow
    int E = graf.getLiczbaKrawedzi(); // Liczba krawedzi
    int* odleglosci = new int[V]; // Tablica odleglosci
    bool* sptSet = new bool[V]; // Tablica sptSet, ktora przechowuje informacje o tym, czy wierzcholek zostal juz odwiedzony
    int* parent = new int[V]; // Tablica rodzicow

    // Inicjalizacja odleglosci i rodzicow
    for (int i = 0; i < V; i++) {
        odleglosci[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    odleglosci[start] = 0;
    int** macierz = graf.getMacierz(); // Pobranie macierzy incydencji

    // Petla iterujaca po wszystkich wierzcholkach
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(odleglosci, sptSet, V); // Znajdowanie wierzcholka o minimalnej odleglosci
        sptSet[u] = true; // Zaznacz wierzcholek jako odwiedzony

        // Aktualizowanie wartosci odleglosci dla sasiadow wybranego wierzcholka
        for (int j = 0; j < E; j++) {
            if (macierz[u][j] > 0) {  // Tylko dodatnie wartosci sa prawidlowymi krawedziami
                int v = -1;
                int waga = macierz[u][j];
                for (int i = 0; i < V; i++) {
                    if (macierz[i][j] == -macierz[u][j]) {  // Znajdz wierzcholek koncowy
                        v = i;
                        break;
                    }
                }
                // Aktualizacja odleglosci i rodzica, jezeli znaleziono krotsza sciezke
                if (v != -1 && !sptSet[v] && odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
                    parent[v] = u;
                    odleglosci[v] = odleglosci[u] + waga;
                }
            }
        }
    }

    wyswietlSciezke(odleglosci, parent, V, start);

    delete[] odleglosci;
    delete[] sptSet;
    delete[] parent;
}

// Implementacja algorytmu Dijkstry dla znalezienia najkrotszej sciezki do celu
void Dijkstra::znajdzNajkrotszaSciezkeDoCel(MacierzIncydencji& graf, int start, int cel) {
    int V = graf.getLiczbaWierzcholkow();
    int E = graf.getLiczbaKrawedzi();
    int* odleglosci = new int[V];
    bool* sptSet = new bool[V];
    int* parent = new int[V];

    // Inicjalizacja odleglosci i rodzicow
    for (int i = 0; i < V; i++) {
        odleglosci[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    odleglosci[start] = 0;
    int** macierz = graf.getMacierz(); // Pobranie macierzy incydencji

    // Petla iterujaca po wszystkich wierzcholkach
    for (int count = 0; count < V; count++) {
        int u = minDistance(odleglosci, sptSet, V); // Znajdowanie wierzcholka o minimalnej odleglosci
        if (u == -1) break;  // Wszystkie wierzcholki sa juz odwiedzone
        sptSet[u] = true; // Zaznacz wierzcholek jako odwiedzony

        if (u == cel) break;  // Przerywamy petle, gdy znajdziemy cel

        // Aktualizowanie wartosci odleglosci dla sasiadow wybranego wierzcholka
        for (int j = 0; j < E; j++) {
            if (macierz[u][j] > 0) {  // Tylko dodatnie wartosci sa prawidlowymi krawedziami
                int v = -1;
                int waga = macierz[u][j];
                for (int i = 0; i < V; i++) {
                    if (macierz[i][j] == -macierz[u][j]) {  // Znajdz wierzcholek koncowy
                        v = i;
                        break;
                    }
                }
                // Aktualizacja odleglosci i rodzica, jezeli znaleziono krotsza sciezke
                if (v != -1 && !sptSet[v] && odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
                    parent[v] = u;
                    odleglosci[v] = odleglosci[u] + waga;
                }
            }
        }
    }

    // Wyswietlenie sciezki do celu
    if (odleglosci[cel] == INT_MAX) {
        cout << "Nie ma dostepnej sciezki z " << start << " do " << cel << "." << endl;
    }
    else {
        cout << "Wierzcholek \tOdleglosc od " << start << "\tSciezka" << endl;
        cout << cel << " \t\t " << odleglosci[cel] << "\t\t";
        printPath(parent, cel);
        cout << endl;
    }

    delete[] odleglosci;
    delete[] sptSet;
    delete[] parent;
}

// Implementacja algorytmu Dijkstry dla reprezentacji grafu za pomoca listy sasiedztwa
void Dijkstra::znajdzNajkrotszaSciezke(ListaSasiedstwa& graf, int start) {
    int V = graf.getLiczbaWierzcholkow();
    int* odleglosci = new int[V];
    bool* sptSet = new bool[V];
    int* parent = new int[V];

    // Inicjalizacja odleglosci i rodzicow
    for (int i = 0; i < V; i++) {
        odleglosci[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    odleglosci[start] = 0;

    // Petla iterujaca po wszystkich wierzcholkach
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(odleglosci, sptSet, V); // Znajdowanie wierzcholka o minimalnej odleglosci
        sptSet[u] = true; // Zaznacz wierzcholek jako odwiedzony

        // Aktualizowanie wartosci odleglosci dla sasiadow wybranego wierzcholka
        const list<pair<int, int>>& sasiedzi = graf.getSasiedzi(u);
        for (const auto& sasiad : sasiedzi) {
            int v = sasiad.first;
            int waga = sasiad.second;
            if (waga > 0 && !sptSet[v] && odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
                parent[v] = u;
                odleglosci[v] = odleglosci[u] + waga;
            }
        }
    }

    wyswietlSciezke(odleglosci, parent, V, start);

    delete[] odleglosci;
    delete[] sptSet;
    delete[] parent;
}

// Implementacja algorytmu Dijkstry dla znalezienia najkrotszej sciezki do celu
void Dijkstra::znajdzNajkrotszaSciezkeDoCel(ListaSasiedstwa& graf, int start, int cel) {
    int V = graf.getLiczbaWierzcholkow();
    int* odleglosci = new int[V];
    bool* sptSet = new bool[V];
    int* parent = new int[V];

    // Inicjalizacja odleglosci i rodzicow
    for (int i = 0; i < V; i++) {
        odleglosci[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    odleglosci[start] = 0;

    // Petla iterujaca po wszystkich wierzcholkach
    for (int count = 0; count < V; count++) {
        int u = minDistance(odleglosci, sptSet, V);
        if (u == -1) break;  // Wszystkie wierzcholki sa juz odwiedzone
        sptSet[u] = true; // Zaznacz wierzcholek jako odwiedzony

        if (u == cel) break;  // Przerywamy petle, gdy znajdziemy cel

        // Aktualizowanie wartosci odleglosci dla sasiadow wybranego wierzcholka
        const list<pair<int, int>>& sasiedzi = graf.getSasiedzi(u);
        for (const auto& sasiad : sasiedzi) {
            int v = sasiad.first;
            int waga = sasiad.second;
            if (!sptSet[v] && odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
                parent[v] = u;
                odleglosci[v] = odleglosci[u] + waga;
            }
        }
    }

    // Wyswietlenie sciezki do celu
    if (odleglosci[cel] == INT_MAX) {
        cout << "Nie ma dostepnej sciezki z " << start << " do " << cel << "." << endl;
    }
    else {
        cout << "Wierzcholek \tOdleglosc od " << start << "\tSciezka" << endl;
        cout << cel << " \t\t " << odleglosci[cel] << "\t\t";
        printPath(parent, cel);
        cout << endl;
    }

    delete[] odleglosci;
    delete[] sptSet;
    delete[] parent;
}

// Funkcja wyswietlajaca najkrotsza sciezke
void Dijkstra::wyswietlSciezke(int odleglosci[], int parent[], int V, int start) {
    cout << "Wierzcholek \tOdleglosc od " << start << "\tSciezka" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << odleglosci[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

// Funkcja rekurencyjna wyswietlajaca sciezke z wierzcholka startowego do wierzcholka v
void Dijkstra::printPath(int parent[], int v) {
    if (parent[v] == -1) {
        cout << v;
        return;
    }
    printPath(parent, parent[v]);
    cout << " -> " << v;
}

// Funkcja znajdujaca wierzcholek o minimalnej odleglosci, ktory nie zostal jeszcze odwiedzony
int Dijkstra::minDistance(int odleglosci[], bool sptSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && odleglosci[v] < min) {
            min = odleglosci[v];
            min_index = v;
        }
    }

    return min_index;
}

