#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::vector<std::string> arr(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    arr[i] = str.substr(i, 2);
  }
  std::string result = arr[0];
  std::sort(arr.begin(), arr.end());
  int max_count = 1;
  int count_now = 1;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == arr[i + 1]) {
      ++count_now;
    } else {
      if (max_count < count_now) {
        max_count = std::max(max_count, count_now);
        result = arr[i];
      }
      count_now = 1;
    }
  }
  std::cout << result;
  return 0;
}