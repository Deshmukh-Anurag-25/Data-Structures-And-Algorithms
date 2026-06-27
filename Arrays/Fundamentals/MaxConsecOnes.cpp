#include <algorithm>
#include <vector>
using namespace std;

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
