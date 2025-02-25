// AOCD4P2.cpp : Defines the entry point for the application.
//

#include "AOCD4P2.h"

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

int findXMAS(const vector<vector<char>>& board, size_t i, size_t j) {
	if (board[i][j] != 'A') 
		return 0;

	if ((board[i - 1][j - 1] == 'M') && (board[i + 1][j + 1] == 'S')
		&& (board[i - 1][j + 1] == 'M') && (board[i + 1][j - 1] == 'S'))
		return 1;

	if ((board[i - 1][j - 1] == 'M') && (board[i + 1][j + 1] == 'S')
		&& (board[i - 1][j + 1] == 'S') && (board[i + 1][j - 1] == 'M'))
		return 1;

	if ((board[i - 1][j - 1] == 'S') && (board[i + 1][j + 1] == 'M')
		&& (board[i - 1][j + 1] == 'M') && (board[i + 1][j - 1] == 'S'))
		return 1;

	if ((board[i - 1][j - 1] == 'S') && (board[i + 1][j + 1] == 'M')
		&& (board[i - 1][j + 1] == 'S') && (board[i + 1][j - 1] == 'M'))
		return 1;

	return 0;
}

int main()
{
	string input = R"(M.S
.A.
M.S)";

	input = R"(.M.S......
..A..MSMS.
.M.S.MAA..
..A.ASMSM.
.M.S.M....
..........
S.S.S.S.S.
.A.A.A.A..
M.M.M.M.M.
..........)";

	ifstream ifs("input.txt");
	stringstream buffer;
	buffer << ifs.rdbuf();
	input = buffer.str();

	vector<string> lines = split(input, '\n');
	vector<vector<char>> board;
	for (const string& line : lines) {
		vector<char> vec;
		for (char c : line)
			vec.push_back(c);
		board.push_back(vec);
	}

	long answer = 0;
	for (size_t i = 1; i < board.size() - 1; i++) {
		for (size_t j = 1; j < board[i].size() - 1; j++) {
			answer += findXMAS(board, i, j);
		}
	}

	cout << "Answer: " << answer << endl;

	return 0;
}
