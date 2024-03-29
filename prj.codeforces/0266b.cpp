#include <iostream>
#include <string>

int main() {
  int n = 0;
  int t = 0;
  std::cin >> n >> t;
  std::string str;
  std::cin >> str;
  if( n == 2 ){
    if (str == "BB") {
      std::cout << "BB";
    }
    if (str == "BG" || str == "GB") {
      std::cout << "GB";
    }
    if (str == "GG") {
      std::cout << "GG";
    }
    return 0;
  }
  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < str.size() - 1; ++j) {
      if (str[j] == 'B' && str[j + 1] == 'G') {
        str[j] = 'G';
        str[j + 1] = 'B';
        j++;
      }
    }
  }
  std::cout << str;
  return 0;
}