#include "PrimMST.h"
#include <iostream>
#include <climits>
#include <utility>

using namespace std;

// Funkcja implementujaca algorytm Prima dla grafu reprezentowanego za pomoca macierzy incydencji
void PrimMST::znajdzMST(MacierzIncydencji& graf) {
    int V = graf.getLiczbaWierzcholkow();
    int E = graf.getLiczbaKrawedzi();
    int* parent = new int[V];
    int* key = new int[V];
    bool* mstSet = new bool[V];
    int totalCost = 0; // Zmienna do przechowywania calkowitego kosztu MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;   // Inicjalizacja kluczy jako nieskonczonosci
        mstSet[i] = false;  // Poczatkowo zaden wierzcholek nie jest w MST
        parent[i] = -1;     // Rodzic kazdego wierzcholka to -1 (nie ma rodzica)
    }

    key[0] = 0;             // Start od pierwszego wierzcholka

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V); // Znajdz wierzcholek z najmniejszym kluczem
        mstSet[u] = true;               // Dodaj wierzcholek do MST

        // Przejrzyj wszystkie krawedzie wychodzace z u
        for (int j = 0; j < E; j++) {
            for (int v = 0; v < V; v++) {
                // Jesli krawedz istnieje i wierzcholek v nie jest w MST
                if (graf.getMacierz()[u][j] != 0 && graf.getMacierz()[v][j] != 0 && u != v) {
                    int waga = abs(graf.getMacierz()[u][j]);
                    if (waga < key[v] && !mstSet[v]) {
                        parent[v] = u;
                        key[v] = waga;
                    }
                }
            }
        }
    }
    // Sumowanie kosztow MST
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            totalCost += key[i];
        }
    }
    // Wyswietlenie wynikow
    wyswietlMST(parent, key, V);
    cout << "Calkowity koszt MST: " << totalCost << endl;

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

// Funkcja implementujaca algorytm Prima dla grafu reprezentowanego za pomoca listy sasiedztwa
void PrimMST::znajdzMST(ListaSasiedstwa& graf) {
    int V = graf.getLiczbaWierzcholkow();
    int* parent = new int[V];
    int* key = new int[V];
    bool* mstSet = new bool[V];
    int totalCost = 0; // Zmienna do przechowywania calkowitego kosztu MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        const auto& sasiedzi = graf.getSasiedzi(u);
        for (const auto& sasiedziPara : sasiedzi) {
            int v = sasiedziPara.first;
            int waga = sasiedziPara.second;
            if (!mstSet[v] && waga < key[v]) {
                parent[v] = u;
                key[v] = waga;
            }
        }
    }

    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            totalCost += key[i];
        }
    }

    wyswietlMST(parent, V, graf);
    cout << "Calkowity koszt MST: " << totalCost << endl;

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

void PrimMST::wyswietlMST(int* parent, int* key, int n) {
    cout << "Krawedz \tWaga\n";
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << "\t" << key[i] << endl;
    }
}

int PrimMST::minKey(int* key, bool* mstSet, int V) {
    // Znalezienie wierzcholka z najmniejszym kluczem, ktory nie jest jeszcze w MST
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

// Funkcja do wyswietlania MST dla listy sasiedztwa
void PrimMST::wyswietlMST(int* parent, int V, const ListaSasiedstwa& graf) {
    cout << "Krawedz \tWaga\n";
    for (int i = 1; i < V; i++) {
        const auto& sasiedzi = graf.getSasiedzi(parent[i]);
        for (const auto& sasiedziPara : sasiedzi) {
            if (sasiedziPara.first == i) {
                cout << parent[i] << " - " << i << " \t" << sasiedziPara.second << "\n";
                break;
            }
        }
    }
}