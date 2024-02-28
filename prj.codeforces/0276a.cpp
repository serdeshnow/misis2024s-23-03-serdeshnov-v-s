#include <iostream>


int main() {
  int n = 0;
  int k = 0;
  int f_max = -100000000000;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int f = 0;
    int t = 0;
    std::cin >> f >> t;
    if (t > k) {
      f = f - (t - k);
      f_max = std::max(f_max, f);
    }
    else {
      f_max = std::max(f_max, f);
    }
  }
  std::cout << f_max << std::endl;
  return 0;
}