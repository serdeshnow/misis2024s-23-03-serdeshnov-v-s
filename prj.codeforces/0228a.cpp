#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector <int> arr(4);
  for (int i = 0; i < 4; ++i) {
    long long int p = 0;
    std::cin >> p;
    arr[i] = p;
  }
  sort(arr.begin(), arr.end());
  arr.erase (unique(arr.begin(), arr.end()), arr.end());
  std::cout << 4 - arr.size();
  return 0;
}
