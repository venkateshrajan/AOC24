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

//	string input = R"(7 6 4 2 1
//1 2 7 8 9
//9 7 6 2 1
//1 3 2 4 5
//8 6 4 4 1
//1 3 6 7 9)";
//	lines = split(input, '\n');
//	lines.clear();

	ifstream ifs("./input.txt");
	string line;
	while (getline(ifs, line)) {
		lines.push_back(line);
	}

	int total = 0;
	for (const string& report : lines) {
		vector<string> levels = split(report, ' ');
		size_t n = levels.size();
		// my data set doesn't have this.
		/*if (n <= 1) {
			total++;
			continue;
		}*/
		int a = atoi(levels[0].c_str());
		int b = atoi(levels[1].c_str());
		if (a == b) continue;
		bool asc = a < b;
		bool safe = true;
		for (size_t i = 1; i < n-1; i++) {
			a = asc ? atoi(levels[i + 1].c_str()) : atoi(levels[i].c_str());
			b = asc ? atoi(levels[i].c_str()) : atoi(levels[i + 1].c_str());
			int d = a - b;
			if (d < 1 || d > 3) {
				safe = false;
				break;
			}
		}

		if (safe) total++;
	}

	cout << "Answer: " << total << endl;

	return 0;
}
