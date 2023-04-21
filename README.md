# Eight Queens Puzzle
This program solves the famous "Eight Queens Puzzle", which is a problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other. In other words, no two queens share the same row, column, or diagonal.
 
## Usage
To run the program, simply compile and execute the code in a C++ compiler. The program will print out all solutions for the puzzle, as well as the total number of solutions found.

## Implementation
The program uses a recursive backtracking algorithm to generate all possible solutions. A global 2D array is used to represent the chessboard, with each cell containing a 0 if it is empty, or a positive integer if it is occupied by a queen.

The gen() function recursively places a queen on each row of the board and marks all the squares that it threatens. The del() function removes the queen from the board, while the print() function prints out the current configuration of the board with the queens represented by the Unicode character "♕" and empty squares represented by "▢".

To change the color of the output strings, the program uses the Windows API function SetConsoleTextAttribute() to set the text color for each character that is printed.

## Future improvements
One potential improvement to the program would be to optimize the algorithm to find only the unique solutions, as there are 92 distinct solutions to the puzzle. Additionally, the program could be extended to solve the puzzle for larger chessboards with more than eight queens.

### here is one of 92 the answers

▢ ▢ ▢ ▢ ▢ ▢ ▢ ♕    
▢ ▢ ▢ ♕ ▢ ▢ ▢ ▢    
♕ ▢ ▢ ▢ ▢ ▢ ▢ ▢   
▢ ▢ ♕ ▢ ▢ ▢ ▢ ▢   
▢ ▢ ▢ ▢ ▢ ♕ ▢ ▢   
▢ ♕ ▢ ▢ ▢ ▢ ▢ ▢   
▢ ▢ ▢ ▢ ▢ ▢ ♕ ▢   
▢ ▢ ▢ ▢ ♕ ▢ ▢ ▢   