#include <iostream>
#include <utility>
#include <algorithm>


int main() {
	int s = 0; /// strength
	int n = 0;
	std::cin >> s;
	std::cin >> n;
	std::pair <int, int> arr[n];

	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i].first >> arr[i].second;

	}
	std::sort(arr, arr + n);

	bool flag = true; /// can escape?
	for (int j = 0; j < n; ++j) {
		if (s > arr[j].first) {
			s += arr[j].second;
		} else {
			flag = false;
			break;
		}
	}

	flag ? std::cout << "YES" : std::cout << "NO";
	return 0;
}