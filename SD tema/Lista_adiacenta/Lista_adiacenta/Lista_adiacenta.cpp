// Lista_adiacenta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int max_noduri = 100; // Numărul maxim de noduri în graf

class Graph {
private:
    int numNoduri;
    int listaAdiacenta[max_noduri][max_noduri];

public:
    Graph(int noduri) {
        numNoduri = noduri;

        // Inițializăm lista de adiacență cu 0 (nu există muchii)
        for (int i = 0; i < numNoduri; ++i) {
            for (int j = 0; j < numNoduri; ++j) {
                listaAdiacenta[i][j] = 0;
            }
        }
    }

    void adaugareMuchie(int src, int dest) {
        // Adaugăm muchia de la src la dest
        listaAdiacenta[src][dest] = 1;

        // Dacă graful este neorientat, adăugăm și muchia inversă
        // listaAdiacenta[dest][src] = 1;
    }

    void afisareGraf() {
        for (int i = 0; i < numNoduri; ++i) {
            cout << "Nodul " << i << ": ";
            for (int j = 0; j < numNoduri; ++j) {
                if (listaAdiacenta[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int numNoduri = 5; // Numărul de noduri în graf
    Graph graph(numNoduri);

    // Adăugăm muchiile în graf
    graph.adaugareMuchie(0, 1);
    graph.adaugareMuchie(0, 4);
    graph.adaugareMuchie(1, 2);
    graph.adaugareMuchie(1, 3);
    graph.adaugareMuchie(1, 4);
    graph.adaugareMuchie(2, 3);
    graph.adaugareMuchie(3, 4);

    // Afișăm lista de adiacență
    graph.afisareGraf();

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
