#include <vector>
#include<algorithm>
using namespace std;

/**
 * @brief Finds all leader elements in an array.
 *
 * A leader is an element that is strictly greater than all the elements
 * to its right. The rightmost element is always considered a leader.
 *
 * The function traverses the array from right to left, maintaining the
 * maximum element seen so far. Whenever the current element is greater
 * than this maximum, it is identified as a leader. The resulting list is
 * reversed before being returned so that the leaders appear in the same
 * order as in the original array.
 *
 * Example:
 * nums = {16, 17, 4, 3, 5, 2}
 *
 * Returns:
 * {17, 5, 2}
 *
 * Note:
 * - The returned leaders preserve their original left-to-right order.
 * - If no elements exist to the right of an element (i.e., the last element),
 *   it is always considered a leader.
 *
 * @param nums The input vector of integers.
 * @return vector<int> A vector containing all leader elements in their original order.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
vector<int> leaders(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans;
    int maxi = nums[n - 1];

    for (int i = n - 1; i >= 0; i--) {
        if (ans.empty() || nums[i] > maxi) {
            ans.push_back(nums[i]);
            maxi = nums[i];
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}