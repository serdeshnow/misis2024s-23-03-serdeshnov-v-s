#include <iostream>
#include <string>

int main() {
  int l = 0;
  int b = 0;
  std::cin >> l >> b;
  int y = 1;
  while (l < b){
    l *= 3;
    b *= 2;
    if (l > b) {
      break;
    }
    ++y;
  }
  std::cout << y;
  return 0;
}