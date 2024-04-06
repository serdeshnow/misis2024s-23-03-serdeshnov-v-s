#include <iostream>
#include <algorithm>

int main() {
  int n = 5;
  int k = 100, l = 10, nl = 4;
  int c = 1, d = 19;
  int p = 90, np = 3;
  std::cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int res1 = (k * l) / nl;
  int res2 = c * d;
  int res3 = p / np;
  std::cout << std::min(std::min( res1, res2 ), res3 ) / n;
  return 0;
}