// Aufgabe 05 Lottozahlen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Erzeugen sie eine Ziehung der Lottozahlen :
// 6 Lottozahlen(1 - 49) + Superzahl(0 - 9).
//
// Die Ziehung der Lottozahlen soll mit Hilfe des Zufallszahlengenerators
// srand((unsigned)time(NULL)) erfolgen.
//
// Speichern Sie die gezogenen Zahlen in einem geeigneten Array.
//
// Achten Sie bei der Ziehung der Zahlen auf Duplikate!
//
// Nach der Ziehung geben Sie die Lottozahlen aufsteigend sortiert
// aus.
//
// Weisen Sie die Superzahl separat aus.

#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::locale;

constexpr int ANZAHL_LOTTOZAHLEN = 6;
constexpr int MIN_LOTTOZAHL = 1;
constexpr int MAX_LOTTOZAHL = 49;
constexpr int MIN_SUPERZAHL = 0;
constexpr int MAX_SUPERZAHL = 9;

void druckenTitel();
void dieZiehung(int*);
int eineZahlZiehen(int*, int);
int nimmZufallszahl(int, int);
bool istDuplikat(int*, int, int);
void sortierung(int*);
int nimmMinFeld(int*, int);
void werteTauschen(int*, int, int);
void druckenAllerLottozahlen(int*);
char nimmSeparator(int);

int main()
{
	locale::global(locale("German_germany"));

	srand((unsigned)time(NULL));

	int lottozahlen[ANZAHL_LOTTOZAHLEN];

	druckenTitel();

	dieZiehung(lottozahlen);

	sortierung(lottozahlen);

	druckenAllerLottozahlen(lottozahlen);

	return EXIT_SUCCESS;
}

void druckenTitel()
{
	cout << endl << endl << ">> Die Ziehung der Lottozahlen <<" << endl << endl << endl;
}

void dieZiehung(int* lottozahlen)
{
	for (int ziehung = 0; ziehung < ANZAHL_LOTTOZAHLEN; ziehung++)
	{
		lottozahlen[ziehung] = eineZahlZiehen(lottozahlen, ziehung);

		cout << "Ziehung " << ziehung + 1 << ": " << lottozahlen[ziehung] << endl;
	}
}

int eineZahlZiehen(int* lottozahlen, int ziehung)
{
	while (true)
	{
		int zufallszahl = nimmZufallszahl(MIN_LOTTOZAHL, MAX_LOTTOZAHL);


		if (!istDuplikat(lottozahlen, ziehung, zufallszahl))
			return zufallszahl;
	}
}

int nimmZufallszahl(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

bool istDuplikat(int* lottozahlen, int ziehung, int zufallszahl)
{
	for (int j = 0; j < ziehung; j++)
	{
		if (lottozahlen[j] == zufallszahl)
			return true;
	}

	return false;
}

void sortierung(int* lottozahlen) {

	for (int i = 0; i < ANZAHL_LOTTOZAHLEN - 1; i++) {

		int min = nimmMinFeld(lottozahlen, i);

		if (min != i)
			werteTauschen(lottozahlen, i, min);
	}
}

int nimmMinFeld(int* lottozahlen, int aktuell)
{
	int min = aktuell;

	for (int j = aktuell + 1; j < ANZAHL_LOTTOZAHLEN; j++)
		if (lottozahlen[j] < lottozahlen[min])
			min = j;

	return min;
}

void werteTauschen(int* lottozahlen, int aktuell, int min)
{
	lottozahlen[aktuell] += lottozahlen[min];
	lottozahlen[min] = lottozahlen[aktuell] - lottozahlen[min];
	lottozahlen[aktuell] -= lottozahlen[min];
}

void druckenAllerLottozahlen(int* lottozahlen)
{
	cout << endl << "Die gezogenen Lottozahlen sind:";

	for (int i = 0; i < ANZAHL_LOTTOZAHLEN; i++)
		cout << " " << lottozahlen[i] << nimmSeparator(i);

	cout << endl << endl << "Die Superzahl ist: " << nimmZufallszahl(MIN_SUPERZAHL, MAX_SUPERZAHL) << endl;
}

char nimmSeparator(int aktuell)
{
	if (aktuell != ANZAHL_LOTTOZAHLEN - 1)
		return ',';

	return '.';
}