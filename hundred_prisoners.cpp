#include <iostream>
#include <ctime>
using namespace std;

int main(){
srand( time( NULL ) );

cout << "Program liczy procent sukcesow dla podanej liczby prob w problemie"
     << " 100 wiezniow dla optymalnej strategii." << endl
     << "Prosze podac liczbe prob: " ;
int n; //liczba prob
cin >> n;
int p = 0; //liczba prob udanych

for(int k = 1; k <= n; k++){ //k - numer proby

int szafka[101] = {}; // zeby miec indeksy od 1 do 100

//jest tez funkcja random_shuffle, ale chcialem napisac swoj generator
for(int i = 1; i <= 100; i++){
    do {
        bool powtorka = 0; // czy wylosowana liczba juz byla wczesniej
        int r = rand()%100+1; // losujemy liczbe od 1 do 100
        for(int j = 1; j < i; j++){ // patrzymy, czy nie bylo jej juz wczesniej
            if(r == szafka[j]){
                powtorka = 1;
                break;
            }
        }
        if(!powtorka) szafka[i] = r; // jesli sie nie powtarza wstawiamy liczbe do szafki
    }while(szafka[i] == 0); // 0 oznacza, ze szafka nie dostala jeszcze numerka
}
//for(int i = 1; i<=100; i++) cout << szafka[i] << endl;

int sumaDlugCykli = 0;
for(int i = 1; i <= 100; i++){
    if(szafka[i] == 0) continue; // jak w szafce jest 0, znaczy to ze byla juz we wczesniejszym cyklu
    int cykl = 0; // dlugosc rozpoatrywanego cyklu
    int nast = 0; // bedzie to numer w nastepnej szafce
    int x = i;    // pomocnicza
    while(nast != i){ // dopoki nie trafimy na karteczke z numerem, jaki miala szafka, od ktorej zaczelismy
        nast = szafka[x];
        szafka[x] = 0;
        x = nast;
        cykl++;
    }
    //cout << "Po wykresleniu cyklu " << cykl << "-wyrazowego mamy:" << endl;
    //for(int i = 1; i<=100; i++) cout << szafka[i] << endl;
    if(cykl > 50) break;//{cout << "Przekroczyl 50" << endl; break;} // nieudana proba
    sumaDlugCykli += cykl;
    //cout << "suma dlugosci cykli: " << sumaDlugCykli << endl;
    if(sumaDlugCykli >= 50) {
        //cout << "jest wieksza lub rowna 50, czyli doliczam zwiekszam p" << endl;
        p++; // proba udana
        break;
    }
}
} // koniec glownego fora
cout << float(p)/n*100 << "% prob zakonczylo sie sukcesem.";
//cin >> n;
}
