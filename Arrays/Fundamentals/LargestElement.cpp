#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/**
 * @brief Finds the largest element in a vector.
 *
 * Iterates through the given vector and returns the maximum element.
 * The function performs a linear scan, updating the current maximum
 * whenever a larger element is encountered.
 *
 * Example:
 * nums = {3, 8, 2, 10, 5}
 *
 * Returns:
 * 10
 *
 * Note:
 * - The input vector must contain at least one element.
 * - Behavior is undefined for an empty vector.
 *
 * @param nums The input vector of integers.
 * @return int The largest element in the vector.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int largestElement(vector<int> &nums) {
  int maxi = INT_MIN;

  for (int num : nums) {
    maxi = max(maxi, num);
  }

  return maxi;
}
