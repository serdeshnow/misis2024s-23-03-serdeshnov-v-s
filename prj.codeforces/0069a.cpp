#include <iostream>

int main() {
	int n = 0;
	int res_x = 0;
	int res_y = 0;
	int res_z = 0;

	std::cin >> n;
	for(int i = 0; i < n; ++i) {
		int x = 0;
		int y = 0;
		int z = 0;
		std::cin >> x >> y >> z;
		res_x += x;
		res_y += y;
		res_z += z;
	}
	bool flag = (res_x == 0 && res_y == 0 && res_z == 0);
	if (flag) {
		std::cout << "YES";
	} else{
		std::cout << "NO";
	}
	return 0;
}
