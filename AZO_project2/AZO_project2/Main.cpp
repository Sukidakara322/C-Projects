#include <iostream>
#include <chrono>
#include "MacierzIncydencji.h"
#include "ListaSasiedstwa.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "PrimMST.h"
#include "KruskalMST.h"
#include "GrafLoader.h"
#include "TestMode.h"

using namespace std;
using namespace std::chrono;

// Funkcja do mierzenia czasu dzialania wybranych algorytmow
void zmierz_czas_dzialania(MacierzIncydencji& macierz_graf, ListaSasiedstwa& lista_graf, MacierzIncydencji& macierz_graf_skierowany, ListaSasiedstwa& lista_graf_skierowany, int algorytm) {
    switch (algorytm) {
    case 1: {
        PrimMST prim;
        auto start = high_resolution_clock::now();
        prim.znajdzMST(macierz_graf);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Czas dzialania Prim (Macierz Incydencji): " << duration.count() << " millisekund" << endl;

        start = high_resolution_clock::now();
        prim.znajdzMST(lista_graf);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Czas dzialania Prim (Lista Sasiedstwa): " << duration.count() << " millisekund" << endl;
        break;
    }
    case 2: {
        KruskalMST kruskal;
        auto start = high_resolution_clock::now();
        kruskal.znajdzMST(macierz_graf);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Czas dzialania Kruskal (Macierz Incydencji): " << duration.count() << " millisekund" << endl;

        start = high_resolution_clock::now();
        kruskal.znajdzMST(lista_graf);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Czas dzialania Kruskal (Lista Sasiedstwa): " << duration.count() << " millisekund" << endl;
        break;
    }
    case 3: {
        while (true) {
            int wybor;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "|                      Menu wprowadzenia                     |" << endl;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "| Wybierz jak chcesz uruchomic ten algorytm:                 |" << endl;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "| 1 - Sciezka do wszystkich wierzcholkow                     |" << endl;
            cout << "| 2 - Sciezka z wyborem poczatkowego i koncowego wierzcholka |" << endl;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "| 3 - Wyjscie do Menu Algorytmow                             |" << endl;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "Wybierz opcje: ";
            cin >> wybor;

            int start, koniec;
            high_resolution_clock::time_point start_time, stop_time;
            duration<double, milli> duration;
            switch (wybor) {
            case 1: {
                Dijkstra dijkstra;
                start_time = high_resolution_clock::now();
                dijkstra.znajdzNajkrotszaSciezke(macierz_graf_skierowany, 0);
                stop_time = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop_time - start_time);
                cout << "Czas dzialania Dijkstra (Macierz Incydencji): " << duration.count() << " millisekund" << endl;

                start_time = high_resolution_clock::now();
                dijkstra.znajdzNajkrotszaSciezke(lista_graf_skierowany, 0);
                stop_time = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop_time - start_time);
                cout << "Czas dzialania Dijkstra (Lista Sasiedstwa): " << duration.count() << " millisekund" << endl;
                break;
            }
            case 2: {
                cout << "Podaj wierzcholek poczatkowy: ";
                cin >> start;
                cout << "Podaj wierzcholek koncowy: ";
                cin >> koniec;
                Dijkstra dijkstra;
                start_time = high_resolution_clock::now();
                dijkstra.znajdzNajkrotszaSciezkeDoCel(macierz_graf_skierowany, start, koniec);
                stop_time = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop_time - start_time);
                cout << "Czas dzialania Dijkstra (Macierz Incydencji): " << duration.count() << " millisekund" << endl;

                start_time = high_resolution_clock::now();
                dijkstra.znajdzNajkrotszaSciezkeDoCel(lista_graf_skierowany, start, koniec);
                stop_time = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop_time - start_time);
                cout << "Czas dzialania Dijkstra (Lista Sasiedstwa): " << duration.count() << " millisekund" << endl;
                break;
            }
            case 3: {
                return;
            }
            default:
                cout << "Nieprawidlowy wybor" << endl;
                break;
            }
        }
        break;
    }
    case 4: {
        while (true) {
            int wybor;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "|                      Menu wprowadzenia                     |" << endl;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "| Wybierz jak chcesz uruchomic ten algorytm:                 |" << endl;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "| 1 - Sciezka do wszystkich wierzcholkow                     |" << endl;
            cout << "| 2 - Sciezka z wyborem poczatkowego i koncowego wierzcholka |" << endl;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "| 3 - Wyjscie do Menu Algorytmow                             |" << endl;
            cout << "|------------------------------------------------------------|" << endl;
            cout << "Wybierz opcje: ";
            cin >> wybor;

            int start, koniec;
            high_resolution_clock::time_point start_time, stop_time;
            duration<double, milli> duration;
            switch (wybor) {
            case 1: {
                BellmanFord bellmanford;
                start_time = high_resolution_clock::now();
                bellmanford.znajdzNajkrotszaSciezke(macierz_graf_skierowany, 0);
                stop_time = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop_time - start_time);
                cout << "Czas dzialania Bellmana Forda (Macierz Incydencji): " << duration.count() << " millisekund" << endl;

                start_time = high_resolution_clock::now();
                bellmanford.znajdzNajkrotszaSciezke(lista_graf_skierowany, 0);
                stop_time = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop_time - start_time);
                cout << "Czas dzialania Bellmana Forda (Lista Sasiedstwa): " << duration.count() << " millisekund" << endl;
                break;
            }
            case 2: {
                cout << "Podaj wierzcholek poczatkowy: ";
                cin >> start;
                cout << "Podaj wierzcholek koncowy: ";
                cin >> koniec;
                BellmanFord bellmanford;
                start_time = high_resolution_clock::now();
                bellmanford.znajdzNajkrotszaSciezkeDoCel(macierz_graf_skierowany, start, koniec);
                stop_time = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop_time - start_time);
                cout << "Czas dzialania Bellmana Forda (Macierz Incydencji): " << duration.count() << " millisekund" << endl;

                start_time = high_resolution_clock::now();
                bellmanford.znajdzNajkrotszaSciezkeDoCel(lista_graf_skierowany, start, koniec);
                stop_time = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop_time - start_time);
                cout << "Czas dzialania Bellmana Forda (Lista Sasiedstwa): " << duration.count() << " millisekund" << endl;
                break;
            }
            case 3: {
                return;
            }
            default:
                cout << "Nieprawidlowy wybor" << endl;
                break;
            }
        }
        break;
    }
    case 5: {
        break;
    }
    default:
        cout << "Nieprawidlowy wybor" << endl;
        break;
    }
}

