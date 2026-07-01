#include <vector>
using namespace std;

/**
 * @brief Searches for a target value in a row-wise sorted matrix.
 *
 * Treats the matrix as a single sorted array and performs an iterative
 * binary search. The 1D index is mapped back to a 2D position using:
 *
 *      row = index / number_of_columns
 *      column = index % number_of_columns
 *
 * This approach is valid when:
 * - Each row is sorted in non-decreasing order.
 * - The first element of each row is greater than the last element of the
 *   previous row.
 *
 * Example:
 * mat = {
 *   {1, 3, 5, 7},
 *   {10, 11, 16, 20},
 *   {23, 30, 34, 60}
 * }
 * target = 3
 *
 * Returns:
 * true
 *
 * Example:
 * mat = {
 *   {1, 3, 5, 7},
 *   {10, 11, 16, 20},
 *   {23, 30, 34, 60}
 * }
 * target = 13
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Consider the matrix as a flattened sorted array of size rows × cols.
 * 2. Perform binary search on the virtual array.
 * 3. Convert the middle index to matrix coordinates:
 *    - row = mid / cols
 *    - col = mid % cols
 * 4. Compare the corresponding matrix element with the target.
 * 5. Continue until the target is found or the search space is exhausted.
 *
 * Note:
 * - The matrix must satisfy the properties of LeetCode 74:
 *   - Each row is sorted.
 *   - The first element of each row is greater than the last element of
 *     the previous row.
 * - The function returns true if the target exists; otherwise, false.
 *
 * @param mat The sorted 2D matrix.
 * @param target The value to search for.
 * @return bool True if the target is present; otherwise, false.
 *
 * Time Complexity: O(log(rows × cols))
 * Space Complexity: O(1)
 */
bool searchMatrix(vector<vector<int>> &mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();
    int left = 0, right = (rows * cols) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int el = mat[mid / cols][mid % cols];

        if (el == target)
            return true;
        else if (el < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}