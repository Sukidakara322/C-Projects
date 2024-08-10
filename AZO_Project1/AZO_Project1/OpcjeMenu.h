#ifndef OPCJEMENU_H
#define OPCJEMENU_H

class OpcjeMenu {
public:
	static void wyswietlMenuGlowne();
	static void wczytajTabeleZPliku(int*& tabela, int& liczba_elementow);
	static void wczytajTabeleZPlikuFloat(float*& tabela, int& liczba_elementow);
	static void generujTabeleLosowo(int*& tabela, int liczba_elementow);
	static void generujTabeleLosowoFloat(float*& tabela, int liczba_elementow);
	static void generujTabeleRosnaco(int*& tabela, int liczba_elementow);
	static void generujTabeleRosnacoFloat(float*& tabela, int liczba_elementow);
	static void generujTabeleMalejaco(int*& tabela, int liczba_elementow);
	static void generujTabeleMalejacoFloat(float*& tabela, int liczba_elementow);
	static void generujTabele33Posortowana(int*& tabela, int liczba_elementow);
	static void generujTabele33PosortowanaFloat(float*& tabela, int liczba_elementow);
	static void generujTabele66Posortowana(int*& tabela, int liczba_elementow);
	static void generujTabele66PosortowanaFloat(float*& tabela, int liczba_elementow);
	static void wyswietlOstatnioUzywanaTabele(int* tabela, int liczba_elementow);
	static void wyswietlOstatnioUzywanaTabeleFloat(float* tabela, int liczba_elementow);
	static bool sortujTabele(int* tabela, int liczba_elementow);
	static bool sortujTabeleFloat(float* tabela, int liczba_elementow);
};

#endif
