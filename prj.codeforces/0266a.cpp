#include <iostream>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  if (n == 1) {
    std::cout << 0;
    return 0;
  }
  std::string str;
  std::cin >> str;
  int i = 0;
  int count = 0;
  for(int j = 1; j < str.size(); ++j) {
    if (str[j] == str[i] ? ++count : i = j) {}
  }
  std::cout << count;
  return 0;
}