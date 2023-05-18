// parcurgereLatime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const int maxNoduri = 100; // Numărul maxim de noduri în graf

class Graph {
private:
    int numNoduri;
    int listaAdiacenta[maxNoduri][maxNoduri];
    bool vizitat[maxNoduri];

public:
    Graph(int noduri) {
        numNoduri = noduri;

        // Inițializăm lista de adiacență cu 0 (nu există muchii)
        for (int i = 0; i < numNoduri; ++i) {
            for (int j = 0; j < numNoduri; ++j) {
                listaAdiacenta[i][j] = 0;
            }
        }

        // Inițializăm vectorul de vizitări cu false
        for (int i = 0; i < numNoduri; ++i) {
            vizitat[i] = false;
        }
    }

    void aduagareMuchie(int src, int dest) {
        // Adăugăm muchia de la src la dest
        listaAdiacenta[src][dest] = 1;

        // Dacă graful este neorientat, adăugăm și muchia inversă
        // listaAdiacenta[dest][src] = 1;
    }

    void BFS(int nodStart) {
        int coada[maxNoduri];
        int front = 0;
        int rear = -1;

        vizitat[nodStart] = true;
        coada[++rear] = nodStart;

        while (front <= rear) {
            int currentVertex = coada[front++];
            cout << currentVertex << " ";

            for (int i = 0; i < numNoduri; ++i) {
                if (listaAdiacenta[currentVertex][i] == 1 && !vizitat[i]) {
                    vizitat[i] = true;
                    coada[++rear] = i;
                }
            }
        }
    }
};

int main() {
    int numNoduri = 7; // Numărul de noduri în graf
    Graph graph(numNoduri);

    // Adăugăm muchiile în graf
    graph.aduagareMuchie(0, 1);
    graph.aduagareMuchie(0, 2);
    graph.aduagareMuchie(1, 3);
    graph.aduagareMuchie(1, 4);
    graph.aduagareMuchie(2, 5);
    graph.aduagareMuchie(2, 6);

    int nodStart = 0; // Nodul de start pentru parcurgerea BFS
    cout << "Parcurgerea in latime (BFS): ";
    graph.BFS(nodStart);

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
