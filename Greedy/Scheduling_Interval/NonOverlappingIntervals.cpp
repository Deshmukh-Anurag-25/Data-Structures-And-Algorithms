#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Finds the minimum number of intervals that must be removed
 * so that the remaining intervals do not overlap.
 *
 * Two intervals are considered non-overlapping if the start of the
 * current interval is greater than or equal to the end of the
 * previously selected interval.
 *
 * The greedy strategy is to always keep the interval that finishes
 * earliest, leaving the maximum room for future intervals.
 *
 * Example:
 * intervals = [[1,2],[2,3],[3,4],[1,3]]
 *
 * After sorting by end time:
 * [1,2] [1,3] [2,3] [3,4]
 *
 * Selected intervals:
 * [1,2] -> [2,3] -> [3,4]
 *
 * Total intervals = 4
 * Non-overlapping intervals = 3
 *
 * Minimum removals = 4 - 3 = 1
 *
 * Algorithm:
 * 1. Sort all intervals according to their ending time.
 * 2. Select the first interval.
 * 3. Traverse the remaining intervals:
 *    - If the current interval starts after or at the end of the last
 *      selected interval, keep it.
 *    - Otherwise, discard it.
 * 4. The answer equals:
 *      Total intervals - Number of selected intervals.
 *
 * @param intervals Array of intervals where each interval is represented
 *        as [start, end].
 * @return int Minimum number of intervals to remove.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 * where:
 * - n = number of intervals.
 */
class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comparator);

        int nonOverlapping = 1;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {

            if (intervals[i][0] >= lastEnd) {
                nonOverlapping++;
                lastEnd = intervals[i][1];
            }
        }

        return n - nonOverlapping;
    }
};