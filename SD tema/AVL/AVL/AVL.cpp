// AVL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class frunza {
public:
    int data;
    frunza* left;
    frunza* right;
    int inaltime;

    frunza(int valoare) {
        data = valoare;
        left = nullptr;
        right = nullptr;
        inaltime = 1;
    }
};

class arboreAvl {
private:
    frunza* root;

public:
    arboreAvl() {
        root = nullptr;
    }

    int getinaltime(frunza* nod) {
        if (nod == nullptr) {
            return 0;
        }
        return nod->inaltime;
    }

    int getBalanceFactor(frunza* nod) {
        if (nod == nullptr) {
            return 0;
        }
        return getinaltime(nod->left) - getinaltime(nod->right);
    }

    frunza* rotateRight(frunza* nod) {
        frunza* newRoot = nod->left;
        frunza* rightfiu = newRoot->right;

        newRoot->right = nod;
        nod->left = rightfiu;

        nod->inaltime = max(getinaltime(nod->left), getinaltime(nod->right)) + 1;
        newRoot->inaltime = max(getinaltime(newRoot->left), getinaltime(newRoot->right)) + 1;

        return newRoot;
    }

    frunza* rotateLeft(frunza* nod) {
        frunza* newRoot = nod->right;
        frunza* leftfiu = newRoot->left;

        newRoot->left = nod;
        nod->right = leftfiu;

        nod->inaltime = max(getinaltime(nod->left), getinaltime(nod->right)) + 1;
        newRoot->inaltime = max(getinaltime(newRoot->left), getinaltime(newRoot->right)) + 1;

        return newRoot;
    }

    frunza* insert(frunza* nod, int valoare) {
        if (nod == nullptr) {
            return new frunza(valoare);
        }

        if (valoare < nod->data) {
            nod->left = insert(nod->left, valoare);
        }
        else if (valoare > nod->data) {
            nod->right = insert(nod->right, valoare);
        }
        else {
            // Elementul deja există în arbore
            return nod;
        }

        nod->inaltime = max(getinaltime(nod->left), getinaltime(nod->right)) + 1;

        int balanceFactor = getBalanceFactor(nod);

        // Cazul L-L
        if (balanceFactor > 1 && valoare < nod->left->data) {
            return rotateRight(nod);
        }

        // Cazul R-R
        if (balanceFactor < -1 && valoare > nod->right->data) {
            return rotateLeft(nod);
        }

        // Cazul L-R
        if (balanceFactor > 1 && valoare > nod->left->data) {
            nod->left = rotateLeft(nod->left);
            return rotateRight(nod);
        }

        // Cazul R-L
        if (balanceFactor < -1 && valoare < nod->right->data) {
            nod->right = rotateRight(nod->right);
            return rotateLeft(nod);
        }

        return nod;
    }

    void insert(int valoare) {
        root = insert(root, valoare);
    }

    void traversareInOrdine(frunza* nod) {
        if (nod != nullptr) {
            traversareInOrdine(nod->left);
            cout << nod->data << " ";
            traversareInOrdine(nod->right);
        }
    }

    void traversareInOrdine() {
        traversareInOrdine(root);
    }
};

int main() {
    arboreAvl arboreAvl;

    // Inserează elementele în arborele AVL echilibrat
    arboreAvl.insert(9);
    arboreAvl.insert(5);
    arboreAvl.insert(10);
    arboreAvl.insert(0);
    arboreAvl.insert(6);
    arboreAvl.insert(11);
    arboreAvl.insert(-1);
    arboreAvl.insert(1);
    arboreAvl.insert(2);

    cout << "Parcurgerea in ordine : ";
    arboreAvl.traversareInOrdine();

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
