#include <iostream>
#include <vector>
#include <cstdint>


int main() {
  int64_t n = 0;
  int64_t m = 0;

  int64_t count = 0;
  int64_t pos = 1;
  int64_t new_pos = 0;

  std::cin >> n >> m;
  for (int64_t i = 0; i < m; ++i) {
    std::cin >> new_pos;
    if (pos > new_pos) {
      count += (n + new_pos - pos);
    }
    else {
      count += (new_pos - pos);
    }
    pos = new_pos;
  }
  std::cout << count;
  return 0;
}