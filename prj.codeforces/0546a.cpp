#include <iostream>

int main() {
  int k = 0;
  int n = 0;
  int w = 0;
  std::cin >> k >> n >> w;
  for (int i = 1; i < w + 1; ++i) {
    n -= i * k;
  }
  if (n < 0 ? std::cout << std::abs(n) : std::cout << 0) {}
  return 0;
}