#include <iostream>
#include <algorithm>

int main() {
  int a = 0;
  int b = 0;
  int c = 0;
  std::cin >> a >> b >> c;
  int res1 = (a + b) * c;
  int res2 = a + (b * c);
  int res3 = (a * b) + c;
  int res4 = a * (b + c);
  int res5 = a * b * c;
  int res6 = a + b + c;
  int max_val = std::max(std::max(std::max(std::max(std::max(res1, res2), res3), res4), res5), res6);
  std::cout << max_val;
  return 0;
}
