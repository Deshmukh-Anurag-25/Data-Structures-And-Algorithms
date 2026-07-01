#include <vector>
using namespace std;

/**
 * @brief Searches for a target value in a row-wise and column-wise sorted matrix.
 *
 * Starts from the top-right corner of the matrix and eliminates either an
 * entire row or an entire column in each step:
 * - If the current element is smaller than the target, move down to the
 *   next row.
 * - If the current element is larger than the target, move left to the
 *   previous column.
 *
 * This approach is valid when:
 * - Each row is sorted in non-decreasing order from left to right.
 * - Each column is sorted in non-decreasing order from top to bottom.
 *
 * Example:
 * matrix = {
 *   {1, 4, 7, 11, 15},
 *   {2, 5, 8, 12, 19},
 *   {3, 6, 9, 16, 22},
 *   {10, 13, 14, 17, 24},
 *   {18, 21, 23, 26, 30}
 * }
 * target = 5
 *
 * Returns:
 * true
 *
 * Example:
 * matrix = {
 *   {1, 4, 7, 11, 15},
 *   {2, 5, 8, 12, 19},
 *   {3, 6, 9, 16, 22},
 *   {10, 13, 14, 17, 24},
 *   {18, 21, 23, 26, 30}
 * }
 * target = 20
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Start at the top-right corner of the matrix.
 * 2. Compare the current element with the target.
 * 3. If the current element equals the target, return true.
 * 4. If the current element is smaller than the target, move down.
 * 5. Otherwise, move left.
 * 6. Repeat until the target is found or the search leaves the matrix.
 *
 * Note:
 * - The matrix must satisfy the properties of LeetCode 240:
 *   - Each row is sorted in non-decreasing order.
 *   - Each column is sorted in non-decreasing order.
 * - The function returns true if the target exists; otherwise, false.
 *
 * @param matrix The row-wise and column-wise sorted 2D matrix.
 * @param target The value to search for.
 * @return bool True if the target is present; otherwise, false.
 *
 * Time Complexity: O(rows + cols)
 * Space Complexity: O(1)
 */
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int r = 0, c = cols - 1;

    while (r < rows && c >= 0) {
        if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] < target) {
            r++;
        } else {
            c--;
        }
    }

    return false;
}