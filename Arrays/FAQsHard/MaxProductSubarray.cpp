#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/**
 * @brief Finds the maximum product of a contiguous subarray.
 *
 * Uses a bidirectional traversal to compute prefix and suffix products.
 * This approach handles negative numbers by considering products from both
 * the left and right directions. Whenever a product becomes zero, it is
 * reset to 1 to begin evaluating a new subarray.
 *
 * Example:
 * nums = {2, 3, -2, 4}
 *
 * Returns:
 * 6
 *
 * Explanation:
 * The subarray {2, 3} has the maximum product of 6.
 *
 * Example:
 * nums = {-2, 0, -1}
 *
 * Returns:
 * 0
 *
 * Explanation:
 * The maximum product is obtained from the subarray {0}.
 *
 * Example:
 * nums = {-2, -3, -4}
 *
 * Returns:
 * 12
 *
 * Explanation:
 * The subarray {-3, -4} has the maximum product.
 *
 * Algorithm:
 * 1. Initialize prefix and suffix products to 1.
 * 2. Traverse the array simultaneously:
 *    - From left to right, updating the prefix product.
 *    - From right to left, updating the suffix product.
 * 3. If either product becomes zero, reset it to 1 before continuing.
 * 4. After each iteration, update the maximum product using both prefix
 *    and suffix values.
 * 5. Return the maximum product found.
 *
 * Note:
 * - Traversing from both directions ensures that subarrays containing an
 *   odd number of negative values are handled correctly.
 * - The algorithm naturally handles zeros by restarting the product.
 *
 * @param nums The input vector of integers.
 * @return int The maximum product of any contiguous subarray.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxProduct(vector<int> &nums) {
    int prefix = 1, suffix = 1;
    int n = nums.size();
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (prefix == 0)
            prefix = 1;

        if (suffix == 0)
            suffix = 1;

        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        ans = max(ans, max(prefix, suffix));
    }

    return ans;
}