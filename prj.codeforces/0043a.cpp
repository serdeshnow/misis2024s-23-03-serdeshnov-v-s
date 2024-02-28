#include <iostream>
#include <string>

int main() {
	int amt_of_games = 0;
	std::string team_a;
	std::string team_b = "-1";
	std::string new_str;
	int cnt_a = 0;
	int cnt_b = 0;

	std::cin >> amt_of_games;
	for (int i = 0; i < amt_of_games; ++i) {
		if (i == 0) {
			std::cin >> team_a;
			cnt_a += 1;
		} else {
			std::cin >> new_str;
			if ("-1" == team_b && new_str != team_a) {
				team_b = new_str;
			}
			if (new_str == team_a ? cnt_a += 1 : cnt_b += 1);
		}
	}

	if (cnt_a > cnt_b ? std::cout << team_a : std::cout << team_b);

	return 0;
}
