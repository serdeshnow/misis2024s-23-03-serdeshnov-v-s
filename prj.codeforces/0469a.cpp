#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector <int> arr;

  int little_x = 0;
  std::cin >> little_x;
  for (int i = 0; i < little_x; ++i) {
    int x = 0;
    std::cin >> x;
    arr.push_back(x);
  }

  int little_y = 0;
  std::cin >> little_y;
  for (int j = 0; j < little_y; ++j) {
    int y = 0;
    std::cin >> y;
    arr.push_back(y);
  }

  sort( arr.begin(), arr.end() );
  arr.erase( unique( arr.begin(), arr.end() ), arr.end() );
  if (arr.size() == n ? std::cout << "I become the guy." : std::cout << "Oh, my keyboard!"){}

  return 0;
}