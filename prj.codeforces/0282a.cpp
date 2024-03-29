#include <iostream>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  int count = 0;
  while (n > 0) {
    std::string s;
    std::cin >> s;
    if (s[0] == '+' || s[2] == '+' ? count++ : count--) {};
    --n;
  }
  std::cout << count;
  return 0;
}