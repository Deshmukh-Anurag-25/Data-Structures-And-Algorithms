#include <vector>
using namespace std;

/**
 * @brief Finds all elements that appear more than n/3 times in an array.
 *
 * Uses the Boyer-Moore Voting Algorithm (extended version) to identify all
 * majority elements that occur more than ⌊n/3⌋ times.
 *
 * Unlike the standard majority element problem (> n/2), there can be at
 * most two elements that occur more than n/3 times. The algorithm first
 * identifies two potential candidates and then verifies their frequencies
 * in a second traversal.
 *
 * Example:
 * nums = {3, 2, 3}
 *
 * Returns:
 * {3}
 *
 * Example:
 * nums = {1, 1, 1, 3, 3, 2, 2, 2}
 *
 * Returns:
 * {1, 2}
 *
 * Example:
 * nums = {1, 2, 3, 4}
 *
 * Returns:
 * {}
 *
 * Algorithm:
 * 1. Maintain two candidate elements and their vote counts.
 * 2. Traverse the array:
 *    - If the current element matches a candidate, increment its count.
 *    - Otherwise, if a candidate count becomes zero, replace that candidate.
 *    - If neither condition holds, decrement both counts.
 * 3. Perform a second traversal to count the actual occurrences of both
 *    candidates.
 * 4. Return every candidate whose frequency exceeds n/3.
 *
 * Note:
 * - There can be at most two majority elements occurring more than n/3
 *   times.
 * - A second pass is required because the first pass only determines
 *   potential candidates.
 *
 * @param nums The input vector of integers.
 * @return vector<int> A vector containing all elements that occur more than
 *         n/3 times.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
vector<int> majorityElement(vector<int> &nums) {
    int n = nums.size();

    int el1 = 0, el2 = 0;
    int cnt1 = 0, cnt2 = 0;

    vector<int> ans;

    // Phase 1: Find two potential majority candidates.
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i]) {
            cnt1++;
        }
        else if (el2 == nums[i]) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Phase 2: Verify the candidates.
    cnt1 = 0;
    cnt2 = 0;

    for (int num : nums) {
        if (num == el1)
            cnt1++;
        else if (num == el2)
            cnt2++;
    }

    int threshold = n / 3 + 1;

    if (cnt1 >= threshold)
        ans.push_back(el1);

    if (cnt2 >= threshold)
        ans.push_back(el2);

    return ans;
}