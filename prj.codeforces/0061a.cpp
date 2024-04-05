#include <iostream>
#include <string>

int main() {
  std::string a;
  std::string b;
  std::cin >> a >> b;
  std::string result;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      result += '1';
    }else{
      result += '0';
    }
  }
  std::cout << result;
  return 0;
}