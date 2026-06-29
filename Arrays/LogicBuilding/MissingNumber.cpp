#include <vector>
using namespace std;

/**
 * @brief Finds the missing number in an array containing numbers from 0 to n.
 *
 * Given a vector containing n distinct numbers from the range [0, n],
 * this function returns the single missing number using the XOR technique.
 *
 * The XOR operation cancels out identical values, leaving only the missing
 * number after XORing all array elements with the numbers from 1 to n.
 *
 * Example:
 * nums = {3, 0, 1}
 *
 * Returns:
 * 2
 *
 * Example:
 * nums = {0, 1}
 *
 * Returns:
 * 2
 *
 * Note:
 * - The input vector must contain distinct integers in the range [0, n].
 * - Exactly one number from the range is assumed to be missing.
 * - This implementation avoids integer overflow, unlike the summation approach.
 *
 * @param nums The input vector containing n distinct integers.
 * @return int The missing number in the range [0, n].
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int xorr = 0;

    for (int i = 0; i < n; i++) {
        xorr ^= nums[i] ^ (i + 1);
    }

    return xorr;
}