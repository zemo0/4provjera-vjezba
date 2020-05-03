#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool negativan(double broj)
{
    if(broj<0)
        return true;
    return false;
}

bool tekuci(unsigned long long int broj)
{
    if(broj/100000000 == 32)
        return true;
    return false;
}

bool ispisi_podatke(string prezimeIme[],
                    unsigned long long int brRacuna[],
                    double saldo[],
                    int brKLijenata,
                    string pretraga)
{
    int br = 0;
    for(int i = 0; i < brKLijenata; i++)
    {
        if(prezimeIme[i] == pretraga)
        {
            cout << brRacuna[i] << ", " << saldo[i] << endl;
            br++;
        }
    }
    if(br==0)
        return false;
    return true;
}

int main()
{
    int brKlijenata = 0;
    unsigned long long int *brRacuna = new unsigned long long int[1000];
    string *prezimeIme = new string[1000];
    double *saldo = new double[1000];
    int izbor;
    while(1)
    {
        system("cls");
        cout << "1. Upis novog korisnika" << endl;
        cout << "2. Ispis svih podataka" << endl;
        cout << "3. Pretraga prema prezimenu i imenu" << endl;
        cout << "4. Brisanje računa" << endl;
        cout << "5. Ispiši sortirano prema prezimenu i imenu" << endl;
        cout << "6. izlaz" << endl;
        cout << "Unesite broj opcije: ";
        cin >> izbor;
        cout << endl;
        if(izbor == 1)
        {
            unsigned long long unos;
            while(1)
            {
                try
                {
                    cout << "Unesite broj racuna: ";
                    cin >> unos;
                    if(unos < 1000000000 || unos > 9999999999)
                        throw "Broj racuna mora imati 10 znamenki";
                    break;
                }
                catch(const char* msg)
                {
                    cout << msg << endl;
                }
            }
            brRacuna[brKlijenata] = unos;
            cout << "Unesite prezime i ime: " << endl;
            cin.ignore();
            getline(cin, prezimeIme[brKlijenata]);
            cout << "Unesite saldo: ";
            cin >> saldo[brKlijenata];
            brKlijenata++;
        }
        else if(izbor == 2)
        {
            for(int i = 0; i < brKlijenata; i++)
            {
                cout << brRacuna[i] << ", " << prezimeIme[i] << ", " << saldo[i] << endl;
            }
            cout << "Suma svih salda je " << accumulate(saldo, saldo+brKlijenata, 0.0) << endl;
            int max_indeks = max_element(saldo, saldo+brKlijenata) - saldo;
            cout << "Klijent koji ima najveži saldo je: " << prezimeIme[max_indeks] << endl;
            cout << "Broj racuna s negativnim saldom: " << count_if(saldo, saldo+brKlijenata, negativan) << endl;
            cout << "Broj tekucih racuna je: " << count_if(brRacuna, brRacuna+brKlijenata, tekuci) << endl;
        }
        else if(izbor == 3)
        {
            cout << "Unesite ime i prezime koje pretrazujete: " << endl;
            string pretraga;
            cin.ignore();
            getline(cin, pretraga);
            if(ispisi_podatke(prezimeIme,brRacuna,saldo,brKlijenata,pretraga)==false)
            {
                cout << "Nema takvih klijenata." << endl;
            }
        }

    return 0; //asdsadsad
}
