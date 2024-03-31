#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  int count_islands = 1;
  int prev_magnet = 0;
  for (int i = 0; i < n; ++i) {
    int magnet = 0;
    std::cin >> magnet;
    if (prev_magnet == 0) {
      prev_magnet = magnet;
    } else if (magnet != prev_magnet) {
      count_islands++;
      prev_magnet = magnet;
    }
  }
  std::cout << count_islands;
  return 0;
}