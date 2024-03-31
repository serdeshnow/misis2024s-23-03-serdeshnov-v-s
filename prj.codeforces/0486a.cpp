#include <iostream>

int main() {
  long long int n = 0;
  std::cin >> n;
  if (n % 2 == 1 ? std::cout << -(n / 2) - 1: std::cout << (n / 2) ) {}
  return 0;
}
