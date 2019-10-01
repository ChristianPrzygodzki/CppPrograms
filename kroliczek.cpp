/////////////==================KROLICZEK++++++++++++++

#include <iostream>
#include <string>

using namespace std;
void gps(int iks, int igrek){
  cout << "===GPS===" << endl;
for(int j = 5; j>=1; j--){
  for(int i = 1; i<=5; i++){
    if(i == iks && j == igrek) cout << "k ";
    else cout << "_ ";
  }
  cout << endl;
}
cout << endl << "k -  pozycja kroliczka" << endl << endl;
}
int main(){
  int x = 3, y = 3;
  cout << "Kroliczku tu jest mapa i GPS. Gdzie idziemy?(lewo/prawo/gora/dol/spac/mapa)" << endl << "\t(\\__/)" << endl << "\t(='.'=)" << endl << "\t(\")_(\")" << endl << endl;

  cout << "===MAPA===" << endl ;
  cout << "M _ _ _ _ " << endl;
  cout << "_ _ _ L _" << endl;
  cout << "_ _ _ _ _" << endl;
  cout << "_ _ _ _ _" << endl;
  cout << "_ K _ _ _" << endl ;
  cout << endl << "M - dom misia " << endl << "L - lody" << endl << "K - KFC" << endl << endl;
  gps(x,y);
  string komenda;
  string odp;
  string pomocnik;
  int ile_galek;
  string zamowienie;
  while(1){
    cin >> komenda;
    if(komenda=="mapa"){
      cout << "===MAPA===" << endl ;
      cout << "M _ _ _ _ " << endl;
      cout << "_ _ _ L _" << endl;
      cout << "_ _ _ _ _" << endl;
      cout << "_ _ _ _ _" << endl;
      cout << "_ K _ _ _" << endl ;
      cout << endl << "M - dom misia " << endl << "L - lody" << endl << "K - KFC" << endl << endl;
      getline(cin,pomocnik);
      cout << "Napisz cos, aby kontynuowac:" << endl;
    }
    if(komenda=="spac") {
      cout << "To dobranoc kroliczku.";
      break;
    }

    if(komenda=="lewo") x--;
    if(komenda=="prawo") x++;
    if(komenda=="gora") y++;
    if(komenda=="dol") y--;
    if(x>5 || x<1 || y>5 || y<1) {
      cout << "Oj, kroliczku! Zgubiles sie!!!";
      break;
    }

    if(x == 1 && y == 5){
      cout << "Jestes u misia." << endl << "Mis: -kawkie, herbatkie?" << endl;
      cin >> odp;
      if(odp == "kawkie" || odp == "kawke"){
        cout << "Parzymy kawkie z mleczkiem. Dobra?" << endl;
        cin >> pomocnik;
      }
      if(odp == "herbatkie" || odp == "herbatke"){
        cout << "Parzymy herbatkie. Dobra?" << endl;
        cin >> pomocnik;
      }
      getline(cin,pomocnik);
      cout << "Napisz cos, aby kontynuowac:" << endl;
    }

    if(x == 4 && y == 4){
      cout << "Jestes w lodziarni. Ile galeczek? (liczba)" << endl;
      cin >> ile_galek;
      getline(cin, pomocnik);
      if(ile_galek == 0)
      {
        cout << "Nie, to nie." << endl;
        goto tutaj;
      }
      cout << "Jakie smaki?" << endl;
      getline(cin, pomocnik);
      cout << "Prosze, oto " << ile_galek << " galki." << "Smakuja?" <<endl;
      getline(cin, pomocnik);
      tutaj:;
      cout << "Napisz cos, aby kontynuowac:" << endl;
    }
    if(x == 2 && y == 1){
      getline(cin,pomocnik);
      cout << "Jestes w KFC. Co podac?" << endl;
      getline(cin,zamowienie);
      cout << "Prosze oto: " << zamowienie << endl;
      cout << "Napisz cos, aby kontynuowac:" << endl;
    }
    getline(cin,pomocnik);
    if(pomocnik == "kocham cie." || pomocnik == "kocham cie" || pomocnik == "Kocham cie." || pomocnik == "Kocham Cie." || pomocnik == "Kocham Cie"){
      cout << "Ja tez Cie kocham." << endl;
      cout << "Napisz cos, aby kontynuowac:" << endl;
    getline(cin,pomocnik);
    }
    cout << endl;
    gps(x,y);
    cout << "Dobrze kroliczku. A teraz dokad? (lewo/prawo/gora/dol/spac/mapa)" << endl;
}
}
