#include <iostream>
#include <array>
#include <algorithm>

int main() {
  std::array <int, 3> arr;
  for (int i = 0; i < 3; ++i) {
    int a = 0;
    std::cin >> a;
    arr[i] = a;
  }
  std::sort(arr.begin(), arr.end());
  int length = 0;

  for (int j = 1; j < 3; ++j) {
    length += (arr[j] - arr[j - 1]);
  }
  std::cout << length << std::endl;


  return 0;
}