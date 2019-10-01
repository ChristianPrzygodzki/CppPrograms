#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// tworzymy klase macierz z szablonem na dowolne cialo modulo k
template<int k>class macierz_4x4{
  public:
  int wyraz[4][4];
// konstrukto macierzy zerowej
  macierz_4x4(){
    wyraz[0][0] = 0;wyraz[0][1] = 0;wyraz[0][2] = 0;wyraz[0][3] = 0;
    wyraz[1][0] = 0;wyraz[1][1] = 0;wyraz[1][2] = 0;wyraz[1][3] = 0;
    wyraz[2][0] = 0;wyraz[2][1] = 0;wyraz[2][2] = 0;wyraz[2][3] = 0;
    wyraz[3][0] = 0;wyraz[3][1] = 0;wyraz[3][2] = 0;wyraz[3][3] = 0;
  }
// konstruktor macierzy jednostkowej
  macierz_4x4(int n){
    wyraz[0][0] = n;wyraz[0][1] = 0;wyraz[0][2] = 0;wyraz[0][3] = 0;
    wyraz[1][0] = 0;wyraz[1][1] = n;wyraz[1][2] = 0;wyraz[1][3] = 0;
    wyraz[2][0] = 0;wyraz[2][1] = 0;wyraz[2][2] = n;wyraz[2][3] = 0;
    wyraz[3][0] = 0;wyraz[3][1] = 0;wyraz[3][2] = 0;wyraz[3][3] = n;
  }
// konstruktor macierzy o podanych wyrazach
  macierz_4x4(int a00, int a01, int a02, int a03, int a10, int a11, int a12, int a13, int a20, int a21, int a22, int a23, int a30, int a31, int a32, int a33){
    wyraz[0][0]=a00;wyraz[0][1]=a01;wyraz[0][2]=a02;wyraz[0][3]=a03;
    wyraz[1][0]=a10;wyraz[1][1]=a11;wyraz[1][2]=a12;wyraz[1][3]=a13;
    wyraz[2][0]=a20;wyraz[2][1]=a21;wyraz[2][2]=a22;wyraz[2][3]=a23;
    wyraz[3][0]=a30;wyraz[3][1]=a31;wyraz[3][2]=a32;wyraz[3][3]=a33;
  }
// funkcja zwracajaca wyznacznik (modulo k)
  int wyznacznik(){
    return (wyraz[0][0]*(wyraz[1][1]*wyraz[2][2]*wyraz[3][3]+wyraz[1][2]*wyraz[2][3]*wyraz[3][1]+wyraz[1][3]*wyraz[2][1]*wyraz[3][2]-wyraz[1][3]*wyraz[2][2]*wyraz[3][1]-wyraz[1][1]*wyraz[2][3]*wyraz[3][2]-wyraz[1][2]*wyraz[2][1]*wyraz[3][3])-wyraz[0][1]*(wyraz[1][0]*wyraz[2][2]*wyraz[3][3]+wyraz[1][2]*wyraz[2][3]*wyraz[3][0]+wyraz[1][3]*wyraz[2][0]*wyraz[3][2]-wyraz[1][3]*wyraz[2][2]*wyraz[3][0]-wyraz[1][0]*wyraz[2][3]*wyraz[3][2]-wyraz[1][2]*wyraz[2][0]*wyraz[3][3])+wyraz[0][2]*(wyraz[1][0]*wyraz[2][1]*wyraz[3][3]+wyraz[1][1]*wyraz[2][3]*wyraz[3][0]+wyraz[1][3]*wyraz[2][0]*wyraz[3][1]-wyraz[1][3]*wyraz[2][1]*wyraz[3][0]-wyraz[1][0]*wyraz[2][3]*wyraz[3][1]-wyraz[1][1]*wyraz[2][0]*wyraz[3][3])-wyraz[0][3]*(wyraz[1][0]*wyraz[2][1]*wyraz[3][2]+wyraz[1][1]*wyraz[2][2]*wyraz[3][0]+wyraz[1][2]*wyraz[2][0]*wyraz[3][1]-wyraz[1][2]*wyraz[2][1]*wyraz[3][0]-wyraz[1][0]*wyraz[2][2]*wyraz[3][1]-wyraz[1][1]*wyraz[2][0]*wyraz[3][2]))%k;
  }
// zdefiniowanie potegowania, dodawania, odejmowania, dzia³ania modulo na wszystkich wyrazach i porownywania
  macierz_4x4<k> operator^(int n){
    macierz_4x4<k> b=*this, c;
    for(int m=1;m<n;m++){
      for(int i=0;i<4;i++) for(int j=0;j<4;j++){
      c.wyraz[i][j] = b.wyraz[i][0]*(wyraz[0][j])+b.wyraz[i][1]*(wyraz[1][j])+b.wyraz[i][2]*(wyraz[2][j])+b.wyraz[i][3]*(wyraz[3][j]);
    }
      b = c;
    }
    return (c%k);
  }

  macierz_4x4<k> operator+(macierz_4x4<k> skladnik){
    return macierz_4x4<k>(wyraz[0][0]+skladnik.wyraz[0][0], wyraz[0][1]+skladnik.wyraz[0][1], wyraz[0][2]+skladnik.wyraz[0][2], wyraz[0][3]+skladnik.wyraz[0][3], wyraz[1][0]+skladnik.wyraz[1][0], wyraz[1][1]+skladnik.wyraz[1][1], wyraz[1][2]+skladnik.wyraz[1][2], wyraz[1][3]+skladnik.wyraz[1][3], wyraz[2][0]+skladnik.wyraz[2][0], wyraz[2][1]+skladnik.wyraz[2][1], wyraz[2][2]+skladnik.wyraz[2][2], wyraz[2][3]+skladnik.wyraz[2][3], wyraz[3][0]+skladnik.wyraz[3][0], wyraz[3][1]+skladnik.wyraz[3][1], wyraz[3][2]+skladnik.wyraz[3][2], wyraz[3][3]+skladnik.wyraz[3][3])%k;
  }

macierz_4x4<k> operator-(macierz_4x4<k> odjemnik){
    return macierz_4x4<k>(wyraz[0][0]-odjemnik.wyraz[0][0], wyraz[0][1]-odjemnik.wyraz[0][1], wyraz[0][2]-odjemnik.wyraz[0][2], wyraz[0][3]-odjemnik.wyraz[0][3], wyraz[1][0]-odjemnik.wyraz[1][0], wyraz[1][1]-odjemnik.wyraz[1][1], wyraz[1][2]-odjemnik.wyraz[1][2], wyraz[1][3]-odjemnik.wyraz[1][3], wyraz[2][0]-odjemnik.wyraz[2][0], wyraz[2][1]-odjemnik.wyraz[2][1], wyraz[2][2]-odjemnik.wyraz[2][2], wyraz[2][3]-odjemnik.wyraz[2][3], wyraz[3][0]-odjemnik.wyraz[3][0], wyraz[3][1]-odjemnik.wyraz[3][1], wyraz[3][2]-odjemnik.wyraz[3][2], wyraz[3][3]-odjemnik.wyraz[3][3])%k;
  }

  macierz_4x4<k> operator%(int dzielnik){
    return macierz_4x4<k>(wyraz[0][0]%dzielnik, wyraz[0][1]%dzielnik, wyraz[0][2]%dzielnik, wyraz[0][3]%dzielnik, wyraz[1][0]%dzielnik, wyraz[1][1]%dzielnik, wyraz[1][2]%dzielnik, wyraz[1][3]%dzielnik, wyraz[2][0]%dzielnik, wyraz[2][1]%dzielnik, wyraz[2][2]%dzielnik, wyraz[2][3]%dzielnik, wyraz[3][0]%dzielnik, wyraz[3][1]%dzielnik, wyraz[3][2]%dzielnik, wyraz[3][3]%dzielnik);
  }

  bool operator==(macierz_4x4<k> por){
    if(wyraz[0][0]==por.wyraz[0][0] && wyraz[0][1]==por.wyraz[0][1] && wyraz[0][2]==por.wyraz[0][2] && wyraz[0][3]==por.wyraz[0][3] && wyraz[1][0]==por.wyraz[1][0] && wyraz[1][1]==por.wyraz[1][1] && wyraz[1][2]==por.wyraz[1][2] && wyraz[1][3]==por.wyraz[1][3] && wyraz[2][0]==por.wyraz[2][0] && wyraz[2][1]==por.wyraz[2][1] && wyraz[2][2]==por.wyraz[2][2] && wyraz[2][3]==por.wyraz[2][3] && wyraz[3][0]==por.wyraz[3][0] && wyraz[3][1]==por.wyraz[3][1] && wyraz[3][2]==por.wyraz[3][2] && wyraz[3][3]==por.wyraz[3][3]) return true;
    else return false;
  }
  // funkcja wypisujaca macierz
  void pisz(){
    cout << "[ " << wyraz[0][0] << " " << wyraz[0][1] << " " << wyraz[0][2] << " " << wyraz[0][3] << " ]" << endl << "[ " << wyraz[1][0] << " " << wyraz[1][1] << " " << wyraz[1][2] << " " << wyraz[1][3] << " ]" << endl << "[ " << wyraz[2][0] << " " << wyraz[2][1] << " " << wyraz[2][2] << " " << wyraz[2][3] << " ]" << endl << "[ " << wyraz[3][0] << " " << wyraz[3][1] << " " << wyraz[3][2] << " " << wyraz[3][3] << " ]" << endl;
  }
  // funkcja zwracajaca macierz zapisana w postaci stringa
  string daj_str(){
  string matrix, poczatek;
  poczatek = "[ ";
  matrix = poczatek + to_string(wyraz[0][0]) + " " + to_string(wyraz[0][1]) + " " + to_string(wyraz[0][2]) + " " + to_string(wyraz[0][3]) + " ]" + "\n" + "[ " + to_string(wyraz[1][0]) + " " + to_string(wyraz[1][1]) + " " + to_string(wyraz[1][2]) + " " + to_string(wyraz[1][3]) + " ]" + "\n" + "[ " + to_string(wyraz[2][0]) + " " + to_string(wyraz[2][1]) + " " + to_string(wyraz[2][2]) + " " + to_string(wyraz[2][3]) + " ]" + "\n" + "[ " + to_string(wyraz[3][0]) + " " + to_string(wyraz[3][1]) + " " + to_string(wyraz[3][2]) + " " + to_string(wyraz[3][3]) + " ]" + "\n";
  return matrix;
  }
};

