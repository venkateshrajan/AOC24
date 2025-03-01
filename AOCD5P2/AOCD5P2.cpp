// AOCD5P2.cpp : Defines the entry point for the application.
//

#include "AOCD5P2.h"

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

int makeCorrectUpdate(vector<int>& update, map<int, vector<int>>& rules) {
	bool correctUpdate = true;
	size_t n = update.size();
	for (size_t i = 0; i < n; i++) {
		for (size_t j = i; j < n; j++) {
			if (rules.find(update[i]) == rules.end()) {
				if (rules.find(update[j]) != rules.end()) {
					if (find(rules[update[j]].begin(), rules[update[j]].end(), update[i]) != rules[update[j]].end()) {
						correctUpdate = false;
						int temp = update[i];
						update[i] = update[j];
						update[j] = temp;
					}
				}
			}
			else {
				if (find(rules[update[i]].begin(), rules[update[i]].end(), update[j]) == rules[update[i]].end()) {
					if (rules.find(update[j]) != rules.end()) {
						if (find(rules[update[j]].begin(), rules[update[j]].end(), update[i]) != rules[update[j]].end()) {
							correctUpdate = false;
							int temp = update[i];
							update[i] = update[j];
							update[j] = temp;
						}
					}
				}
			}
		}
	}

	if (correctUpdate) return 0;

	return update[n / 2];
}

int main()
{
	string input = R"(47|53
97|13
97|61
97|47
75|29
61|13
75|53
29|13
97|29
53|29
61|53
97|53
61|29
47|13
75|47
97|75
47|61
75|61
47|29
75|13
53|13

75,47,61,53,29
97,61,53,29,13
75,29,13
75,97,47,61,53
61,13,29
97,13,75,29,47)";

	ifstream ifs("input.txt");
	stringstream buffer;
	buffer << ifs.rdbuf();
	input = buffer.str();

	vector<string> lines = split(input, '\n');
	bool rule = true;
	map<int, vector<int>> rules;
	vector<vector<int>> updates;
	for (const string& line : lines) {
		if (line.empty()) {
			rule = false;
			continue;
		}
		if (rule) {
			vector<string> splitrule = split(line, '|');
			rules[atoi(splitrule[0].c_str())].push_back(atoi(splitrule[1].c_str()));
		}
		else {
			vector<string> splitupdate = split(line, ',');
			vector<int> update;
			for (auto i : splitupdate) {
				update.push_back(atoi(i.c_str()));
			}
			updates.push_back(update);
		}
	}

	int answer = 0;
	for (vector<int>& update : updates) {
		answer += makeCorrectUpdate(update, rules);
	}
	cout << "Answer: " << answer << endl;

	return 0;
}
