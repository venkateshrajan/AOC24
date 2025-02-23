// AOCD3P2.cpp : Defines the entry point for the application.
//

#include "AOCD3P2.h"

using namespace std;

struct S {
	size_t pos;
	int a, b;
};

int main()
{
	string input = R"(do()xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5)))";

	ifstream ifs("input.txt");
	stringstream buffer;
	buffer << ifs.rdbuf();
	input = buffer.str();

	string mul = input;
	regex re{ R"(mul\([0-9][0-9]?[0-9]?,[0-9][0-9]?[0-9]?\))" }; // don't have any leading zeroes in my input
	vector<S> muls;
	size_t pos = 0;
	for (smatch sm; regex_search(mul, sm, re); mul = sm.suffix()) {
		pos += sm.prefix().length();
		string m = mul.substr(mul.find(sm[0]), string(sm[0]).size());
		size_t cpos = m.find(',');
		muls.push_back(S{ 
			pos,
			atoi(m.substr(4, cpos - 4).c_str()), 
			atoi(m.substr(cpos + 1, m.find(')') - cpos).c_str()) 
		});
		pos += string(sm[0]).size();
	}

	string doi = input;
	re = R"(do\(\))";
	vector<size_t> do_pos;
	pos = 0;
	for (smatch sm; regex_search(doi, sm, re); doi = sm.suffix()) {
		pos += sm.prefix().length();
		do_pos.push_back(pos);
		pos += string(sm[0]).size();
	}

	string donti = input;
	re = R"(don't\(\))";
	vector<size_t> dont_pos;
	pos = 0;
	for (smatch sm; regex_search(donti, sm, re); donti = sm.suffix()) {
		pos += sm.prefix().length();
		dont_pos.push_back(pos);
		pos += string(sm[0]).size();
	}

	int answer = 0;
	bool domul = true;
	size_t doidx = 0, dontidx = 0;
	for (const S& s : muls) {
		while (doidx + 1 < do_pos.size() && do_pos[doidx + 1] < s.pos) doidx++;
		while (dontidx + 1 < dont_pos.size() && dont_pos[dontidx + 1] < s.pos) dontidx++;
		if (do_pos[doidx] < s.pos && dont_pos[dontidx] < s.pos) domul = do_pos[doidx] > dont_pos[dontidx];
		else if (do_pos[doidx] < s.pos) domul = true;
		else if (dont_pos[dontidx] < s.pos) domul = false;
		if (domul) answer += s.a * s.b;
	}
	cout << "Answer: " << answer << endl;

	return 0;
}
