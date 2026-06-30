/**
 * @brief Computes the value at a specific position in Pascal's Triangle.
 *
 * Returns the element located at the given row and column of Pascal's
 * Triangle using the binomial coefficient formula:
 *
 *      C(r - 1, c - 1)
 *
 * where the row and column indices are 1-based.
 *
 * The value is computed iteratively to avoid calculating large factorials,
 * making the implementation more efficient.
 *
 * Example:
 * r = 5, c = 3
 *
 * Returns:
 * 6
 *
 * Explanation:
 * The 5th row of Pascal's Triangle is:
 * {1, 4, 6, 4, 1}
 * The 3rd element is 6.
 *
 * Note:
 * - Both row and column indices are 1-based.
 * - It is assumed that 1 <= c <= r.
 *
 * @param r The 1-based row number.
 * @param c The 1-based column number.
 * @return int The value at the specified position in Pascal's Triangle.
 *
 * Time Complexity: O(c)
 * Space Complexity: O(1)
 */
int pascalTriangleI(int r, int c) {
    int res = 1;
    r = r - 1;
    c = c - 1;

    for (int i = 0; i < c; i++) {
        res *= (r - i);
        res /= (i + 1);
    }

    return res;
}