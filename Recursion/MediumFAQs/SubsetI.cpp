#include <vector>
using namespace std;

/**
 * @brief Stores all possible subsets of the input array.
 */
vector<vector<int>> subsetsList;

/**
 * @brief Recursively generates every possible subset of the array.
 *
 * At each index, the function has two choices:
 * - Include the current element in the subset.
 * - Exclude the current element from the subset.
 *
 * When all elements have been processed, the current subset is added to
 * the result.
 *
 * @param index Current index being processed.
 * @param n Number of elements in the array.
 * @param nums Input array.
 * @param current Current subset being constructed.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * where:
 * - n = number of elements in the array.
 */
void helper(int index,
            int n,
            const vector<int>& nums,
            vector<int>& current) {

    if (index >= n) {
        subsetsList.push_back(current);
        return;
    }

    // Include the current element.
    current.push_back(nums[index]);
    helper(index + 1, n, nums, current);

    // Backtrack.
    current.pop_back();

    // Exclude the current element.
    helper(index + 1, n, nums, current);
}

/**
 * @brief Generates all possible subsets (the power set) of an array.
 *
 * A subset is formed by selecting zero or more elements from the array
 * without changing their relative order.
 *
 * Example:
 * nums = {1, 2, 3}
 *
 * Returns:
 * {
 *   {},
 *   {3},
 *   {2},
 *   {2, 3},
 *   {1},
 *   {1, 3},
 *   {1, 2},
 *   {1, 2, 3}
 * }
 *
 * Algorithm:
 * 1. Start with an empty subset.
 * 2. At every element:
 *    - Include the element.
 *    - Exclude the element.
 * 3. Once all elements have been considered, store the current subset.
 *
 * Note:
 * - Every element has two choices (include or exclude), producing
 *   a total of 2^n subsets.
 * - The order of subsets in the output depends on the recursion.
 *
 * @param nums Input array.
 * @return vector<vector<int>> A list containing every possible subset.
 *
 * Time Complexity: O(n × 2^n)
 * Space Complexity: O(n) excluding the output.
 * where:
 * - n = number of elements in the array.
 */
vector<vector<int>> subsets(vector<int>& nums) {
    subsetsList.clear();

    vector<int> current;
    helper(0, nums.size(), nums, current);

    return subsetsList;
}