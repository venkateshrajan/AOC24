# [Day 3: Part 1](https://adventofcode.com/2024/day/3)

```bash
mul\([0-9][0-9]?[0-9]?,[0-9][0-9]?[0-9]?\)
```
I know I could have optimized this regex but didn't bother too much

## Explanation

- `[0-9]` - Matches any number from 0 to 9 inclusive
- `[0-9]?` - Matches empty or any number from 0 to 9 inclusive
- `[0-9][0-9]?[0-9]?` - Matches any single digit, two digit and three digit number
- `\(` / `\)` - '(' / ')' has meaning in regex so escaping it to match
- `mul\([0-9][0-9]?[0-9]?,[0-9][0-9]?[0-9]?\)` - matches 'mul(x,y)' 
where x and y can be any number from 0 to 999
	
