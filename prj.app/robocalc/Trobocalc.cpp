#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

struct Command {
	std::string type;
	double value;
	std::function<void(double&)> operation;
};

class Assembler {
private:
	double out = 0.0;
	std::vector<Command> commands;
	std::vector<Command> history;

public:
	static void ADD(double& prev, const double val) {
		prev += val;
	}
	static void SUB(double& prev, const double val) {
		prev -= val;
	}
	static void MUL(double& prev, const double val) {
		prev *= val;
	}
	static void DIV(double& prev, const double val) {
		prev /= val;
	}

	void execute(const std::string& line) {
		std::istringstream iss(line);
		std::string commandType;
		double value = 0.0;
		iss >> commandType;

		if (commandType != "REV") {
			iss >> value;
		}

		Command cmd;
		cmd.type = commandType;
		cmd.value = value;

		if (commandType == "ADD") {
//			cmd.operation = [value](double& out) { out += value; };
			Assembler::ADD(out, value);
		} else if (commandType == "SUB") {
			cmd.operation = [value](double& out) { out -= value; };
		} else if (commandType == "MUL") {
			cmd.operation = [value](double& out) { out *= value; };
		} else if (commandType == "DIV") {
			cmd.operation = [value](double& out) { out /= value; };
		} else if (commandType == "REV") {
			int count = static_cast<int>(value);
			while (count-- > 0 && !history.empty()) {
				history.pop_back();
			}
			out = 0.0; // Reset OUT
			for (const auto& cmd : history) {
				cmd.operation(out);
			}
			return;
		}

		cmd.operation(out);
		history.push_back(cmd);
	}

	void printOut() const {
		std::cout << "OUT: " << out << std::endl;
	}
};

int main() {
	Assembler asmblr;
	std::string line;

	while (getline(std::cin, line)) {
		if (line == "EXIT") break;
		asmblr.execute(line);
		asmblr.printOut();
	}

	return 0;
}

