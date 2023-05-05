#include <iostream>
#include <string>


using namespace std;

struct Club {
    string nume_club;
    int an_fondat;
    double market_value;
};

void afisare(Club* club);

void afisare_an(struct Club club[10]) {

    system("cls");

    int an;
    cout << "Introduceti anul in care a fost fondat clubul: ";
    cin >> an;
    if (cin.fail())
    {
        cout << "Eroare\n";
    }

    int ok = 1;
    for (int i = 0; i < 3; i++) {
        if (an == club[i].an_fondat) {
            cout << club[i].nume_club << endl;
            ok = 0;
        }
    }
    if (ok == 1)
        cout << "Nu exista" << endl;
    cout << endl;

    system("pause");
}

void ordonare_crescator(Club* club) {

    system("cls");

    int aux1;
    string aux;
    double aux2;

    for (int i = 0; i < 13; i++)
        for (int j = i; j < 3; j++)
        {
            if (club[i].market_value > club[j].market_value)
            {
                aux = club[i].nume_club;
                aux1 = club[i].an_fondat;
                aux2 = club[i].market_value;

                club[i].nume_club = club[j].nume_club;
                club[i].an_fondat = club[j].an_fondat;
                club[i].market_value = club[j].market_value;

                club[j].nume_club = aux;
                club[j].an_fondat = aux1;
                club[j].market_value = aux2;
            }
        }

    afisare(club);

    system("pause");

}

void ordonare_descrescator(Club* club) {

    system("cls");

    int aux1;
    string aux;
    double aux2;

    for (int i = 0; i < 3; i++)
        for (int j = i; j < 3; j++)
        {
            if (club[i].market_value < club[j].market_value)
            {
                aux = club[i].nume_club;
                aux1 = club[i].an_fondat;
                aux2 = club[i].market_value;

                club[i].nume_club = club[j].nume_club;
                club[i].an_fondat = club[j].an_fondat;
                club[i].market_value = club[j].market_value;

                club[j].nume_club = aux;
                club[j].an_fondat = aux1;
                club[j].market_value = aux2;
            }
        }
    afisare(club);

    system("pause");

}

void schimbare_valoare(Club* club)
{
    system("cls");

    cin.ignore();
    cout << "Pentru ce club vreti sa schimbati valoarea pe piata: ";
    string CLUB;
    getline(cin, CLUB);
    int valoare;
    cout << "Introduceti noua valoare: ";
    cin >> valoare;
    if (cin.fail())
    {
        cout << "Eroare\n";
    }

    int ok = 0;
    for (int i = 0; i < 3; i++)
    {
        if (club[i].nume_club == CLUB)
        {
            club[i].market_value = valoare;
            ok = 1;
            cout << "valoare schimbata cu succes"<<endl;
        }

    }
    if (ok == 0)
    {
        cout << "Clubul introdus nu exista"<<endl;
    }
    cout << endl;

    system("pause");
}


void afisare(Club* club)
{
    for (int i = 0; i < 3; i++)
    {
        cout << club[i].nume_club << endl;
        cout << club[i].an_fondat << endl;
        cout << club[i].market_value << endl;
        cout << endl;
    }
}

void menu(Club club[10])
{
    int alegere;

    do {
        system("cls");

        cout << "------Meniu------\n\n";
        cout << "1) Cautati un club dupa an\n";
        cout << "2) Afisati cluburile in ordine crescatoare dupa pret\n";
        cout << "3) Afisati cluburile in ordine descrescatoare dupa pret\n";
        cout << "4) Schimbati valoarea pe piata a unui club\n";
        cout << "5) Iesiti\n";

        cin >> alegere;

        if (cin.fail())
        {
            cout << "Eroare\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (alegere < 1 || alegere>5)
        {
            cout << "Un numar intre 1 si 5!!\n\n";
        }

        switch (alegere)
        {
        case 1:
            afisare_an(club);
            break;
        case 2:
            ordonare_crescator(club);
            afisare(club);
            break;
        case 3:
            ordonare_descrescator(club);
            afisare(club);
            break;
        case 4:
            schimbare_valoare(club);
            break;
        case 5:
            exit(0);
        }

    } while (alegere != 5);
}

int main()
{

    Club club[10];

    club[0].nume_club = "Fc Barcelona";
    club[0].an_fondat = 1899;
    club[0].market_value = 767.00;

    club[1].nume_club = "Real Madrid";
    club[1].an_fondat = 1902;
    club[1].market_value = 860.80;

    club[2].nume_club = "Atletico Madrid";
    club[2].an_fondat = 1903;
    club[2].market_value = 457.80;

    menu(club);

    return 0;
}

