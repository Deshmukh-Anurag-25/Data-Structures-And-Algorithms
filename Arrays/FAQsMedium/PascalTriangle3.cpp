#include <vector>
using namespace std;

/**
 * @brief Generates the specified row of Pascal's Triangle.
 *
 * Returns the elements of the given row of Pascal's Triangle using an
 * iterative computation of binomial coefficients. Each element is derived
 * from the previous one, avoiding the need to compute factorials.
 *
 * The row number is 1-based.
 *
 * Example:
 * r = 5
 *
 * Returns:
 * {1, 4, 6, 4, 1}
 *
 * Algorithm:
 * 1. Initialize the row with the first element, 1.
 * 2. Compute each subsequent element using the recurrence relation:
 *      C(n, k) = C(n, k - 1) * (n - k + 1) / k
 *    where n = r - 1.
 * 3. Append each computed value to the result.
 *
 * Note:
 * - The row number is 1-based.
 * - The first and last elements of every row are always 1.
 *
 * @param r The 1-based row number of Pascal's Triangle.
 * @return vector<int> A vector containing all elements of the specified row.
 *
 * Time Complexity: O(r)
 * Space Complexity: O(r)
 */
vector<int> pascalTriangleII(int r) {
    vector<int> ans;
    ans.push_back(1);
    int res = 1;

    for (int i = 1; i < r; i++) {
        res = res * (r - i);
        res = res / i;

        ans.push_back(res);
    }

    return ans;
}

/**
 * @brief Generates the first r rows of Pascal's Triangle.
 *
 * Constructs Pascal's Triangle by generating each row individually using
 * the pascalTriangleII() function and storing the rows in a 2D vector.
 *
 * The rows are generated in ascending order, starting from the first row.
 *
 * Example:
 * r = 5
 *
 * Returns:
 * {
 *   {1},
 *   {1, 1},
 *   {1, 2, 1},
 *   {1, 3, 3, 1},
 *   {1, 4, 6, 4, 1}
 * }
 *
 * Note:
 * - The row numbering is 1-based.
 * - Each row contains one more element than the previous row.
 *
 * @param r The number of rows to generate.
 * @return vector<vector<int>> A 2D vector representing the first r rows
 *         of Pascal's Triangle.
 *
 * Time Complexity: O(r²)
 * Space Complexity: O(r²)
 */
vector<vector<int>> pascalTriangleIII(int r) {
    vector<vector<int>> ans;

    for (int i = 1; i <= r; i++) {
        ans.push_back(pascalTriangleII(i));
    }

    return ans;
}