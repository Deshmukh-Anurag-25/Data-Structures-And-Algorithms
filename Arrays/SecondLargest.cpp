#include <bits/stdc++.h>
#include <climits>
using namespace std;

int secondLargest(vector<int> &nums) {
  int maxi = INT_MIN, maxi2 = -1;
  for (int num : nums) {
    if (num > maxi) {
      maxi2 = maxi;
      maxi = num;
    } else if (num > maxi2 && num != maxi) {
      maxi2 = num;
    }
  }

  return (maxi2 == INT_MIN) ? -1 : maxi2;
}
