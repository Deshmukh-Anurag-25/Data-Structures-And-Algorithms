#include <vector>
using namespace std;

/**
 * @brief Rotates the elements of a vector one position to the left.
 *
 * Shifts every element in the vector one index toward the beginning,
 * moving the first element to the end of the vector.
 *
 * Example:
 * nums = {1, 2, 3, 4, 5}
 *
 * After rotation:
 * {2, 3, 4, 5, 1}
 *
 * Note:
 * - The input vector must contain at least one element.
 * - The rotation is performed in-place without using any additional array.
 *
 * @param nums The vector of integers to be rotated.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void leftRotate(vector<int> &nums) {
    int temp = nums[0];
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        nums[i] = nums[i + 1];
    }

    nums[n - 1] = temp;
}