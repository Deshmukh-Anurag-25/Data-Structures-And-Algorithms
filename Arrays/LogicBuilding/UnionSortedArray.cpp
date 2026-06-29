#include <vector>
using namespace std;

/**
 * @brief Computes the union of two sorted arrays.
 *
 * Merges two sorted arrays into a single vector containing all distinct
 * elements present in either array. Duplicate values, whether within the
 * same array or across both arrays, are included only once in the result.
 *
 * The function uses the two-pointer technique to efficiently traverse
 * both arrays simultaneously while maintaining the sorted order of the
 * output.
 *
 * Example:
 * nums1 = {1, 2, 2, 3, 5}
 * nums2 = {2, 3, 4, 5, 6}
 *
 * Returns:
 * {1, 2, 3, 4, 5, 6}
 *
 * Example:
 * nums1 = {1, 3, 5}
 * nums2 = {2, 4, 6}
 *
 * Returns:
 * {1, 2, 3, 4, 5, 6}
 *
 * Note:
 * - Both input vectors must be sorted in non-decreasing order.
 * - The returned vector contains only distinct elements.
 * - The resulting vector is also sorted in non-decreasing order.
 *
 * @param nums1 The first sorted vector of integers.
 * @param nums2 The second sorted vector of integers.
 * @return vector<int> A sorted vector containing the union of the two input vectors.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(n + m)
 */
vector<int> unionArrays(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0, j = 0;
    vector<int> ans;

    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            if (ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }
            i++;
        } else {
            if (ans.empty() || ans.back() != nums2[j]) {
                ans.push_back(nums2[j]);
            }
            j++;
        }
    }

    while (i < n1) {
        if (ans.empty() || ans.back() != nums1[i]) {
            ans.push_back(nums1[i]);
        }
        i++;
    }

    while (j < n2) {
        if (ans.empty() || ans.back() != nums2[j]) {
            ans.push_back(nums2[j]);
        }
        j++;
    }

    return ans;
}