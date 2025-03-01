# [Day 6: Part 1](https://adventofcode.com/2024/day/6)

Wanted to use new c++ 20 features so I am not even sure if the solution is anywhere closer to optimal

Observed that the stack is overflowing on debug mode with less that 2K recursive call. That's pretty small. 
If it happens, run it in release mode.

Solution wise, this is an implementation problem. Used DFS. 

	
