#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Stores all unique subsets of the input array.
 */
vector<vector<int>> subsetsList;

/**
 * @brief Recursively generates all unique subsets of a sorted array.
 *
 * At each index, the function has two choices:
 * - Include the current element in the subset.
 * - Exclude the current element and skip any consecutive duplicates.
 *
 * Since the input array is sorted, duplicate values appear together,
 * allowing them to be skipped efficiently when exploring the exclusion
 * branch.
 *
 * @param index Current index being processed.
 * @param n Number of elements in the array.
 * @param nums Sorted input array.
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
    current.pop_back();

    // Skip duplicate elements.
    while (index + 1 < n && nums[index] == nums[index + 1])
        index++;

    // Exclude the current element.
    helper(index + 1, n, nums, current);
}

/**
 * @brief Generates all unique subsets of an array that may contain duplicates.
 *
 * A subset is formed by selecting zero or more elements from the array
 * without changing their relative order. Duplicate subsets are removed by
 * first sorting the array and then skipping consecutive duplicate values
 * during recursion.
 *
 * Example:
 * nums = {1, 2, 2}
 *
 * Returns:
 * {
 *   {},
 *   {1},
 *   {2},
 *   {1, 2},
 *   {2, 2},
 *   {1, 2, 2}
 * }
 *
 * Algorithm:
 * 1. Sort the input array.
 * 2. At every index:
 *    - Include the current element.
 *    - Exclude the current element while skipping all consecutive duplicates.
 * 3. Once all elements have been processed, store the current subset.
 *
 * Note:
 * - Sorting is necessary to group duplicate values together.
 * - Every unique subset is generated exactly once.
 *
 * @param nums Input array that may contain duplicate values.
 * @return vector<vector<int>> A list of all unique subsets.
 *
 * Time Complexity: O(n × 2^n)
 * Space Complexity: O(n) excluding the output.
 * where:
 * - n = number of elements in the array.
 */
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    subsetsList.clear();

    sort(nums.begin(), nums.end());

    vector<int> current;
    helper(0, nums.size(), nums, current);

    return subsetsList;
}