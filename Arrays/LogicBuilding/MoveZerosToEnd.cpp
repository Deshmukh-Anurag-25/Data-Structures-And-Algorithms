#include <vector>
using namespace std;

/**
 * @brief Moves all zero elements to the end of the vector while preserving
 *        the relative order of non-zero elements.
 *
 * Traverses the vector once, copying each non-zero element to the next
 * available position. After all non-zero elements have been placed,
 * the remaining positions are filled with zeros.
 *
 * Example:
 * nums = {0, 1, 0, 3, 12}
 *
 * After modification:
 * {1, 3, 12, 0, 0}
 *
 * Example:
 * nums = {1, 2, 3}
 *
 * After modification:
 * {1, 2, 3}
 *
 * Note:
 * - The operation is performed in-place.
 * - The relative order of non-zero elements is preserved.
 *
 * @param nums The vector of integers to be modified.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void moveZeros(vector<int> &nums) {
    int n = nums.size();
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    while (j < n)
        nums[j++] = 0;
}