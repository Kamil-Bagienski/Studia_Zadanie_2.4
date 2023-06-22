//Kamil Bagieński, numer indeksu 155623
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

struct Pracownik
{
    string nazwisko;
    int staz;
    double pensja;
};
//Zadanie 2, plik z pracownikami
void wczytywanie_pracownik(Pracownik *tablica,int &wielkosc);
void wyswietlenie_pracownicy(Pracownik *tablica, int wielkosc);
void sortowanie(Pracownik *tablica, int wielkosc);
double srednia(int staz,Pracownik *tablica, int wielkosc);
void zapisywanie_pracownik(Pracownik *tablica,int wielkosc);
void pracownicy();
//Zadanie 1, macierze
void wypelnienie_macierz(int tablica[6][6]);
void wyswietlenie(int tablica[6][6]);
void zapisywanie_macierz(int tablica[6][6]);
void transponowanie(int tablica[6][6]);
void macierze();
bool wybor(char menu);

int main( )
{
srand(time(NULL));
char menu='T';
do
{
system("CLS");
int zadanie=0;
cout<<"Zadanie 2.4- program do transponowania macierzy z pliku oraz program do wczytywania danych pracownikow z pliku"<<endl;
cout<<"Ktory program chcesz najpierw otworzyc?:"<<endl;
cout<<"1.Transponowanie macierzy z pliku"<<endl<<"2.Wczytywanie danych pracowniczych z pliku"<<endl<<"Wpisz cyfre:";
cin>>zadanie;
if (zadanie==1)
{
macierze();
cout<<"Czy chcesz wrocic do menu by powtorzyc program? Napisz T albo N:";cin>>menu;
}
else if(zadanie==2)
{
pracownicy();
cout<<"Czy chcesz wrocic do menu by powtorzyc program? Napisz T albo N:";cin>>menu;
}
else
cout<<"Nie ma takiego zadania, wybierz poprawna cyfre"<<endl;
} while (wybor(menu)==true);
cout<<"Program zostanie zakonczony zgodnie z Twoim wyborem"<<endl;
return 0;
}

void wypelnienie_macierz(int tablica[6][6])
{
int poczatek,koniec;
cout<<"Podaj najmniejsza liczbe jaka ma pojawic sie w macierzy(liczba ma byc calkowita):";
cin>>poczatek;
cout<<"Podaj najwieksza liczbe jaka ma pojawic sie w macierzy(liczba ma byc calkowita):";
cin>>koniec;
for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        tablica[i][j]=rand() % (koniec+1-poczatek)+poczatek;
    }
}
}

void wyswietlenie(int tablica[6][6])
{
for(int i=0;i<6;i++)
{
    cout<<"|";
    for(int j=0;j<6;j++)
    {
        cout<<setw(3)<<tablica[i][j]<<" ";
    }
    cout<<"|"<<endl;
}
cout<<endl;
cout<<endl;
}

void zapisywanie_macierz(int tablica[6][6])
{
ofstream plik_macierz;
plik_macierz.open("macierz.txt");
if(!plik_macierz)
{
    cout<<"BLAD ZAPISU-NASTAPI ZAMKNIECIE PROGRAMU";
    exit(1);
}
else
{
for (int i=0;i<6;i++)
{
    for (int j=0;j<6;j++)
    {
        plik_macierz<<tablica[i][j]<<" ";
    }
    plik_macierz<<endl;
}
cout << "Plik zostal poprawnie utworzony"<<endl;
cout <<endl;
}
}

void transponowanie(int tablica[6][6])
{
    ifstream plik_macierz;
    plik_macierz.open("macierz.txt");
    if(!plik_macierz.is_open())
    {
    cout<<"BLAD ODCZYTU-NASTAPI ZAMKNIECIE PROGRAMU"<<endl;
    exit(1);
    }
    else {
    for (int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            plik_macierz>>tablica[j][i];
        }
    }
    plik_macierz.close();
    }
}

void macierze()
{
    system("CLS");
    int macierz[6][6];
    cout<<"Program do transponowania macierzy 6x6, wypelnionej liczbami losowymi z przedzialu podanego przez uzytkownika"<<endl;
    wypelnienie_macierz(macierz);
    cout<<"Macierz:"<<endl;
    wyswietlenie(macierz);
    zapisywanie_macierz(macierz);
    transponowanie(macierz);
    cout<<"Macierz po transponowaniu:"<<endl;
    wyswietlenie(macierz);
}

bool wybor(char menu)
{
    if(menu=='t'||menu=='T')
    {
    return true;
    }
    else
    return false;
}

