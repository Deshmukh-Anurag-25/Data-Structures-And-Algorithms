#include <vector>
using namespace std;

/**
 * @brief Performs a linear search for a target element in a vector.
 *
 * Iterates through the vector from the beginning and returns the index
 * of the first occurrence of the target element. If the target is not
 * found, the function returns -1.
 *
 * Example:
 * nums = {10, 20, 30, 40}
 * target = 30
 *
 * Returns:
 * 2
 *
 * Example:
 * nums = {10, 20, 30, 40}
 * target = 50
 *
 * Returns:
 * -1
 *
 * Note:
 * - The vector does not need to be sorted.
 * - If the target appears multiple times, the index of its first
 *   occurrence is returned.
 *
 * @param nums The vector of integers to search.
 * @param target The value to search for.
 * @return int The index of the first occurrence of the target, or -1 if not found.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int linearSearch(vector<int> &nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == target)
            return i;
    }

    return -1;
}