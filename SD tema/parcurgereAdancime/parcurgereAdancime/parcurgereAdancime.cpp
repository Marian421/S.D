// parcurgereAdancime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const int maxNoduri = 100; // Numărul maxim de noduri în graf

class Graf {
private:
    int numarNoduri;
    int listaAdiacenta[maxNoduri][maxNoduri];
    bool vizitat[maxNoduri];

public:
    Graf(int vertices) {
        numarNoduri = vertices;

        // Inițializăm lista de adiacență cu 0 (nu există muchii)
        for (int i = 0; i < numarNoduri; ++i) {
            for (int j = 0; j < numarNoduri; ++j) {
                listaAdiacenta[i][j] = 0;
            }
        }

        // Inițializăm vectorul de vizitări cu false
        for (int i = 0; i < numarNoduri; ++i) {
            vizitat[i] = false;
        }
    }

    void aduagareMuchie(int src, int dest) {
        // Adăugăm muchia de la src la dest
        listaAdiacenta[src][dest] = 1;

        // Dacă graful este neorientat, adăugăm și muchia inversă
        // listaAdiacenta[dest][src] = 1;
    }

    void DFS(int nodStart) {
        vizitat[nodStart] = true;
        cout << nodStart << " ";

        // Parcurgem toate nodurile adiacente nodului curent
        for (int i = 0; i < numarNoduri; ++i) {
            if (listaAdiacenta[nodStart][i] == 1 && !vizitat[i]) {
                DFS(i);
            }
        }
    }
};

int main() {
    int numarNoduri = 7; // Numărul de noduri în graf
    Graf graf(numarNoduri);

    // Adăugăm muchiile în graf
    graf.aduagareMuchie(0, 1);
    graf.aduagareMuchie(0, 2);
    graf.aduagareMuchie(1, 3);
    graf.aduagareMuchie(1, 4);
    graf.aduagareMuchie(2, 5);
    graf.aduagareMuchie(2, 6);

    int nodStart = 0; // Nodul de start pentru parcurgerea DFS
    cout << "Parcurgerea in adancime (DFS): ";
    graf.DFS(nodStart);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
