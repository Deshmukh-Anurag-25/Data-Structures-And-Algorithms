#include <string>
#include <vector>
using namespace std;

/**
 * @brief Performs backtracking to determine whether the given word can be
 * formed starting from a specific cell.
 *
 * The function explores the board in four directions (up, down, left, right)
 * while ensuring that each cell is used at most once in the current path.
 *
 * A visited cell is temporarily marked with '#' and restored after exploring
 * all possible paths (backtracking).
 *
 * @param index Current character index in the word.
 * @param row Current row in the board.
 * @param col Current column in the board.
 * @param board Character grid.
 * @param word Target word to search.
 * @return bool True if the remaining word can be formed; otherwise false.
 *
 * Time Complexity: O(4^L)
 * Space Complexity: O(L)
 * where:
 * - L = length of the word.
 */
bool solve(int index,
           int row,
           int col,
           vector<vector<char>>& board,
           const string& word) {

    // Entire word has been matched.
    if (index == word.size())
        return true;

    // Out of bounds.
    if (row < 0 || row >= board.size() ||
        col < 0 || col >= board[0].size())
        return false;

    // Character mismatch.
    if (board[row][col] != word[index])
        return false;

    // Mark the current cell as visited.
    char original = board[row][col];
    board[row][col] = '#';

    bool found =
        solve(index + 1, row + 1, col, board, word) ||
        solve(index + 1, row - 1, col, board, word) ||
        solve(index + 1, row, col + 1, board, word) ||
        solve(index + 1, row, col - 1, board, word);

    // Restore the original character (backtracking).
    board[row][col] = original;

    return found;
}

/**
 * @brief Determines whether a word exists in a character grid.
 *
 * The word can be constructed by moving horizontally or vertically to
 * adjacent cells. Each cell may be used only once in a single path.
 *
 * Example:
 * Board:
 * A B C E
 * S F C S
 * A D E E
 *
 * Word:
 * "ABCCED"
 *
 * Path:
 * A → B → C → C → E → D
 *
 * Returns:
 * true
 *
 * Example:
 * Word:
 * "ABCB"
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Try every cell as the starting position.
 * 2. Perform a DFS with backtracking.
 * 3. Match one character at a time.
 * 4. Temporarily mark visited cells to prevent reuse.
 * 5. Restore the board after exploring each path.
 * 6. Return true as soon as the complete word is found.
 *
 * Note:
 * - Cells may be revisited in different search paths, but never twice in
 *   the same path.
 * - Backtracking ensures the board is restored after each recursive call.
 *
 * @param board Character grid.
 * @param word Word to search for.
 * @return bool True if the word exists in the grid; otherwise false.
 *
 * Time Complexity: O(m × n × 4^L)
 * Space Complexity: O(L)
 * where:
 * - m = number of rows.
 * - n = number of columns.
 * - L = length of the word.
 */
bool exist(vector<vector<char>>& board, string word) {

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {

            if (solve(0, row, col, board, word))
                return true;
        }
    }

    return false;
}