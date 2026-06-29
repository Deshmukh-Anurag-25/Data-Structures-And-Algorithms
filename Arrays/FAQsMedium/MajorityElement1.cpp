#include <vector>
using namespace std;

/**
 * @brief Finds the majority element in a vector using Moore's Voting Algorithm.
 *
 * A majority element is an element that appears more than ⌊n / 2⌋ times,
 * where n is the size of the vector.
 *
 * The function first identifies a potential majority candidate using
 * Moore's Voting Algorithm. It then performs a second pass to verify
 * whether the candidate actually occurs more than n / 2 times.
 *
 * Example:
 * nums = {2, 2, 1, 1, 1, 2, 2}
 *
 * Returns:
 * 2
 *
 * Example:
 * nums = {1, 2, 3, 4}
 *
 * Returns:
 * -1
 *
 * Algorithm:
 * 1. Traverse the vector to find a candidate using Moore's Voting Algorithm.
 * 2. Count the occurrences of the candidate.
 * 3. If the candidate appears more than n / 2 times, return it;
 *    otherwise, return -1.
 *
 * Note:
 * - The function returns -1 if no majority element exists.
 * - The input vector may contain any integer values.
 *
 * @param nums The input vector of integers.
 * @return int The majority element if it exists; otherwise, -1.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int majorityElement(vector<int> &nums) {
    int n = nums.size();
    int el = 0, cnt = 0;

    for (int num : nums) {
        if (cnt == 0) {
            cnt = 1;
            el = num;
        } else if (el == num) {
            cnt++;
        } else {
            cnt--;
        }
    }

    cnt = 0;
    for (int num : nums) {
        if (num == el)
            cnt++;
    }

    return (cnt > n / 2) ? el : -1;
}