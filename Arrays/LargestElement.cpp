#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int largestElement(vector<int> &nums) {
  int maxi = INT_MIN;
  for (int num : nums) {
    maxi = max(maxi, num);
  }

  return maxi;
}
