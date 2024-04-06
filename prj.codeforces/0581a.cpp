#include <iostream>
#include <algorithm>

int main() {
  int red = 0;
  int blue = 0;
  std::cin >> red >> blue;
  int fashion_days = std::min(red, blue);
  std::cout << fashion_days << ' ';
  red -= fashion_days;
  blue -= fashion_days;
  if (red == 0 ? std::cout << blue / 2 : std::cout << red / 2) {}
  return 0;
}
