// AOCD3P2.cpp : Defines the entry point for the application.
//

#include "AOCD3P2.h"

using namespace std;

int main()
{
	string input = R"(xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5)))";

	ifstream ifs("input.txt");
	stringstream buffer;
	buffer << ifs.rdbuf();
	input = buffer.str();

	int answer = 0;
	const regex re{ R"(mul\([0-9][0-9]?[0-9]?,[0-9][0-9]?[0-9]?\))" }; // don't have any leading zeroes in my input
	for (smatch sm; regex_search(input, sm, re); input = sm.suffix()) {
		string m = input.substr(input.find(sm[0]), string(sm[0]).size());
		size_t pos = m.find(',');
		int a = atoi(m.substr(4, pos - 4).c_str());
		int b = atoi(m.substr(pos + 1, m.find(')') - pos).c_str());
		answer += a * b;
	}

	cout << "Answer: " << answer << endl;

	return 0;
}
