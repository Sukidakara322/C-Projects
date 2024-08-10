#include "TestMode.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include "MacierzIncydencji.h"
#include "ListaSasiedstwa.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "PrimMST.h"
#include "KruskalMST.h"
#include "GrafLoader.h"

using namespace std;
using namespace std::chrono;

void TestMode::runTests(const int* liczbyWierzcholkow, int liczbaWierzcholkowCount, const double* gestosciGrafu, int gestosciGrafuCount, const std::string& outputFile) {
    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cerr << "Nie mozna otworzyc pliku do zapisu: " << outputFile << endl;
        return;
    }

    for (int j = 0; j < gestosciGrafuCount; ++j) {
        outFile << "Gestosc: " << gestosciGrafu[j] << endl;
        for (int i = 0; i < liczbaWierzcholkowCount; ++i) {
            outFile << "Liczba wierzcholkow: " << liczbyWierzcholkow[i] << endl;

            double totalDijkstraMI = 0, totalDijkstraLS = 0;
            double totalBellmanMI = 0, totalBellmanLS = 0;
            double totalPrimMI = 0, totalPrimLS = 0;
            double totalKruskalMI = 0, totalKruskalLS = 0;

            for (int k = 0; k < 25; ++k) {
                testAlgorithms(liczbyWierzcholkow[i], gestosciGrafu[j], totalDijkstraMI, totalDijkstraLS, totalBellmanMI, totalBellmanLS, totalPrimMI, totalPrimLS, totalKruskalMI, totalKruskalLS);
            }

            logResults("Dijkstra (Macierz Incydencji)", totalDijkstraMI / 25, outFile);
            logResults("Dijkstra (Lista Sasiedstwa)", totalDijkstraLS / 25, outFile);
            logResults("Bellman-Ford (Macierz Incydencji)", totalBellmanMI / 25, outFile);
            logResults("Bellman-Ford (Lista Sasiedztwa)", totalBellmanLS / 25, outFile);
            logResults("Prim (Macierz Incydencji)", totalPrimMI / 25, outFile);
            logResults("Prim (Lista Sasiedztwa)", totalPrimLS / 25, outFile);
            logResults("Kruskal (Macierz Incydencji)", totalKruskalMI / 25, outFile);
            logResults("Kruskal (Lista Sasiedztwa)", totalKruskalLS / 25, outFile);

            outFile << endl;
        }
        outFile << endl;
    }

    outFile.close();
}

void TestMode::testAlgorithms(int liczbaWierzcholkow, double gestosc, double& dijkstraMI, double& dijkstraLS, double& bellmanMI, double& bellmanLS, double& primMI, double& primLS, double& kruskalMI, double& kruskalLS) {
    MacierzIncydencji macierzGraf(liczbaWierzcholkow, liczbaWierzcholkow * (liczbaWierzcholkow - 1) / 2);
    MacierzIncydencji macierzGrafSkierowany(liczbaWierzcholkow, liczbaWierzcholkow * (liczbaWierzcholkow - 1) / 2);
    ListaSasiedstwa listaGraf(liczbaWierzcholkow);
    ListaSasiedstwa listaGrafSkierowany(liczbaWierzcholkow);

    // Generowanie losowego grafu
    GrafLoader::generujLosowyGraf(macierzGraf, macierzGrafSkierowany, liczbaWierzcholkow, gestosc);
    GrafLoader::generujLosowyGraf(listaGraf, listaGrafSkierowany, liczbaWierzcholkow, gestosc);

    // Testowanie algorytmu Dijkstra
    Dijkstra dijkstra;
    auto start = high_resolution_clock::now();
    dijkstra.znajdzNajkrotszaSciezke(macierzGrafSkierowany, 0);
    auto stop = high_resolution_clock::now();
    dijkstraMI += duration_cast<milliseconds>(stop - start).count();

    start = high_resolution_clock::now();
    dijkstra.znajdzNajkrotszaSciezke(listaGrafSkierowany, 0);
    stop = high_resolution_clock::now();
    dijkstraLS += duration_cast<milliseconds>(stop - start).count();

    // Testowanie algorytmu Bellman-Ford
    BellmanFord bellmanFord;
    start = high_resolution_clock::now();
    bellmanFord.znajdzNajkrotszaSciezke(macierzGrafSkierowany, 0);
    stop = high_resolution_clock::now();
    bellmanMI += duration_cast<milliseconds>(stop - start).count();

    start = high_resolution_clock::now();
    bellmanFord.znajdzNajkrotszaSciezke(listaGrafSkierowany, 0);
    stop = high_resolution_clock::now();
    bellmanLS += duration_cast<milliseconds>(stop - start).count();

    // Testowanie algorytmu Prim
    PrimMST prim;
    start = high_resolution_clock::now();
    prim.znajdzMST(macierzGraf);
    stop = high_resolution_clock::now();
    primMI += duration_cast<milliseconds>(stop - start).count();

    start = high_resolution_clock::now();
    prim.znajdzMST(listaGraf);
    stop = high_resolution_clock::now();
    primLS += duration_cast<milliseconds>(stop - start).count();

    // Testowanie algorytmu Kruskal
    KruskalMST kruskal;
    start = high_resolution_clock::now();
    kruskal.znajdzMST(macierzGraf);
    stop = high_resolution_clock::now();
    kruskalMI += duration_cast<milliseconds>(stop - start).count();

    start = high_resolution_clock::now();
    kruskal.znajdzMST(listaGraf);
    stop = high_resolution_clock::now();
    kruskalLS += duration_cast<milliseconds>(stop - start).count();
}

void TestMode::logResults(const std::string& algorithmName, double duration, ofstream& outFile) {
    outFile << algorithmName << ": " << duration << " ms" << endl;
}
