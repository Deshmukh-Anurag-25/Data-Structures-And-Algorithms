#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief Finds the length of the longest consecutive sequence in an array.
 *
 * A consecutive sequence consists of integers that appear consecutively,
 * regardless of their order in the input array.
 *
 * The algorithm uses an unordered_set to provide O(1) average lookup time.
 * A number is considered the beginning of a sequence only if its predecessor
 * (number - 1) does not exist in the set. Starting from each such element,
 * the sequence is extended until no consecutive successor exists.
 *
 * By iterating directly over the unordered_set, duplicate values in the
 * input array are ignored automatically, ensuring that each unique element
 * is processed only once.
 *
 * Example:
 * nums = {100, 4, 200, 1, 3, 2}
 *
 * Consecutive sequence:
 * 1 → 2 → 3 → 4
 *
 * Returns:
 * 4
 *
 * Example:
 * nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}
 *
 * Consecutive sequence:
 * 0 → 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
 *
 * Returns:
 * 9
 *
 * Algorithm:
 * 1. Insert all elements into an unordered_set.
 * 2. Traverse each unique element in the set.
 * 3. If (current - 1) does not exist, the current element is the start of
 *    a new consecutive sequence.
 * 4. Extend the sequence while consecutive successors exist.
 * 5. Track the maximum sequence length encountered.
 * 6. Return the longest sequence length.
 *
 * Note:
 * - Duplicate values are automatically ignored by the unordered_set.
 * - Every element is part of at most one sequence expansion.
 *
 * @param nums The input vector of integers.
 * @return int The length of the longest consecutive sequence.
 *
 * Time Complexity: O(n) average
 * Space Complexity: O(n)
 */
int longestConsecutiveSequence(vector<int> &nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int maxLen = 0;

    for (int curr : st) {
        if (!st.count(curr - 1)) {
            int len = 1;

            while (st.count(curr + 1)) {
                curr++;
                len++;
            }

            maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}