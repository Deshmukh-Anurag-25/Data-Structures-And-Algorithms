#include <vector>
using namespace std;

/**
 * @brief Merges two sorted arrays into the first array in-place.
 *
 * Assumes that:
 * - nums1 has a size of n + m.
 * - The first n elements of nums1 are valid and sorted.
 * - nums2 contains m sorted elements.
 *
 * The merge is performed from the end of the arrays to avoid overwriting
 * unprocessed elements in nums1.
 *
 * Example:
 * nums1 = {1, 2, 3, 0, 0, 0}
 * n = 3
 * nums2 = {2, 5, 6}
 * m = 3
 *
 * After execution:
 * nums1 = {1, 2, 2, 3, 5, 6}
 *
 * Example:
 * nums1 = {4, 5, 6, 0, 0, 0}
 * n = 3
 * nums2 = {1, 2, 3}
 * m = 3
 *
 * After execution:
 * nums1 = {1, 2, 3, 4, 5, 6}
 *
 * Algorithm:
 * 1. Initialize three pointers:
 *    - i at the last valid element of nums1.
 *    - j at the last element of nums2.
 *    - k at the last position of nums1.
 * 2. Compare nums1[i] and nums2[j].
 * 3. Place the larger element at nums1[k].
 * 4. Move the corresponding pointer backward.
 * 5. Repeat until one array is exhausted.
 * 6. Copy any remaining elements from nums2 into nums1.
 *
 * Note:
 * - Remaining elements in nums1 do not need to be copied because they are
 *   already in their correct positions.
 * - Both input arrays must be sorted in non-decreasing order.
 *
 * @param nums1 The first sorted array with enough extra space to hold all
 *              elements.
 * @param n Number of valid elements initially present in nums1.
 * @param nums2 The second sorted array.
 * @param m Number of elements in nums2.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(1)
 */
void merge(vector<int> &nums1, int n, vector<int> &nums2, int m) {
    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] < nums2[j]) {
            nums1[k--] = nums2[j--];
        } else {
            nums1[k--] = nums1[i--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}