#include <vector>
using namespace std;

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
