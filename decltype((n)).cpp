#include <iostream>
using namespace std;

int n = 6;

void f(){
  decltype((n)) cos = n;
  cos++;
}

int main() {
cout << n << endl;
f();
cout << n << endl;
}
