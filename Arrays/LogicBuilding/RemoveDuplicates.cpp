#include <vector>
using namespace std;

/**
 * @brief Removes duplicate elements from a sorted vector in-place.
 *
 * Uses the two-pointer technique to overwrite duplicate elements while
 * preserving the relative order of the unique elements. The function
 * returns the number of unique elements remaining after the operation.
 *
 * Example:
 * nums = {1, 1, 2, 2, 3}
 *
 * After modification:
 * nums = {1, 2, 3, _, _}
 *
 * Returns:
 * 3
 *
 * Example:
 * nums = {1, 2, 3}
 *
 * After modification:
 * nums = {1, 2, 3}
 *
 * Returns:
 * 3
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - Only the first k elements of the vector (where k is the returned value)
 *   are guaranteed to contain the unique elements.
 * - The values beyond the returned length are unspecified.
 *
 * @param nums The sorted vector of integers to be modified.
 * @return int The number of unique elements in the vector.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != nums[j]) {
            nums[++j] = nums[i];
        }
    }

    return j + 1;
}