#ifndef LISTASASIEDSTWA_H
#define LISTASASIEDSTWA_H

#include <list>
#include <utility>

class ListaSasiedstwa {
public:
    // Konstruktor klasy ListaSasiedstwa
    explicit ListaSasiedstwa(int wierzcholki);

    // Metoda dodajaca krawedz do grafu
    void dodaj_krawedz(int poczatek, int koniec, int waga, bool nieskierowana);

    // Metoda wyswietlajaca liste sasiedztwa
    void wyswietl() const;

    // Metoda zwracajaca liczbe wierzcholkow w grafie
    int getLiczbaWierzcholkow() const;

    // Metoda zwracajaca sasiadow danego wierzcholka
    const std::list<std::pair<int, int>>& getSasiedzi(int wierzcholek) const;

    // Metoda sprawdzajaca, czy istnieje krawedz pomiedzy dwoma wierzcholkami
    bool czyIstniejeKrawedz(int poczatek, int koniec) const;

    // Metoda sprawdzajaca, czy graf jest spojny
    bool czySpojny() const;

    // Prywatna metoda DFS do przeszukiwania grafu w glab
    void dfs(bool* odwiedzone, int wierzcholek) const;

private:
    // Lista sasiedztwa reprezentujaca graf
    std::list<std::pair<int, int>>* listaSasiedztwa;
    // Liczba wierzcholkow w grafie
    int liczbaWierzcholkow;
};

#endif