void wczytywanie_pracownik(Pracownik *tablica,int &wielkosc)
{
    ifstream pracownicy_plik;
    pracownicy_plik.open("pracownicy.txt");
    
    if (!pracownicy_plik.is_open())
    {
        cout << "BLAD ODCZYTU - NASTAPI ZAMKNIECIE PROGRAMU" << endl;
        exit(1);
    }
    string ile_linijek;
    int liczba_Linii=0;
    while (getline(pracownicy_plik,ile_linijek))
    {
        liczba_Linii++;
    }
    if(liczba_Linii<wielkosc)
    {
        wielkosc=liczba_Linii;
        cout<<"Plik nie posiada takiej ilosci pracownikow, ilosc ta zostala zmieniona na "<<wielkosc<<endl;
    }
    pracownicy_plik.clear();
    pracownicy_plik.seekg(0, ios::beg);

    for (int i = 0; i < wielkosc; i++)
    {
        pracownicy_plik>>tablica[i].nazwisko;
        pracownicy_plik>>tablica[i].staz;
        pracownicy_plik>>tablica[i].pensja;
    }
    pracownicy_plik.close();
}

void wyswietlenie_pracownicy(Pracownik *tablica, int wielkosc)
{
    cout<<setw(3)<< "Pracownik"<<setw(6)<< "Staz "<<setw(5)<<"Pensja"<<endl;
        for (int i = 0; i < wielkosc; i++)
    {
        cout <<setw(9)<< tablica[i].nazwisko<<" "<<setw(4)<<tablica[i].staz<< " "<<setw(6)<< tablica[i].pensja<<endl;
    }
    cout<<endl;
}
void sortowanie(Pracownik *tablica,int wielkosc)
{
	for(int i=0;i<wielkosc;i++)
    {
		for(int j=1;j<wielkosc-i;j++)
		{
            if(tablica[j-1].nazwisko>tablica[j].nazwisko)
			{
            swap(tablica[j-1].nazwisko, tablica[j].nazwisko);
            swap(tablica[j-1].staz, tablica[j].staz);
            swap(tablica[j-1].pensja, tablica[j].pensja);
            }
        }
    }
}

double srednia(int staz,Pracownik *tablica, int wielkosc)
{
    int ilosc=0;
    double suma=0;
    for (int i=0;i<wielkosc;i++)
    {
        if(staz<tablica[i].staz)
        {
            ilosc++;
            suma+=tablica[i].pensja;
        }
    }
    return suma/ilosc;
}

void zapisywanie_pracownik(Pracownik *tablica,int wielkosc)
{
    ofstream pracownicy_plik;
    string nazwaPliku;
    char nazwa[50];
    cout<<"Podaj nazwe pliku do zapisu:"; 
    cin>>nazwa;
    nazwaPliku=nazwa;
    nazwaPliku+=".txt";
    pracownicy_plik.open(nazwaPliku);

    if (!pracownicy_plik.is_open())
    {
        cout << "BLAD zapisu - NASTAPI ZAMKNIECIE PROGRAMU" << endl;
        exit(1);
    }
    
    for (int i = 0; i < wielkosc; i++)
    {
        pracownicy_plik<<tablica[i].nazwisko<<" ";
        pracownicy_plik<<tablica[i].staz<<" ";
        pracownicy_plik<<tablica[i].pensja<<" ";
        pracownicy_plik<<endl;
    }
    cout<< "Plik zostal zapisany pod nazwa "<<nazwaPliku<<endl;
    pracownicy_plik.close();
}

void pracownicy()
{
    system ("CLS");
    int N,staz;
    char sort;
    cout<< "Program do wyswietlania danych pracownikow z pliku tekstowego, sortowania i badania sredniej plac"<<endl;
    cout<< "Podaj ilu pracownikow dane chcesz wyswietlic:";
    cin >> N;
    Pracownik *tablica = new Pracownik[N];
    wczytywanie_pracownik(tablica,N);
    wyswietlenie_pracownicy(tablica,N);
    cout<< "Czy chcesz posortowac alfabetycznie tabelke z pracownikami? Wpisz T albo N:";
    cin>>sort;
    if(sort=='t'||sort=='T')
    {
    cout<<"Tablica po posortowaniu"<<endl;
    system("CLS");
    sortowanie(tablica,N);
    wyswietlenie_pracownicy(tablica,N);
    }
    
    cout<<"Srednia pensja pracownikow powyzej stazu pracy(wpisz staz pracy powyzej ktorego chcesz to zbadac):";
    cin>>staz;
    cout<<"Pracownicy ktorzy maja staz dluzszy niz "<<staz<< " lat maja srednia pensje w wysokosci "<<srednia(staz,tablica,N)<<endl;
    zapisywanie_pracownik(tablica,N);

    delete[] tablica;
}