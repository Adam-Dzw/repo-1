#include <iostream>
#include <string>
using namespace std;

struct Osoba {
    int wiek;
};

void generujWykresWieku(Osoba tab[], int rozmiar) {

    if (rozmiar <= 0) {
        cout << "Brak danych do wyswietlenia.\n";
        return;
    }

    // 0-9, 10-19, ..., 70-79, 80+
    int grupy[9] = { 0 };

    for (int i = 0; i < rozmiar; i++) {
        if (tab[i].wiek < 0) continue; // ignorujemy błędne dane

        int dekada = tab[i].wiek / 10;

        if (dekada >= 0 && dekada <= 7)
            grupy[dekada]++;
        else
            grupy[8]++; // 80+
    }

    cout << "\n--- WYKRES ROZKŁADU WIEKU (Histogram) ---\n";

    string etykiety[9] = {
        "0-9", "10-19", "20-29", "30-39",
        "40-49", "50-59", "60-69", "70-79", "80+"
    };

    for (int i = 0; i < 9; i++) {
        cout << etykiety[i] << " | ";

        for (int j = 0; j < grupy[i]; j++) {
            cout << "*";
        }

        cout << " (" << grupy[i] << ")\n";
    }
}