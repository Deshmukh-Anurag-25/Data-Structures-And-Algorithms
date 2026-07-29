#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Inserts a new interval into a sorted list of non-overlapping
 * intervals and merges overlapping intervals if necessary.
 *
 * The input intervals are already sorted by their starting times and
 * do not overlap with one another.
 *
 * The algorithm processes the intervals in three phases:
 * 1. Add all intervals that end before the new interval begins.
 * 2. Merge all intervals that overlap with the new interval.
 * 3. Add the remaining intervals that start after the merged interval.
 *
 * Example:
 * intervals = [[1,3],[6,9]]
 * newInterval = [2,5]
 *
 * Result:
 * [[1,5],[6,9]]
 *
 * Example:
 * intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
 * newInterval = [4,8]
 *
 * Result:
 * [[1,2],[3,10],[12,16]]
 *
 * Algorithm:
 * 1. Copy all intervals that end before the new interval starts.
 * 2. Merge every interval whose start is less than or equal to the
 *    current merged interval's end.
 * 3. Append the merged interval.
 * 4. Copy all remaining intervals.
 *
 * @param intervals Sorted list of non-overlapping intervals where each
 *        interval is represented as [start, end].
 * @param newInterval The interval to be inserted.
 * @return vector<vector<int>> The updated list of merged intervals.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of intervals.
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        int i = 0;

        vector<vector<int>> mergedIntervals;

        // Add all intervals that come completely before the new interval.
        while (i < n && intervals[i][1] < start) {
            mergedIntervals.push_back(intervals[i]);
            i++;
        }

        // Merge all overlapping intervals.
        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        mergedIntervals.push_back({start, end});

        // Add all remaining intervals.
        while (i < n) {
            mergedIntervals.push_back(intervals[i]);
            i++;
        }

        return mergedIntervals;
    }
};