// Funkcja wyswietlajaca menu glowne
void wyswietl_menu_glowne() {
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "|                              Menu Glowne                            |" << endl;
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "| 1 - Wczytanie grafu z pliku                                         |" << endl;
    cout << "| 2 - Generowanie losowego grafu                                      |" << endl;
    cout << "| 3 - Wyswietlenie ostatnio uzywanego grafu (nieskierowane krawedzi)  |" << endl;
    cout << "| 4 - Wyswietlenie ostatnio uzywanego grafu (skierowane krawedzi)     |" << endl;
    cout << "| 5 - Uruchomianie algorytmow                                         |" << endl;
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "| 6 - Koniec programu                                                 |" << endl;
    cout << "|---------------------------------------------------------------------|" << endl;
    cout << "Wybierz opcje: ";
}

// Funkcja wyswietlajaca menu wyboru algorytmow
void wyswietl_menu_algorytmy() {
    cout << "|----------------------------------------------|" << endl;
    cout << "|               Menu Algorytmow                |" << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "| 1 - Algorytm Prima                           |" << endl;
    cout << "| 2 - Algorytm Kruskala                        |" << endl;
    cout << "| 3 - Algorytm Dijkstra                        |" << endl;
    cout << "| 4 - Algorytm Bellmana - Forda                |" << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "| 5 - koniec dzialania                         |" << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "Wybierz algorytm: ";
}

