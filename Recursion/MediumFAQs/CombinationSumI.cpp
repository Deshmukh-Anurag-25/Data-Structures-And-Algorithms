#include <vector>
using namespace std;

/**
 * @brief Stores all valid combinations whose sum equals the target.
 */
vector<vector<int>> combinations;

/**
 * @brief Recursively generates all combinations whose sum equals the target.
 *
 * At each index, the function has two choices:
 * - Include the current element. Since each candidate can be chosen
 *   multiple times, the index remains unchanged.
 * - Exclude the current element and move to the next index.
 *
 * Whenever the running sum becomes equal to the target, the current
 * combination is added to the answer.
 *
 * @param index Current index being processed.
 * @param n Number of candidates.
 * @param target Required target sum.
 * @param candidates Input array of candidate values.
 * @param current Current combination being constructed.
 * @param sum Current sum of the selected elements.
 *
 * Time Complexity: O(2^t) (depends on the number of valid combinations)
 * Space Complexity: O(target)
 */
void helper(int index,
            int n,
            int target,
            const vector<int>& candidates,
            vector<int>& current,
            int sum) {
    if (sum == target) {
        combinations.push_back(current);
        return;
    }

    if (index >= n || sum > target)
        return;

    // Include the current candidate.
    current.push_back(candidates[index]);
    helper(index, n, target, candidates, current, sum + candidates[index]);
    current.pop_back();

    // Exclude the current candidate.
    helper(index + 1, n, target, candidates, current, sum);
}

/**
 * @brief Finds all unique combinations of candidates that sum to the target.
 *
 * Each candidate may be selected an unlimited number of times.
 * The order of elements inside a combination does not matter.
 *
 * Example:
 * candidates = {2, 3, 6, 7}
 * target = 7
 *
 * Returns:
 * {
 *   {2, 2, 3},
 *   {7}
 * }
 *
 * Algorithm:
 * 1. Start from the first candidate.
 * 2. At every index:
 *    - Include the current candidate (stay at the same index).
 *    - Exclude the current candidate (move to the next index).
 * 3. Whenever the running sum equals the target, store the combination.
 * 4. Continue until all possibilities have been explored.
 *
 * Note:
 * - Each candidate can be used any number of times.
 * - This implementation assumes all candidate values are positive because
 *   it prunes recursion when the running sum exceeds the target.
 *
 * @param candidates Array of candidate numbers.
 * @param target Required target sum.
 * @return vector<vector<int>> All valid combinations.
 *
 * Time Complexity: Exponential (depends on the number of valid combinations)
 * Space Complexity: O(target) excluding the output.
 */
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    combinations.clear();

    vector<int> current;
    helper(0, candidates.size(), target, candidates, current, 0);

    return combinations;
}