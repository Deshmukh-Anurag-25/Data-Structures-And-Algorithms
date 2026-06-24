#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutiveSequence(vector<int> &nums) {
  int n = nums.size();
  unordered_set<int> st(nums.begin(), nums.end());
  int len = 0, maxLen = 0;
  for (int i = 0; i < n; i++) {
    int curr = nums[i];
    if (!st.count(curr - 1)) {
      len = 1;
      while (st.count(curr + 1)) {
        len++;
        curr++;
      }

      maxLen = max(maxLen, len);
    }
  }

  return maxLen;
}
