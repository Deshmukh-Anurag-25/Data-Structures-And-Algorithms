#include <unordered_map>
#include <vector>
using namespace std;

/**
 * @brief Finds two indices whose corresponding elements sum to a target value.
 *
 * Uses a hash map to store previously encountered elements and their indices.
 * For each element, the function computes the required complement and checks
 * whether it has already been seen. If so, the indices of the two elements
 * are returned immediately.
 *
 * Example:
 * nums = {2, 7, 11, 15}
 * target = 9
 *
 * Returns:
 * {0, 1}
 *
 * Explanation:
 * nums[0] + nums[1] = 2 + 7 = 9
 *
 * Example:
 * nums = {3, 2, 4}
 * target = 6
 *
 * Returns:
 * {1, 2}
 *
 * Explanation:
 * nums[1] + nums[2] = 2 + 4 = 6
 *
 * Algorithm:
 * 1. Traverse the array from left to right.
 * 2. For each element, compute:
 *      complement = target - current_element
 * 3. Check if the complement exists in the hash map.
 * 4. If found, return the complement's index followed by the current index.
 * 5. Otherwise, store the current element and its index in the hash map.
 *
 * Note:
 * - The same element cannot be used twice.
 * - The first returned index corresponds to the element encountered earlier
 *   during the traversal.
 * - If no valid pair exists, the function returns {-1, -1}.
 *
 * @param nums The input vector of integers.
 * @param target The target sum.
 * @return vector<int> A vector containing the indices of the two elements
 *         whose sum equals the target, or {-1, -1} if no such pair exists.
 *
 * Time Complexity: O(n) average
 * Space Complexity: O(n)
 */
vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();
    unordered_map<int, int> seen;
    int complement = 0;

    for (int i = 0; i < n; i++) {
        complement = target - nums[i];

        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }

        seen[nums[i]] = i;
    }

    return {-1, -1};
}