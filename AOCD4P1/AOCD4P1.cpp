// AOCD4P1.cpp : Defines the entry point for the application.
//

#include "AOCD4P1.h"

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

int findXMAS(const vector<vector<char>>& board, int i, int j) {
	int answer = 0;

	// Horizontal
	if ((j + 3) < board[i].size())
	{
		if (board[i][j] == 'X'
			&& board[i][j + 1] == 'M'
			&& board[i][j + 2] == 'A'
			&& board[i][j + 3] == 'S')
			answer++;
	}

	// Reverse Horizontal
	if ((j - 3) >= 0)
	{
		if (board[i][j] == 'X'
			&& board[i][j - 1] == 'M'
			&& board[i][j - 2] == 'A'
			&& board[i][j - 3] == 'S')
			answer++;
	}

	// Vertical 
	if ((i + 3) < board.size())
	{
		if (board[i][j] == 'X'
			&& board[i + 1][j] == 'M'
			&& board[i + 2][j] == 'A'
			&& board[i + 3][j] == 'S')
			answer++;
	}

	// Reverse Vertical
	if ((i - 3) >= 0)
	{
		if (board[i][j] == 'X'
			&& board[i - 1][j] == 'M'
			&& board[i - 2][j] == 'A'
			&& board[i - 3][j] == 'S')
			answer++;
	}

	// Main Diagonal
	if ((i + 3) < board.size())
	{
		if (board[i][j] == 'X'
			&& (j + 1) < board[i + 1].size() && board[i + 1][j + 1] == 'M'
			&& (j + 2) < board[i + 2].size() && board[i + 2][j + 2] == 'A'
			&& (j + 3) < board[i + 3].size() && board[i + 3][j + 3] == 'S')
			answer++;
	}

	// Reverse Main Diagonal
	if ((i - 3) >= 0 && (j - 3) >= 0)
	{
		if (board[i][j] == 'X'
			&& board[i - 1][j - 1] == 'M'
			&& board[i - 2][j - 2] == 'A'
			&& board[i - 3][j - 3] == 'S')
			answer++;
	}

	// Anti Diagonal
	if ((i + 3) < board.size() && (j - 3) >= 0)
	{
		if (board[i][j] == 'X'
			&& board[i + 1][j - 1] == 'M'
			&& board[i + 2][j - 2] == 'A'
			&& board[i + 3][j - 3] == 'S')
			answer++;
	}

	// Reverse Anti Diagonal
	if ((i - 3) >= 0)
	{
		if (board[i][j] == 'X'
			&& (j + 1) < board[i - 1].size() && board[i - 1][j + 1] == 'M'
			&& (j + 2) < board[i - 2].size() && board[i - 2][j + 2] == 'A'
			&& (j + 3) < board[i - 3].size() && board[i - 3][j + 3] == 'S')
			answer++;
	}

	return answer;
}

int main()
{
	string input = R"(..X...
.SAMX.
.A..A.
XMAS.S
.X....)";

	input = R"(MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX)";

	input = R"(....XXMAS.
.SAMXMS...
...S..A...
..A.A.MS.X
XMASAMX.MM
X.....XA.A
S.S.S.S.SS
.A.A.A.A.A
..M.M.M.MM
.X.X.XMASX)";

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

	int answer = 0;
	for (size_t i = 0; i < board.size(); i++) {
		for (size_t j = 0; j < board[i].size(); j++) {
			answer += findXMAS(board, i, j);
		}
	}

	cout << "Answer: " << answer << endl;

	return 0;
}
