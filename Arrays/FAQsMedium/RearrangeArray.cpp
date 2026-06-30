#include <vector>
using namespace std;

/**
 * @brief Rearranges an array so that positive and negative numbers appear
 *        alternately.
 *
 * Constructs a new array in which positive elements occupy the even indices
 * and negative elements occupy the odd indices. The relative order of the
 * positive elements and the relative order of the negative elements are
 * preserved.
 *
 * This implementation assumes that the number of positive and negative
 * elements is equal.
 *
 * Example:
 * nums = {3, 1, -2, -5, 2, -4}
 *
 * Returns:
 * {3, -2, 1, -5, 2, -4}
 *
 * Example:
 * nums = {1, -1, 2, -2}
 *
 * Returns:
 * {1, -1, 2, -2}
 *
 * Note:
 * - The input is assumed to contain an equal number of positive and
 *   negative integers.
 * - Positive numbers are placed at even indices (0, 2, 4, ...).
 * - Negative numbers are placed at odd indices (1, 3, 5, ...).
 * - The relative ordering of positive and negative elements is maintained.
 *
 * @param nums The input vector containing an equal number of positive and
 *             negative integers.
 * @return vector<int> A rearranged vector with alternating positive and
 *         negative elements.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    int pos = 0, neg = 1;

    for (int num : nums) {
        if (num > 0) {
            ans[pos] = num;
            pos += 2;
        } else {
            ans[neg] = num;
            neg += 2;
        }
    }

    return ans;
}