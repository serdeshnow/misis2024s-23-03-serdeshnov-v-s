#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  bool is_hard_flag = false;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    std::cin >> a;
    if (a == 1) {
      is_hard_flag = true;
    }
  }
  if(is_hard_flag ? std::cout << "HARD" : std::cout << "EASY"){}
  return 0;
}
