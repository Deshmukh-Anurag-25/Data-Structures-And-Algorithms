#include <vector>
using namespace std;

/**
 * @brief Determines whether it is possible to reach the last index
 * of the array.
 *
 * Each element in the array represents the maximum number of steps
 * that can be jumped forward from that position.
 *
 * The algorithm greedily keeps track of the farthest index that can
 * currently be reached. If at any point the current index lies beyond
 * the farthest reachable position, the last index cannot be reached.
 *
 * Example:
 * nums = [2,3,1,1,4]
 *
 * Jump sequence:
 * Index 0 -> Index 1 -> Index 4
 *
 * Returns:
 * true
 *
 * Example:
 * nums = [3,2,1,0,4]
 *
 * The jump at index 3 has length 0, making index 4 unreachable.
 *
 * Returns:
 * false
 *
 * Algorithm:
 * 1. Initialize the farthest reachable index as 0.
 * 2. Traverse the array from left to right.
 * 3. If the current index is greater than the farthest reachable
 *    index, return false.
 * 4. Otherwise, update the farthest reachable index using:
 *      maxReach = max(maxReach, i + nums[i])
 * 5. If the traversal completes, the last index is reachable.
 *
 * @param nums Array where nums[i] represents the maximum jump length
 *        from index i.
 * @return bool True if the last index can be reached; otherwise false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = size of the array.
 */
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;

    for (int i = 0; i < n; i++) {

        if (i > maxReach)
            return false;

        maxReach = max(maxReach, i + nums[i]);
    }

    return true;
}