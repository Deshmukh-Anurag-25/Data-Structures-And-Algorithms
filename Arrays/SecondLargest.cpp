#include <climits>
#include <vector>
using namespace std;

int secondLargest(vector<int> &nums) {
  int maxi1 = INT_MIN, maxi2 = INT_MIN;

  for (int num : nums) {
    if (num > maxi1) {
      maxi2 = maxi1;
      maxi1 = num;
    } else if (num > maxi2 && num != maxi1) {
      maxi2 = num;
    }
  }

  return (maxi2 == INT_MIN) ? -1 : maxi2;
}
