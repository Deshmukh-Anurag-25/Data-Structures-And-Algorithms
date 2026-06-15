#include <bits/stdc++.h>
using namespace std;

int largestEl(vector<int> &nums) {
  int maxi = INT_MIN;
  for (int num : nums) {
    maxi = max(maxi, num);
  }

  return maxi;
}
