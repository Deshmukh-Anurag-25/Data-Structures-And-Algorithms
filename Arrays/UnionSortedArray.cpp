#include <vector>
using namespace std;

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
