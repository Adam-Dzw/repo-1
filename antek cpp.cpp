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














FUNKCJE



void generujImie(Osoba tab[], int index)

{

	string iBazowe = bazaImion[rand() % 7];

	char literaI = bazaImion[rand() % 7][0];

	iBazowe[0] = literaI;

	tab[index].imie = iBazowe;



}



void generujReszte(Osoba tab[], int index, mt19937& gen)

{

	uniform_int_distribution<> d7(0, 6);

	uniform_int_distribution<> dWiek(18, 80);

	uniform_int_distribution<> dWzrost(150, 210);

	string nBazowe = bazaNazwisk[d7(gen)];

	char literaN = bazaNazwisk[d7(gen)][0];

	nBazowe[0] = literaN;

	tab[index].nazwisko = nBazowe;

	tab[index].wiek = dWiek(gen);

	tab[index].wzrost = dWzrost(gen);

	tab[index].id = index + 1;

}







int policzWysokich(Osoba tab[], int rozmiar)

{

	int licznik = 0;

	for (int i = 0; i < rozmiar; i++)

	{

		if (tab[i].wzrost > 200) licznik++;

	}

	return licznik;

}







int policzImionaNaA(Osoba tab[], int rozmiar)

{



	int licznik = 0;

	for (int i = 0; i < rozmiar; i++) {

		if (tab[i].imie.back() == 'a' || tab[i].imie.back() == 'A') licznik++;

	}

	return licznik;

}





double obliczSredniWiek(Osoba tab[], int rozmiar) {

	double suma = 0;

	for (int i = 0; i < rozmiar; i++) {

		suma += tab[i].wiek;

	}

	return suma / rozmiar;

}







int znajdzMaxWzrost(Osoba tab[], int rozmiar) {

	int maxW = tab[0].wzrost;



	for (int i = 1; i < rozmiar; i++) {

		if (tab[i].wzrost > maxW) maxW = tab[i].wzrost;

	}

	return maxW;

}





int znajdzNajmlodszego(Osoba tab[], int rozmiar) {

	int minWiek = tab[0].wiek;

	int indeks = 0;

	for (int i = 1; i < rozmiar; i++) {

		if (tab[i].wiek < minWiek) {

			minWiek = tab[i].wiek;

			indeks = i;

		}

	}

	return indeks;

}





void generujWykresWieku(Osoba tab[], int rozmiar) {



	// Tworzymy tablicę liczników dla dekad: 10-19, 20-29, 30-39, 40-49, 50-59, 60-69, 70-79, 80+ 



	int grupy[8] = { 0 };

	for (int i = 0; i < rozmiar; i++) {

		int dekada = tab[i].wiek / 10;

		if (dekada >= 1 && dekada <= 7) grupy[dekada - 1]++;

		else if (dekada >= 8) grupy[7]++; // Grupa 80+ 

	}



	cout << "\n--- WYKRES ROZKŁADU WIEKU (Histogram) ---" << endl;

	string etykiety[8] = { "10-19", "20-29", "30-39", "40-49", "50-59", "60-69", "70-79", "80+  " };



	for (int i = 0; i < 8; i++) {

		cout << etykiety[i] << " | ";

		for (int j = 0; j < grupy[i]; j++) {

			cout << "*";

		}



		cout << " (" << grupy[i] << ")" << endl;

	}



	cout << "------------------------------------------" << endl;



}

 }