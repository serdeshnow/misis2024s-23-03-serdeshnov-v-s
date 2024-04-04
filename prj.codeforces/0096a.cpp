#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;
  int count_danger = 1;
  bool is_danger_flag = false;
  for (int i = 0; i < str.size() - 1; ++i) {
    if (str[i] == str[i+1]) {
      count_danger++;
      if (count_danger == 7) {
        is_danger_flag = true;
      }
    } else {
      count_danger = 1;
    }
  }
  if (is_danger_flag ? std::cout << "YES" : std::cout << "NO") {}
  return 0;
}