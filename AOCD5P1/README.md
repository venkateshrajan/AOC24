# [Day 5: Part 1](https://adventofcode.com/2024/day/5)

- Add the rules in a map with key as the first number and value inserted into a vector
- For every two numbers in update (x, y) and check if the x has a rule
    - If it doesn't then check if the y has a rule
        - If yes, then if the x is part of the rule then its not a correct update.
    - If it has then check if the y is part of the rule
        - If no, then check if the y has a rule for the x
            - if yes, then its not a correct update.

	
