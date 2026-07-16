#include <vector>
using namespace std;

/**
 * @brief Checks whether a digit can be placed in a given Sudoku cell.
 *
 * A placement is valid if the digit does not already exist in:
 * - The same row.
 * - The same column.
 * - The corresponding 3 × 3 subgrid.
 *
 * @param board 9 × 9 Sudoku board.
 * @param row Row index of the cell.
 * @param col Column index of the cell.
 * @param digit Digit to place ('1' to '9').
 * @return bool True if the placement is valid; otherwise false.
 *
 * Time Complexity: O(9)
 * Space Complexity: O(1)
 */
bool isValid(vector<vector<char>>& board, int row, int col, char digit) {

    for (int i = 0; i < 9; i++) {

        // Check the current column.
        if (board[i][col] == digit)
            return false;

        // Check the current row.
        if (board[row][i] == digit)
            return false;

        // Check the corresponding 3 × 3 subgrid.
        if (board[3 * (row / 3) + i / 3]
                 [3 * (col / 3) + (i % 3)] == digit)
            return false;
    }

    return true;
}

/**
 * @brief Solves the Sudoku puzzle using backtracking.
 *
 * The function searches for the first empty cell ('.'). It then tries every
 * digit from '1' to '9'. If a digit is valid, it is placed and the remaining
 * board is solved recursively.
 *
 * If no digit leads to a solution, the function backtracks by restoring the
 * cell to '.'.
 *
 * @param board 9 × 9 Sudoku board.
 * @return bool True if the puzzle can be solved; otherwise false.
 *
 * Time Complexity: Exponential (worst case)
 * Space Complexity: O(81) due to recursion depth.
 */
bool solve(vector<vector<char>>& board) {

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {

            if (board[row][col] == '.') {

                for (char digit = '1'; digit <= '9'; digit++) {

                    if (isValid(board, row, col, digit)) {

                        board[row][col] = digit;

                        if (solve(board))
                            return true;

                        // Backtrack.
                        board[row][col] = '.';
                    }
                }

                // No valid digit can be placed.
                return false;
            }
        }
    }

    // Entire board has been filled successfully.
    return true;
}

/**
 * @brief Solves a 9 × 9 Sudoku puzzle in-place.
 *
 * The Sudoku board contains digits '1' to '9' and empty cells represented
 * by '.'. The function fills every empty cell while satisfying the Sudoku
 * rules:
 * - Each row contains digits 1–9 exactly once.
 * - Each column contains digits 1–9 exactly once.
 * - Each 3 × 3 subgrid contains digits 1–9 exactly once.
 *
 * Example:
 *
 * Input:
 * 5 3 . . 7 . . . .
 * 6 . . 1 9 5 . . .
 * . 9 8 . . . . 6 .
 * 8 . . . 6 . . . 3
 * 4 . . 8 . 3 . . 1
 * 7 . . . 2 . . . 6
 * . 6 . . . . 2 8 .
 * . . . 4 1 9 . . 5
 * . . . . 8 . . 7 9
 *
 * Output:
 * The board is modified in-place into a valid Sudoku solution.
 *
 * Algorithm:
 * 1. Find the first empty cell.
 * 2. Try every digit from '1' to '9'.
 * 3. If a digit satisfies Sudoku rules, place it.
 * 4. Recursively solve the remaining board.
 * 5. If no digit works, undo the placement (backtracking).
 * 6. Continue until the board is completely filled.
 *
 * Note:
 * - The puzzle is guaranteed to have a unique solution.
 * - The board is modified directly.
 *
 * @param board 9 × 9 Sudoku board to solve.
 *
 * Time Complexity: Exponential (worst case)
 * Space Complexity: O(81)
 */
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}