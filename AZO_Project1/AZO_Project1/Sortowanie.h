#include <chrono>
#ifndef SORTOWANIE_H
#define SORTOWANIE_H

class Sortowanie {
public:
    static void wyswietlicTabela(int tabela[], int rozmiar);
    static void wyswietlicTabelaFloat(float tabela[], int rozmiar);
    static void sortowanie_przez_wstawianie(int tabela[], int rozmiar, double& czas_sortowania);
    static void sortowanie_float_przez_wstawianie(float tabela[], int rozmiar, double& czas_sortowania);
    static void sortowanie_przez_kopcowanie(int tabela[], int rozmiar, double& czas_sortowania);
    static void sortowanie_binarne_przez_wstawianie(int tabela[], int rozmiar, double& czas_sortowania);
    static void sortowanie_szybkie_pomiar_czasu(int tabela[], int rozmiar, int pivot_option, double& czas_sortowania);
    static void sortowanie_szybkie(int tabela[], int lewy, int prawy, int pivot_option);
    static void ShellaSortSedgewick(int tabela[], int n, double& czas_sortowania);
    static void ShellaSortHibbard(int tabela[], int n, double& czas_sortowania);
private:
    static void heapify(int tabela[], int rozmiar, int i);
    static int binarne_wyszukiwanie(int tabela[], int rzecz, int niski, int wysoki);
    static int wyborPivota(int tabela[], int lewy, int prawy, int pivot_option);
    static int partycjonowanie(int tabela[], int lewy, int prawy, int pivot_option);
};

#endif
