#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Finds the maximum number of consecutive 1s in a binary array.
 *
 * Traverses the input vector and keeps track of the current streak of
 * consecutive 1s. Whenever a 0 is encountered, the current streak is
 * reset. The maximum streak observed during the traversal is returned.
 *
 * Example:
 * nums = {1, 1, 0, 1, 1, 1}
 *
 * Returns:
 * 3
 *
 * Example:
 * nums = {0, 0, 1, 1, 0, 1}
 *
 * Returns:
 * 2
 *
 * Note:
 * - The input vector is expected to contain only 0s and 1s.
 * - If the vector contains no 1s, the function returns 0.
 *
 * @param nums The binary vector to be examined.
 * @return int The length of the longest sequence of consecutive 1s.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxOnes(vector<int> &nums) {
    int cnt = 0, maxCnt = 0;

    for (int num : nums) {
        if (num == 1) {
            cnt++;
            maxCnt = max(maxCnt, cnt);
        } else {
            cnt = 0;
        }
    }

    return maxCnt;
}