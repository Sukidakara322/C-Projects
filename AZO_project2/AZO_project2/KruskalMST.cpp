#include "KruskalMST.h"
#include <iostream>
#include <utility>

using namespace std;

// Znajdowanie przedstawiciela zbioru elementu i
int KruskalMST::find(int i, int* parent) {
    // Uzywamy kompresji sciezki, aby zoptymalizowac strukture
    while (parent[i] != i) {
        parent[i] = parent[parent[i]]; // Kompresja sciezki
        i = parent[i];
    }
    return i;
}

// Funkcja laczaca dwa zbiory
void KruskalMST::union1(int i, int j, int* parent) {
    int a = find(i, parent);
    int b = find(j, parent);
    parent[a] = b;
}

// Funkcja pomocnicza do scalania podtablic
void merge(Krawedz* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Krawedz* L = new Krawedz[n1];
    Krawedz* R = new Krawedz[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].waga <= R[j].waga) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Funkcja realizujaca algorytm sortowania przez kopcowanie
void mergeSort(Krawedz* arr, int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void KruskalMST::znajdzMST(MacierzIncydencji& graf) {
    int V = graf.getLiczbaWierzcholkow();
    int E = graf.getLiczbaKrawedzi();
    int** macierz = graf.getMacierz();

    Krawedz* krawedzie = new Krawedz[E];
    int k = 0;

    // Zbieranie krawedzi z macierzy incydencji
    for (int j = 0; j < E; j++) {
        int start = -1, koniec = -1, waga = 0;
        for (int i = 0; i < V; i++) {
            if (macierz[i][j] != 0) {
                if (start == -1) {
                    start = i;
                    waga = macierz[i][j];  // Pobierz wage krawedzi
                }
                else {
                    koniec = i;
                    break;
                }
            }
        }
        if (start != -1 && koniec != -1) {
            krawedzie[k++] = { start, koniec, abs(waga) };
        }
    }

    // Sortowanie krawedzi
    mergeSort(krawedzie, 0, k - 1);

    int* parent = new int[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    Krawedz* mst = new Krawedz[V - 1];
    int e = 0, totalCost = 0;
    for (int i = 0; i < k && e < V - 1; i++) {
        int u = find(krawedzie[i].start, parent);
        int v = find(krawedzie[i].koniec, parent);
        if (u != v) {
            mst[e++] = krawedzie[i];
            union1(u, v, parent);
            totalCost += krawedzie[i].waga;
        }
    }

    wyswietlMST(mst, e, totalCost);

    delete[] parent;
    delete[] mst;
    delete[] krawedzie;
}

void KruskalMST::znajdzMST(ListaSasiedstwa& graf) {
    int V = graf.getLiczbaWierzcholkow();
    Krawedz* krawedzie = new Krawedz[V * (V - 1) / 2];
    int k = 0;
    for (int i = 0; i < V; i++) {
        auto& sasiedzi = graf.getSasiedzi(i);
        for (const auto& sasiad : sasiedzi) {
            if (i < sasiad.first) {
                krawedzie[k].start = i;
                krawedzie[k].koniec = sasiad.first;
                krawedzie[k].waga = sasiad.second;
                k++;
            }
        }
    }
    mergeSort(krawedzie, 0, k - 1);

    int* parent = new int[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    Krawedz* mst = new Krawedz[V - 1];
    int e = 0;
    int totalCost = 0;
    for (int i = 0; i < k && e < V - 1; i++) {
        int u = find(krawedzie[i].start, parent);
        int v = find(krawedzie[i].koniec, parent);
        if (u != v) {
            mst[e++] = krawedzie[i];
            totalCost += krawedzie[i].waga;
            union1(u, v, parent);
        }
    }
    wyswietlMST(mst, e, totalCost);

    delete[] parent;
    delete[] mst;
    delete[] krawedzie;
}

void KruskalMST::wyswietlMST(Krawedz* mst, int n, int totalCost) {
    cout << "Krawedz \tWaga\n";
    for (int i = 0; i < n; i++) {
        cout << mst[i].start << " - " << mst[i].koniec << " \t" << mst[i].waga << "\n";
    }
    cout << "Calkowity koszt MST: " << totalCost << endl;
}