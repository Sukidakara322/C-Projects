#include "BellmanFord.h"
#include <iostream>
#include <climits>
#include <utility>

using namespace std;

// Struktura reprezentujaca krawedz w grafie 
struct Krawedz {
    int start, koniec, waga;
};

// Implementacja algorytmu Bellmana-Forda dla reprezentacji grafu za pomoca macierzy incydencji
void BellmanFord::znajdzNajkrotszaSciezke(MacierzIncydencji& graf, int start) {
    int V = graf.getLiczbaWierzcholkow(); // Liczba wierzcholkow
    int E = graf.getLiczbaKrawedzi(); // Liczba krawedzi
    int* odleglosci = new int[V]; // Tablica odleglosci
    int* parent = new int[V]; // Tablica rodzicow

    // Inicjalizacja odleglosci i rodzicow
    for (int i = 0; i < V; i++) {
        odleglosci[i] = INT_MAX;
        parent[i] = -1;
    }
    odleglosci[start] = 0;

    int** macierz = graf.getMacierz(); // Pobranie macierzy incydencji
    Krawedz* krawedzie = new Krawedz[E]; // Tablica krawedzi
    int k = 0;

    // Tworzenie listy krawedzi na podstawie macierzy incydencji
    for (int j = 0; j < E; j++) {
        int u = -1, v = -1;
        int waga = 0;
        for (int i = 0; i < V; i++) {
            if (macierz[i][j] > 0) {
                u = i;
                waga = macierz[i][j];
            }
            else if (macierz[i][j] < 0) {
                v = i;
            }
        }
        if (u != -1 && v != -1) {
            krawedzie[k].start = u;
            krawedzie[k].koniec = v;
            krawedzie[k].waga = waga;
            k++;
        }
    }

    // Relaksacja krawedzi
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < k; j++) {
            int u = krawedzie[j].start;
            int v = krawedzie[j].koniec;
            int waga = krawedzie[j].waga;
            if (odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
                odleglosci[v] = odleglosci[u] + waga;
                parent[v] = u;
            }
        }
    }

    // Sprawdzanie cykli o ujemnej wadze
    for (int j = 0; j < k; j++) {
        int u = krawedzie[j].start;
        int v = krawedzie[j].koniec;
        int waga = krawedzie[j].waga;
        if (odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
            cout << "Graf zawiera cykl o ujemnej wadze!" << endl;
            delete[] odleglosci;
            delete[] parent;
            delete[] krawedzie;
            return;
        }
    }

    // Wyswietlenie najkrotszej sciezki
    wyswietlSciezke(odleglosci, parent, V, start);

    delete[] odleglosci;
    delete[] parent;
    delete[] krawedzie;
}

