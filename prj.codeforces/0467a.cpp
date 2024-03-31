#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  int count_rooms = 0;
  for (int i = 0; i < n; ++i) {
    int size = 0;
    int capacity = 0;
    std::cin >> size >> capacity;
    if (capacity - size >= 2 ? count_rooms += 1: count_rooms += 0) {}
  }
  std::cout << count_rooms;
  return 0;
}