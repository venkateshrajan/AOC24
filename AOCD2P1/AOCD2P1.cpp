// AOCD2P1.cpp : Defines the entry point for the application.
//

#include "AOCD2P1.h"

using namespace std;

vector<string> split(const string& str, char delimiter) {
	vector<string> tokens;
	istringstream istrs(str);
	string line;
	while (getline(istrs, line, delimiter)) {
		tokens.push_back(line);
	}
	return tokens;
}

int main()
{
	vector<string> lines;

	string input = R"(7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9)";
	lines = split(input, '\n');

	lines.clear();
	ifstream ifs("./input.txt");
	string line;
	while (getline(ifs, line)) {
		lines.push_back(line);
	}

	int total = 0;
	for (const string& report : lines) {
		vector<string> levels = split(report, ' ');
		size_t n = levels.size();
		set<int> pos{ 1, 2, 3 };
		set<int> neg{ -1, -2, -3 };
		for (size_t i = 1; i < n; i++) {
			int a = atoi(levels[i].c_str());
			int b = atoi(levels[i-1].c_str());
			pos.insert(a - b);
			neg.insert(a - b);
		}
		if (pos.size() == 3 || neg.size() == 3) total++;
	}

	cout << "Answer: " << total << endl;

	return 0;
}
