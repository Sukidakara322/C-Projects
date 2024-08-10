#ifndef GRAFLOADER_H
#define GRAFLOADER_H

#include <string>
#include "MacierzIncydencji.h"
#include "ListaSasiedstwa.h"

// Klasa GrafLoader odpowiedzialna za wczytywanie i generowanie grafow
class GrafLoader {
public:
    // Statyczna metoda do wczytywania grafu z pliku do macierzy incydencji
    static bool wczytajZPliku(const std::string& nazwaPliku, MacierzIncydencji& macierzGraf, MacierzIncydencji& macierzGraf_skierowany);

    // Statyczna metoda do wczytywania grafu z pliku do listy sasiedztwa
    static bool wczytajZPliku(const std::string& nazwaPliku, ListaSasiedstwa& listaGraf, ListaSasiedstwa& listaGraf_skierowany);

    // Statyczna metoda do generowania losowego grafu w reprezentacji macierzy incydencji
    static void generujLosowyGraf(MacierzIncydencji& macierzGraf, MacierzIncydencji& macierzGraf_skierowany, int liczbaWierzcholkow, double gestosc);

    // Statyczna metoda do generowania losowego grafu w reprezentacji listy sasiedztwa
    static void generujLosowyGraf(ListaSasiedstwa& listaGraf, ListaSasiedstwa& listaGraf_skierowany, int liczbaWierzcholkow, double gestosc);
};

#endif
