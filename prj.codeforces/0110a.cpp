#include <iostream>

int main() {
  int cnt_l = 0;
  long long int num = 0;
//  long long int num = 4744000695826;
  std::cin >> num;
  while (num != 0) {
    if ((num % 10 == 4 || num % 10 == 7) ? ++cnt_l : cnt_l += 0) {}
    num /= 10;
  }
  if(cnt_l % 10 == 4 || cnt_l % 10 == 7 ? std::cout << "YES": std::cout << "NO") {}
  return 0;
}