// Implementacja algorytmu Bellmana-Forda dla znalezienia najkrotszej sciezki do celu
void BellmanFord::znajdzNajkrotszaSciezkeDoCel(MacierzIncydencji& graf, int start, int cel) {
    int V = graf.getLiczbaWierzcholkow();
    int E = graf.getLiczbaKrawedzi();
    int* odleglosci = new int[V];
    int* parent = new int[V];
    Krawedz* krawedzie = new Krawedz[E];

    // Inicjalizacja odleglosci i rodzicow
    for (int i = 0; i < V; i++) {
        odleglosci[i] = INT_MAX;
        parent[i] = -1;
    }
    odleglosci[start] = 0;

    int k = 0;
    int** macierz = graf.getMacierz();
    // Tworzenie listy krawedzi na podstawie macierzy incydencji
    for (int j = 0; j < E; j++) {
        int start = -1, koniec = -1, waga = 0;
        for (int i = 0; i < V; i++) {
            if (macierz[i][j] != 0) {
                if (start == -1) {
                    start = i;
                    waga = macierz[i][j];
                }
                else {
                    koniec = i;
                }
            }
        }
        if (start != -1 && koniec != -1 && waga > 0) {
            krawedzie[k].start = start;
            krawedzie[k].koniec = koniec;
            krawedzie[k].waga = waga;
            k++;
        }
    }

    // Relaksacja krawedzi
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < k; j++) {
            int u = krawedzie[j].start;
            int v = krawedzie[j].koniec;
            int waga = krawedzie[j].waga;
            if (odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
                odleglosci[v] = odleglosci[u] + waga;
                parent[v] = u;
            }
        }
    }

    // Sprawdzanie cykli o ujemnej wadze
    for (int j = 0; j < k; j++) {
        int u = krawedzie[j].start;
        int v = krawedzie[j].koniec;
        int waga = krawedzie[j].waga;
        if (odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
            cout << "Graf zawiera cykl o ujemnej wadze!" << endl;
            delete[] odleglosci;
            delete[] parent;
            delete[] krawedzie;
            return;
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
    delete[] parent;
    delete[] krawedzie;
}

// Implementacja algorytmu Bellmana-Forda dla reprezentacji grafu za pomoca listy sasiedztwa
void BellmanFord::znajdzNajkrotszaSciezke(ListaSasiedstwa& graf, int start) {
    int V = graf.getLiczbaWierzcholkow();
    int* odleglosci = new int[V];
    int* parent = new int[V];

    // Inicjalizacja odleglosci i rodzicow
    for (int i = 0; i < V; i++) {
        odleglosci[i] = INT_MAX;
        parent[i] = -1;
    }
    odleglosci[start] = 0;

    // Tworzenie listy krawedzi na podstawie listy sasiedztwa
    list<Krawedz> krawedzie;
    for (int u = 0; u < V; u++) {
        const auto& sasiedzi = graf.getSasiedzi(u);
        for (const auto& sasiad : sasiedzi) {
            if (sasiad.second > 0) {  // Uwzglednij tylko skierowane krawedzie
                krawedzie.push_back({ u, sasiad.first, sasiad.second });
            }
        }
    }

    // Relaksacja krawedzi
    for (int i = 1; i < V; i++) {
        for (const auto& krawedz : krawedzie) {
            int u = krawedz.start;
            int v = krawedz.koniec;
            int waga = krawedz.waga;
            if (odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
                odleglosci[v] = odleglosci[u] + waga;
                parent[v] = u;
            }
        }
    }

    // Sprawdzanie cykli o ujemnej wadze
    for (const auto& krawedz : krawedzie) {
        int u = krawedz.start;
        int v = krawedz.koniec;
        int waga = krawedz.waga;
        if (odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
            cout << "Graf zawiera cykl o ujemnej wadze!" << endl;
            delete[] odleglosci;
            delete[] parent;
            return;
        }
    }
    // Wyswietlenie najkrotszej sciezki
    wyswietlSciezke(odleglosci, parent, V, start);

    delete[] odleglosci;
    delete[] parent;
}

// Implementacja algorytmu Bellmana-Forda dla znalezienia najkrotszej sciezki do celu
void BellmanFord::znajdzNajkrotszaSciezkeDoCel(ListaSasiedstwa& graf, int start, int cel) {
    int V = graf.getLiczbaWierzcholkow();
    int* odleglosci = new int[V];
    int* parent = new int[V];

    // Inicjalizacja odleglosci i rodzicow
    for (int i = 0; i < V; i++) {
        odleglosci[i] = INT_MAX;
        parent[i] = -1;
    }
    odleglosci[start] = 0;

    // Tworzenie listy krawedzi na podstawie listy sasiedztwa
    list<Krawedz> krawedzie;
    for (int u = 0; u < V; u++) {
        const auto& sasiedzi = graf.getSasiedzi(u);
        for (const auto& sasiad : sasiedzi) {
            if (sasiad.second > 0) {  // Uwzglednienie tylko skierowanych krawedzie
                krawedzie.push_back({ u, sasiad.first, sasiad.second });
            }
        }
    }

    // Relaksacja krawedzi
    for (int i = 1; i < V; i++) {
        for (const auto& krawedz : krawedzie) {
            int u = krawedz.start;
            int v = krawedz.koniec;
            int waga = krawedz.waga;
            if (odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
                odleglosci[v] = odleglosci[u] + waga;
                parent[v] = u;
            }
        }
    }

    // Sprawdzanie cykli o ujemnej wadze
    for (const auto& krawedz : krawedzie) {
        int u = krawedz.start;
        int v = krawedz.koniec;
        int waga = krawedz.waga;
        if (odleglosci[u] != INT_MAX && odleglosci[u] + waga < odleglosci[v]) {
            cout << "Graf zawiera cykl o ujemnej wadze!" << endl;
            delete[] odleglosci;
            delete[] parent;
            return;
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
    delete[] parent;
}

// Funkcja wyswietlajaca najkrotsza sciezke
void BellmanFord::wyswietlSciezke(int odleglosci[], int parent[], int V, int start) {
    cout << "Wierzcholek \tOdleglosc od " << start << "\tSciezka" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << odleglosci[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

// Funkcja rekurencyjna wyswietlajaca sciezke z wierzcholka startowego do wierzcholka v
void BellmanFord::printPath(int parent[], int v) {
    if (parent[v] == -1) {
        cout << v;
        return;
    }
    printPath(parent, parent[v]);
    cout << " -> " << v;
}
