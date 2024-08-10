#ifndef MACIERZINCYDENCJI_H
#define MACIERZINCYDENCJI_H

class MacierzIncydencji {
private:
    // Liczba wierzcholkow w grafie
    int liczbaWierzcholkow;
    // Liczba krawedzi w grafie
    int liczbaKrawedzi;
    // Macierz incydencji
    int** macierz;

public:
    // Konstruktor klasy MacierzIncydencji
    MacierzIncydencji(int V, int E);

    // Metoda dodajaca krawedz do grafu
    void dodaj_krawedz(int poczatek, int koniec, int waga, bool nieskierowana);

    // Metoda wyswietlajaca macierz incydencji
    void wyswietl();

    // Metoda zwracajaca liczbe wierzcholkow w grafie
    int getLiczbaWierzcholkow() const;

    // Metoda zwracajaca liczbe krawedzi w grafie
    int getLiczbaKrawedzi() const;

    // Metoda zwracajaca macierz incydencji
    int** getMacierz() const;

    // Metoda zwracajaca macierz wag
    int** getWagi() const;

    // Metoda sprawdzajaca, czy istnieje krawedz pomiedzy dwoma wierzcholkami
    bool czyIstniejeKrawedz(int poczatek, int koniec) const;

    // Metoda sprawdzajaca, czy graf jest spojny
    bool czySpojny() const;

    // Metoda DFS do przeszukiwania grafu w glab
    void dfs(bool* odwiedzone, int wierzcholek) const;
};

#endif
