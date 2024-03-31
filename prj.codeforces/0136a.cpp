#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector <int> arr(n);
  for (int i = 0; i < n; ++i) {
    int present_to = 0;
    std::cin >> present_to;
    arr[present_to - 1] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  return 0;
}