#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Stores all unique combinations whose sum equals the target.
 */
vector<vector<int>> combinations;

/**
 * @brief Recursively generates all unique combinations that sum to the target.
 *
 * Each candidate can be used at most once. Since the input array is sorted,
 * duplicate values are skipped to avoid generating duplicate combinations.
 *
 * At each index, the function has two choices:
 * - Include the current element.
 * - Exclude the current element and skip all its duplicates.
 *
 * @param index Current index being processed.
 * @param n Number of candidates.
 * @param target Required target sum.
 * @param current Current combination being constructed.
 * @param sum Current sum of the selected elements.
 * @param candidates Sorted list of candidate values.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 * where:
 * - n = number of candidates.
 */
void helper(int index,
            int n,
            int target,
            vector<int>& current,
            int sum,
            const vector<int>& candidates) {

    if (sum == target) {
        combinations.push_back(current);
        return;
    }

    if (index >= n || sum > target)
        return;

    // Include the current candidate.
    if (sum + candidates[index] <= target) {
        current.push_back(candidates[index]);
        helper(index + 1, n, target, current,
               sum + candidates[index], candidates);
        current.pop_back();
    }

    // Skip duplicate candidates.
    while (index + 1 < n && candidates[index] == candidates[index + 1])
        index++;

    // Exclude the current candidate.
    helper(index + 1, n, target, current, sum, candidates);
}

/**
 * @brief Finds all unique combinations of numbers that sum to the target.
 *
 * Each number in the input array may be used at most once in a combination.
 * The input array may contain duplicate values, but duplicate combinations
 * are not included in the output.
 *
 * Example:
 * candidates = {10, 1, 2, 7, 6, 1, 5}
 * target = 8
 *
 * Returns:
 * {
 *   {1, 1, 6},
 *   {1, 2, 5},
 *   {1, 7},
 *   {2, 6}
 * }
 *
 * Algorithm:
 * 1. Sort the candidate array.
 * 2. At every index:
 *    - Include the current element.
 *    - Exclude it and skip all consecutive duplicates.
 * 3. Whenever the running sum equals the target, store the current
 *    combination.
 * 4. Continue until all possibilities have been explored.
 *
 * Note:
 * - Each candidate can be used only once.
 * - Sorting is necessary to efficiently skip duplicates.
 * - The implementation assumes all candidate values are positive.
 *
 * @param candidates Array of candidate numbers.
 * @param target Required target sum.
 * @return vector<vector<int>> All unique valid combinations.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) excluding the output.
 */
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    combinations.clear();

    sort(candidates.begin(), candidates.end());

    vector<int> current;
    helper(0, candidates.size(), target, current, 0, candidates);

    return combinations;
}