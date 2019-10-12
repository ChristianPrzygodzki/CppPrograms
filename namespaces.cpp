#include <iostream>

namespace jedynka{
  int liczba = 1;
  void fun(){
    std::cout << "jestem sobie funkcja z jedynki" << std::endl;
  }
}
namespace dwojka{
  int liczba = 2;
  void fun(){
    std::cout << "hej dwojeczki!" << std::endl;
  }
}

using namespace dwojka;
int main() {
  std::cout << liczba << std::endl;
  fun();

}
