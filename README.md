# Sudoku-Solver-w-Genetic-Algorithms
This project is an interesting experiment of solving sudoku with a genetic algorithm. A genetic algorithm is roughly simulating life on Earth with different generations and populations. While the runtime may be slow and a solution not guarranteed, this is an interesting and fun project.

Results (Population Size: 10000, Selection Rate: 25%, Random selection rate 25%, Mutation rate: 10%, # of children: 4)
        Limits vary based on task

Major Optimizations:
    Made parent selection faster (I previously was erasing elements in the middle of a vector making the function O(n^2))
    Instead I loop from the end to make the selection fast

    Made the mutation algorithm switch two values in a box rather than two whole boxes
    The previous mutation algorithm hurt the fitness level

----
EASY
----
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0

Solved in 23 seconds (0 minutes 23 seconds), 11 generations, 0 restarts, 2500 population size GA
Solved in 43 seconds (0 minutes 43 seconds), 10 generations, 0 restarts, 5000 population size GA
Solved in 78 seconds (1 minutes 18 seconds), 9 generations, 0 restarts, 10000 population size GA
Solved in 0 seconds BACKTRACKING

------
MEDIUM
------
7 0 0 0 3 6 0 4 0
0 4 0 1 0 0 0 7 0
3 0 0 0 0 0 1 0 0
5 3 0 0 0 0 0 0 0
2 0 9 6 4 0 0 0 0
0 6 0 9 7 0 0 8 0
0 2 0 7 0 4 0 0 5
0 0 0 0 0 8 0 0 4
0 5 4 0 6 9 0 0 1

Solved in 1215 seconds (20 minutes 55 seconds), 18 generations, 2 restarts, 25000 population size GA
Solved in 0 seconds BACKTRACKING

----
HARD
----
0 0 0 2 0 0 0 6 3
3 0 0 0 0 5 4 0 1
0 0 1 0 0 3 9 8 0
0 0 0 0 0 0 0 9 0
0 0 0 5 3 8 0 0 0
0 3 0 0 0 0 0 0 0
0 2 6 3 0 0 5 0 0
5 0 3 7 0 0 0 0 8
4 7 0 0 0 1 0 0 0

Solved in 0 seconds BACKTRACKING

------
EXPERT
------
0 0 1 6 0 0 0 0 2
0 4 0 0 3 0 8 0 0
6 5 0 0 0 0 0 0 3
2 0 0 0 7 3 0 0 0
0 0 0 9 0 1 2 0 0
0 0 0 0 4 0 9 0 0
8 0 3 1 0 0 0 0 0
0 7 0 0 0 0 0 0 8
9 1 0 0 0 0 0 0 7

Solved in 0 seconds BACKTRACKING

-----------
AI ESCARGOT
-----------
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0 
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0 
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0

Ran out of patience after more than ~25000 generations, ~28 restarts, 8.5 hours, 10000 population size