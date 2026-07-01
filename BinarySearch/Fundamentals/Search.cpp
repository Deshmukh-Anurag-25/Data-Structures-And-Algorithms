#include <vector>
using namespace std;

/**
 * @brief Searches for a target element in a sorted vector using Binary Search.
 *
 * Performs an iterative binary search to locate the specified target in a
 * sorted vector. The search interval is repeatedly divided in half until
 * the target is found or the interval becomes empty.
 *
 * The middle index is computed as:
 *      low + (high - low) / 2
 * to avoid potential integer overflow that can occur with
 * (low + high) / 2.
 *
 * Example:
 * nums = {1, 3, 5, 7, 9}
 * x = 7
 *
 * Returns:
 * 3
 *
 * Example:
 * nums = {2, 4, 6, 8}
 * x = 5
 *
 * Returns:
 * -1
 *
 * Algorithm:
 * 1. Initialize two pointers, low and high.
 * 2. Compute the middle index.
 * 3. If the middle element equals the target, return its index.
 * 4. If the target is larger, search the right half.
 * 5. Otherwise, search the left half.
 * 6. Repeat until the search interval is empty.
 *
 * Note:
 * - The input vector must be sorted in non-decreasing order.
 * - If the target appears multiple times, this implementation returns
 *   one of its occurrences, not necessarily the first or last.
 *
 * @param nums The sorted vector of integers.
 * @param x The target value to search for.
 * @return int The index of the target if found; otherwise, -1.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int search(vector<int> &nums, int x) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int mid = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (nums[mid] == x)
            return mid;
        else if (nums[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}