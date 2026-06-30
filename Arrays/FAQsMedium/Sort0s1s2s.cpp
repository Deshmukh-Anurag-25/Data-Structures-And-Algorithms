#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Sorts an array containing only 0s, 1s, and 2s in-place.
 *
 * Uses the Dutch National Flag Algorithm to sort the array in a single
 * traversal. The algorithm partitions the array into three regions:
 * - [0, low - 1] contains all 0s.
 * - [low, mid - 1] contains all 1s.
 * - [high + 1, n - 1] contains all 2s.
 *
 * Three pointers (`low`, `mid`, and `high`) are maintained to correctly
 * position each element as the array is traversed.
 *
 * Example:
 * nums = {2, 0, 2, 1, 1, 0}
 *
 * After modification:
 * {0, 0, 1, 1, 2, 2}
 *
 * Example:
 * nums = {1, 0, 2}
 *
 * After modification:
 * {0, 1, 2}
 *
 * Algorithm:
 * 1. If nums[mid] == 0, swap it with nums[low] and increment both
 *    low and mid.
 * 2. If nums[mid] == 1, simply increment mid.
 * 3. If nums[mid] == 2, swap it with nums[high] and decrement high.
 *    Do not increment mid because the swapped element must be examined.
 *
 * Note:
 * - The input array is assumed to contain only the values 0, 1, and 2.
 * - The sorting is performed in-place.
 *
 * @param nums The vector of integers to be sorted.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void sortZeroOneTwo(vector<int> &nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[high--], nums[mid]);
        }
    }
}