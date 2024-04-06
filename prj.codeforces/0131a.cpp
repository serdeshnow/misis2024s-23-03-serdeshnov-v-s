#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;
  bool other_upper = true;
  for (int i = 1; i < str.size(); ++i) {
    if (isupper(str[i]) ? other_upper *= 1 : other_upper *= 0) {}
  }
  if (isupper(str[0]) == true && other_upper) {
    for (int j = 0; j < str.size(); ++j) {
      str[j] = tolower(str[j]);
    }
  } else if (isupper(str[0]) == false && other_upper) {
    str[0] = toupper(str[0]);
    for (int j = 1; j < str.size(); ++j) {
      str[j] = tolower(str[j]);
    }
  }
  std::cout << str;
  return 0;
}
