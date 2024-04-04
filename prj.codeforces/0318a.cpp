#include <iostream>

int main() {
  long long n = 0;
  long long k = 0;
  std::cin >> n >> k;
  if (((n + 1) / 2) >= k) {
    std::cout << (k * 2) - 1;
  } else {
    std::cout << (k - (n+1) / 2) * 2;
  }
  return 0;
}