int main() {
    cout << "AiZO Projekt 2 - Aliaksandr Afanasyeu 273018" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "|           Menu Trybu Pracy         |" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "| 1 - Tryb Symulacji                 |" << endl;
    cout << "| 2 - Tryb Testowania                |" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "Wybierz w jakim trybie uruchomic program: ";
    int opcje_trybu;
    cin >> opcje_trybu;

    if (opcje_trybu == 2) {
        const int liczbyWierzcholkow[] = { 10, 25, 50/*, 100, 200, 300, 450*/};
        const double gestosciGrafu[] = { 0.25, 0.50, 0.99 };
        TestMode testMode;
        testMode.runTests(liczbyWierzcholkow, 3, gestosciGrafu, 3, "wyniki.txt");
    }
    if (opcje_trybu == 1) {
        MacierzIncydencji* macierz_graf = new MacierzIncydencji(0, 0);
        MacierzIncydencji* macierz_graf_skierowany = new MacierzIncydencji(0, 0);
        ListaSasiedstwa* lista_graf = new ListaSasiedstwa(0);
        ListaSasiedstwa* lista_graf_skierowany = new ListaSasiedstwa(0);
        bool graf_wczytany = false;
        bool graf_spojny = false;

        while (true) {
            int opcja;
            wyswietl_menu_glowne();
            cin >> opcja;

            if (opcja == 6) {
                break;
            }

            switch (opcja) {
            case 1: {
                string nazwa_pliku;
                cout << "Wpisz nazwe pliku do wczytania: ";
                cin >> nazwa_pliku;
                graf_wczytany = GrafLoader::wczytajZPliku(nazwa_pliku, *macierz_graf, *macierz_graf_skierowany) && GrafLoader::wczytajZPliku(nazwa_pliku, *lista_graf, *lista_graf_skierowany);
                if (graf_wczytany) {
                    cout << "Graf zaladowany z pliku." << endl;
                    graf_spojny = macierz_graf->czySpojny() && lista_graf->czySpojny();
                    if (!graf_spojny) {
                        cout << "Uwaga: Graf nie jest spojny. Niektore algorytmy moga nie dzialac poprawnie." << endl;
                    }
                }
                else {
                    cout << "Blad ladowania grafu z pliku." << endl;
                }
                break;
            }
            case 2: {
                int liczba_wierzcholkow;
                double gestosc_procent;
                cout << "Podaj liczbe wierzcholkow: ";
                cin >> liczba_wierzcholkow;
                cout << "Podaj gestosc grafu (0 - 100%): ";
                cin >> gestosc_procent;
                double gestosc = gestosc_procent / 100.0;
                GrafLoader::generujLosowyGraf(*macierz_graf, *macierz_graf_skierowany, liczba_wierzcholkow, gestosc);
                GrafLoader::generujLosowyGraf(*lista_graf, *lista_graf_skierowany, liczba_wierzcholkow, gestosc);
                cout << "Losowo wygenerowany graf." << endl;
                graf_wczytany = true;
                graf_spojny = macierz_graf->czySpojny() && lista_graf->czySpojny();
                if (!graf_spojny) {
                    cout << "Uwaga: Graf nie jest spojny. Niektore algorytmy moga nie dzialac poprawnie." << endl;
                }
                break;
            }
            case 3: {
                if (graf_wczytany) {
                    cout << "Ostatnio uzywany graf (nieskierowane krawedzi)" << endl;
                    cout << "Postac Macierzy Incydencji: " << endl;
                    macierz_graf->wyswietl();
                    cout << "Postac Listy Sasiedstwa: " << endl;
                    lista_graf->wyswietl();
                }
                else {
                    cout << "Brak wczytanego grafu" << endl;
                }
                break;
            }
            case 4: {
                if (graf_wczytany) {
                    cout << "Ostatnio uzywany graf (skierowane krawedzi)" << endl;
                    cout << "Postac Macierzy Incydencji: " << endl;
                    macierz_graf_skierowany->wyswietl();
                    cout << "Postac Listy Sasiedstwa: " << endl;
                    lista_graf_skierowany->wyswietl();
                }
                else {
                    cout << "Brak wczytanego grafu" << endl;
                }
                break;
            }
            case 5: {
                if (graf_wczytany && graf_spojny) {
                    while (true) {
                        int algorytm;
                        wyswietl_menu_algorytmy();
                        cin >> algorytm;
                        if (algorytm == 5) {
                            break;
                        }
                        zmierz_czas_dzialania(*macierz_graf, *lista_graf, *macierz_graf_skierowany, *lista_graf_skierowany, algorytm);
                    }
                }
                else {
                    cout << "Nie mozna uruchomic algorytmow - graf nie jest wczytany lub nie jest spojny." << endl;
                }
                break;
            }
            default:
                cout << "Nieprawidlowy wybor" << endl;
                break;
            }
        }

        delete macierz_graf;
        delete lista_graf;
    }

    cout << "Koniec programu" << endl;
    return 0;
}
