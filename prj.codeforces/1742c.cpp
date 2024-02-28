#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int t = 0;
	std::cin >> t; // times
	for (int i = 0; i < t; ++i) {
		std::string row;
		bool red_flag = false;

		for (int j = 0; j < 8; ++j) {
			std::cin >> row;
			int R_in_row = std::count(row.begin(), row.end(), 'R');

			if (R_in_row == 8) {
				red_flag = true;
			}
		}
		if (red_flag ? std::cout << 'R' << std::endl : std::cout << "B" << std::endl) {}
	}
	return 0;
}