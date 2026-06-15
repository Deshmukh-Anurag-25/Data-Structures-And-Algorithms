#include <bits/stdc++.h>
using namespace std;

void leftRotatedByK(vector<int> &nums, int k) {
  int n = nums.size();
  k %= n;

  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
  reverse(nums.begin(), nums.end());
}