int main()
{
  //Macierz 4x4 Z2
  //zmienna plik odpowiedzialna za zapis wynikow do pliku
    fstream plik;
    plik.open("wyniki_z2",ios::out);

// tworzymy macierz jednostkowa i zerowa, beda potrzebne przy porownywaniu
  macierz_4x4<2> jednostkowa(1), zerowa(0);
// wektor do iterowania dla petli for oraz licznik do liczenia znalezionych macierzy
  vector<int> v = {0,1};
  int licznik=0;
  // petle for dla rozpatrzenia kazdej macierzy
  for(int i00:v) for(int i01:v) for(int i02:v) for(int i03:v) for(int i10:v) for(int i11:v) for(int i12:v) for(int i13:v) for(int i20:v) for(int i21:v) for(int i22:v) for(int i23:v) for(int i30:v) for(int i31:v) for(int i32:v) for(int i33:v){
    // tworzymy macierz do sprawdzenia
    macierz_4x4<2> mac(i00, i01, i02, i03, i10, i11, i12, i13, i20, i21, i22, i23, i30, i31, i32, i33);
    // Nie bierzemy pod uwage macierzy o wyznaczniku 0 i takich, ktore po dodaniu jednostkowej daja zerowa
    if((mac.wyznacznik() == 0) || (mac+jednostkowa==zerowa)) continue;
    // podnosimy do potegi 5
    macierz_4x4<2> mac5 = mac^5;
    // sprawdzamy warunek A^5+I = 0
    if(mac5+jednostkowa == zerowa){
        // dwie kolejne linijki sa zakomentowane, gdyz na poczatku program wypisywal wszystkie macierze, spelniajace powyzszy warunek
      //mac.pisz();
      //cout << "jest szukana macierza." << endl;
      // teraz sprawdzamy dodatkowy warunek
      if((mac^4)-(mac^3)+(mac^2)-mac+jednostkowa == zerowa){
          // wypisujemy spelniajace go macierze i zapisujemy do pliku
        mac.pisz();
        cout << "jest szukana macierza." <<endl;
        plik << mac.daj_str() << "jest szukana macierza." << endl;
    // przy kazdej znalezionej macierzy zwiekszamy licznik o 1
      licznik++;
      }
    }
  } //koniec fora
  // na koniec drukujemy, ile macierzy znalezlismy
  cout << "Znaleziono " << licznik << " macierzy.";
  plik << "Znaleziono " << licznik << " macierzy.";
  plik.close();
}
