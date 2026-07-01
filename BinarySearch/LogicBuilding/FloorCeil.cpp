#include <vector>
using namespace std;

/**
 * @brief Finds the floor of a target value in a sorted vector.
 *
 * The floor of a value x is the greatest element in the vector that is
 * less than or equal to x. If no such element exists, the function
 * returns -1.
 *
 * Example:
 * nums = {1, 2, 4, 6, 8}
 * x = 5
 *
 * Returns:
 * 4
 *
 * Example:
 * nums = {3, 5, 7}
 * x = 2
 *
 * Returns:
 * -1
 *
 * Algorithm:
 * 1. Perform binary search.
 * 2. If nums[mid] <= x:
 *    - Record nums[mid] as a potential answer.
 *    - Search the right half for a larger valid value.
 * 3. Otherwise, search the left half.
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 *
 * @param nums The sorted vector of integers.
 * @param x The target value.
 * @return int The floor of x, or -1 if it does not exist.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int floor(vector<int>& nums, int x) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= x) {
            ans = nums[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

/**
 * @brief Finds the ceiling of a target value in a sorted vector.
 *
 * The ceiling of a value x is the smallest element in the vector that is
 * greater than or equal to x. If no such element exists, the function
 * returns -1.
 *
 * Example:
 * nums = {1, 2, 4, 6, 8}
 * x = 5
 *
 * Returns:
 * 6
 *
 * Example:
 * nums = {1, 2, 4}
 * x = 10
 *
 * Returns:
 * -1
 *
 * Algorithm:
 * 1. Perform binary search.
 * 2. If nums[mid] >= x:
 *    - Record nums[mid] as a potential answer.
 *    - Search the left half for a smaller valid value.
 * 3. Otherwise, search the right half.
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 *
 * @param nums The sorted vector of integers.
 * @param x The target value.
 * @return int The ceiling of x, or -1 if it does not exist.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int ceil(vector<int>& nums, int x) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= x) {
            ans = nums[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

/**
 * @brief Finds both the floor and ceiling of a target value in a sorted vector.
 *
 * Uses the floor() and ceil() helper functions to compute the greatest
 * element less than or equal to the target and the smallest element
 * greater than or equal to the target.
 *
 * Example:
 * nums = {1, 2, 4, 6, 8}
 * x = 5
 *
 * Returns:
 * {4, 6}
 *
 * Example:
 * nums = {3, 5, 7}
 * x = 1
 *
 * Returns:
 * {-1, 3}
 *
 * Example:
 * nums = {3, 5, 7}
 * x = 10
 *
 * Returns:
 * {7, -1}
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - If the floor or ceiling does not exist, -1 is returned for that value.
 *
 * @param nums The sorted vector of integers.
 * @param x The target value.
 * @return vector<int> A vector containing {floor, ceiling} of the target.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
vector<int> getFloorAndCeil(vector<int> nums, int x) {
    return {floor(nums, x), ceil(nums, x)};
}