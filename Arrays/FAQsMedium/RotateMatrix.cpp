#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Rotates a square matrix by 90 degrees clockwise in-place.
 *
 * Performs an in-place clockwise rotation of the given square matrix by
 * first transposing the matrix and then reversing each row.
 *
 * Algorithm:
 * 1. Transpose the matrix by swapping grid[i][j] with grid[j][i] for all
 *    i < j.
 * 2. Reverse every row of the transposed matrix.
 *
 * Example:
 * Input:
 * {
 *   {1, 2, 3},
 *   {4, 5, 6},
 *   {7, 8, 9}
 * }
 *
 * After modification:
 * {
 *   {7, 4, 1},
 *   {8, 5, 2},
 *   {9, 6, 3}
 * }
 *
 * Note:
 * - The input matrix must be square (N × N).
 * - The rotation is performed in-place using O(1) extra space.
 *
 * @param grid The square matrix to be rotated.
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */
void rotateMatrix(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < col; j++) {
            swap(grid[i][j], grid[j][i]);
        }
    }

    for (auto &it : grid) {
        reverse(it.begin(), it.end());
    }
}