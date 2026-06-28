#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Rotates the elements of a vector to the left by k positions.
 *
 * Performs an in-place left rotation using the reversal algorithm.
 * The value of k is normalized using the size of the vector to handle
 * cases where k is greater than the number of elements.
 *
 * Example:
 * nums = {1, 2, 3, 4, 5}
 * k = 2
 *
 * After rotation:
 * {3, 4, 5, 1, 2}
 *
 * Algorithm:
 * 1. Reverse the first k elements.
 * 2. Reverse the remaining n - k elements.
 * 3. Reverse the entire vector.
 *
 * Note:
 * - The input vector must contain at least one element.
 * - Rotation is performed in-place using O(1) extra space.
 *
 * @param nums The vector of integers to be rotated.
 * @param k The number of positions to rotate the vector to the left.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void leftRotateBy(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}