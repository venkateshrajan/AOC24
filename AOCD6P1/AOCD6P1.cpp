// AOCD6P1.cpp : Defines the entry point for the application.
//

#include "AOCD6P1.h"

using namespace std;

set<pair<int, int>> visited;
array<int, 4> dirval = { -1, 0, 1, 0 };

int moveNext(vector<pair<int, int>> obs, pair<int, int> dir, pair<int, int> pos, int n) {
	auto [r, c] = pos;
	if (r < 0 || c < 0)
		return 0;

	if (r >= n || c >= n)
		return 0;

	bool isVisited = visited.contains(make_pair(r, c));
	auto &[x, y] = dir;
	int nr = r + dirval[x];
	int nc = c + dirval[y];
	while (ranges::find(obs, make_pair(nr, nc)) != obs.end()) {
		// rotate
		x = ++x % 4;
		y = ++y % 4;

		nr = r + dirval[x];
		nc = c + dirval[y];
	}

	if (!isVisited)
		visited.insert({ r, c });
	int res = moveNext(obs, dir, { nr, nc }, n);

	return isVisited? res : 1 + res;
}

int main()
{
	string_view input = R"(....#.....
.........#
..........
..#.......
.......#..
..........
.#..^.....
........#.
#.........
......#...)";
	auto input_view = input | views::split('\n');
	ifstream ifs("input.txt");

	vector<pair<int, int>> obs;
	int r = 0;
	pair<int, int> startPos;
	ranges::for_each(views::istream<string>(ifs), [&](auto const& view) {
		int c = 0;
		ranges::for_each(view, [&](auto const& view) {
			if (view == '#')
				obs.push_back({ r, c });
			else if (view == '^')
				startPos = { r, c };
			c++;
		});
		r++;
	});

	int answer = moveNext(obs, {0, 1}, startPos, r);
	cout << "Answer: " << answer << endl;

	return 0;
}
