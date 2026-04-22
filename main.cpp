#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 
#include <random> 
using namespace std;

struct Osoba {
	string imie;
	string nazwisko;
	int wiek;
	int wzrost;
	int id;
};

const string bazaImion[7] = { "Marek", "Darek", "Kasia", "Basia", "Piotr", "Pawel", "Anna" };

const string bazaNazwisk[7] = { "Nowak", "Kowal", "Wojcik", "Mazur", "Zajac", "Krol", "Duda" };



// --- FUNKCJE GENERUJĄCE --- 

void generujImie(Osoba tab[], int index)
{

}



void generujReszte(Osoba tab[], int index, mt19937& gen)
{

}



int policzWysokich(Osoba tab[], int rozmiar)
{

}



int policzImionaNaA(Osoba tab[], int rozmiar)
{

}



double obliczSredniWiek(Osoba tab[], int rozmiar)
{

}



int znajdzMaxWzrost(Osoba tab[], int rozmiar)
{

}

int znajdzNajmlodszego(Osoba tab[], int rozmiar)
{

}



void generujWykresWieku(Osoba tab[], int rozmiar)
{

}

int main() {
	const int ROZMIAR = 100;
	Osoba ludnosc[ROZMIAR];

	srand(time(0));
	random_device rd;
	mt19937 gen(rd());

	for (int i = 0; i < ROZMIAR; i++) {

		generujImie(ludnosc, i);
		generujReszte(ludnosc, i, gen);
	}



	// Wyświetlanie statystyk 



	cout << "===== STATYSTYKI GRUPY 100 OSOB =====" << endl;
	
	cout << "A) Liczba osob powyzej 200cm: " << policzWysokich(ludnosc, ROZMIAR) << endl;

	cout << "B) Liczba imion konczacych sie na 'a': " << policzImionaNaA(ludnosc, ROZMIAR) << endl;

	cout << "C) Sredni wiek w grupie: " << obliczSredniWiek(ludnosc, ROZMIAR) << " lat" << endl;

	cout << "D) Rekordowy wzrost: " << znajdzMaxWzrost(ludnosc, ROZMIAR) << " cm" << endl;


int mlody = znajdzNajmlodszego(ludnosc, ROZMIAR);

	cout << "E) Najmlodsza osoba: " << ludnosc[mlody].imie << " "

		<< ludnosc[mlody].nazwisko << " (" << ludnosc[mlody].wiek << " lat)" << endl;

	cout << "\n--- Fragment listy (pierwsze 5 osob) ---" << endl;



	for (int i = 0; i < 5; i++) {
		cout << ludnosc[i].id << ". " << ludnosc[i].imie << " " << ludnosc[i].nazwisko 
			<< " | " << ludnosc[i].wzrost << "cm" << endl;
	}



	// Wywołanie wykresu 



	generujWykresWieku(ludnosc, ROZMIAR);

	return 0;

}
