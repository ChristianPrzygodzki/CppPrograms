#include <iostream>
using namespace std;

void zeroJeden(int l){
  if(l!=0 && l!=1){
    throw "Ma byc zero albo jeden!";
  }
  cout << "Swietnie!" << endl;
}

int main(){
  int liczba;
  cin >> liczba;
  try {zeroJeden(liczba);}
  catch(const char* msg){
    cerr << msg;
  }
}
