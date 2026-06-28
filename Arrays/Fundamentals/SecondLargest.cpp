#include <climits>
#include <vector>
using namespace std;

/**
 * @brief Finds the second largest distinct element in a vector.
 *
 * Traverses the vector once while maintaining the largest and second
 * largest distinct elements encountered so far. If no second distinct
 * largest element exists, the function returns -1.
 *
 * Example:
 * nums = {5, 1, 9, 3, 7}
 *
 * Returns:
 * 7
 *
 * Example:
 * nums = {4, 4, 4}
 *
 * Returns:
 * -1
 *
 * Note:
 * - The second largest element must be distinct from the largest.
 * - If the vector contains fewer than two distinct elements, the
 *   function returns -1.
 *
 * @param nums The input vector of integers.
 * @return int The second largest distinct element, or -1 if it does not exist.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int secondLargest(vector<int> &nums) {
    int maxi1 = INT_MIN, maxi2 = INT_MIN;

    for (int num : nums) {
        if (num > maxi1) {
            maxi2 = maxi1;
            maxi1 = num;
        } else if (num > maxi2 && num != maxi1) {
            maxi2 = num;
        }
    }

    return (maxi2 == INT_MIN) ? -1 : maxi2;
}