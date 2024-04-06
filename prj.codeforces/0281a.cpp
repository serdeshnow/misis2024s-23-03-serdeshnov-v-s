#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;
  str[0] = toupper(str[0]);
  std::cout << str;
  return 0;
}
