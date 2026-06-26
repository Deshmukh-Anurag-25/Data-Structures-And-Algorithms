#include <vector>
using namespace std;

/**
 * @brief Finds the intersection of two sorted arrays.
 *
 * Given two sorted arrays, this function returns a new vector containing
 * the common elements present in both arrays. The order of elements in the
 * result follows their order in the input arrays.
 *
 * This implementation uses the two-pointer technique, making it efficient
 * for sorted arrays.
 *
 * Example:
 * nums1 = {1, 2, 3, 4, 5}
 * nums2 = {2, 4, 6}
 *
 * Returns:
 * {2, 4}
 *
 * Note:
 * - The input arrays must be sorted in non-decreasing order.
 * - Duplicate elements are preserved if they appear in both arrays.
 *   Example:
 *      nums1 = {1, 2, 2, 3}
 *      nums2 = {2, 2, 4}
 *      Returns {2, 2}
 *
 * @param nums1 First sorted input array.
 * @param nums2 Second sorted input array.
 * @return vector<int> A vector containing the intersection of the two arrays.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(min(n, m)) in the worst case (excluding input arrays)
 */
vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
  int n1 = nums1.size(), n2 = nums2.size();
  int i = 0, j = 0;
  vector<int> ans;

  while (i < n1 && j < n2) {
    if (nums1[i] == nums2[j]) {
      ans.push_back(nums1[i]);
      i++;
      j++;
    } else {
      if (nums1[i] < nums2[j])
        i++;
      else
        j++;
    }
  }

  return ans;
}
