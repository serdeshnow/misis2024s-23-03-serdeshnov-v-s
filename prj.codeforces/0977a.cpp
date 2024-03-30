#include <iostream>

int main() {
  int a = 0;
  int n = 0;
  std::cin >> a >> n;
  for (int i = 0; i < n; ++i) {
    if((a % 10) == 0 ? a /= 10 : --a){}
  }
  std::cout << a;
  return 0;
}
