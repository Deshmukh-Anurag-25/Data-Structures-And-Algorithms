#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Represents a meeting with its start time, end time,
 * and original position.
 */
struct Data {
    int start;   ///< Meeting start time.
    int end;     ///< Meeting end time.
    int pos;     ///< Original meeting index (1-based).
};

/**
 * @brief Comparator used to sort meetings by their finishing time.
 *
 * Meetings that finish earlier are given higher priority because they
 * leave more time for scheduling subsequent meetings.
 *
 * @param first First meeting.
 * @param second Second meeting.
 * @return true if the first meeting finishes before the second meeting.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
static bool comparator(Data& first, Data& second) {
    return first.end < second.end;
}

/**
 * @brief Finds the maximum number of non-overlapping meetings that can
 * be scheduled in a single room.
 *
 * Each meeting is represented by:
 * - start[i] → Starting time.
 * - end[i]   → Ending time.
 *
 * Only one meeting can be conducted at a time.
 *
 * Example:
 *
 * Start:
 * 1 3 0 5 8 5
 *
 * End:
 * 2 4 6 7 9 9
 *
 * One optimal schedule:
 * (1,2)
 * (3,4)
 * (5,7)
 * (8,9)
 *
 * Maximum Meetings:
 * 4
 *
 * Algorithm:
 * 1. Combine the start time, end time, and original index into a single
 *    structure.
 * 2. Sort all meetings by increasing finishing time.
 * 3. Select the first meeting.
 * 4. Traverse the remaining meetings:
 *      - If a meeting starts strictly after the previously selected
 *        meeting ends, schedule it.
 * 5. Return the total number of scheduled meetings.
 *
 * Note:
 * - Choosing the meeting that finishes earliest is the greedy choice
 *   that maximizes the number of meetings.
 * - According to this implementation, two meetings cannot overlap even
 *   at their endpoints since the condition used is:
 *      start > previousEnd
 *
 * @param start Array containing meeting start times.
 * @param end Array containing meeting end times.
 * @return int Maximum number of meetings that can be scheduled.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * where:
 * - n = number of meetings.
 */
int maxMeetings(vector<int>& start, vector<int>& end) {

    int n = start.size();

    // Combine meeting information.
    vector<Data> meetings(n);

    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i + 1;
    }

    // Sort meetings by finishing time.
    sort(meetings.begin(), meetings.end(), comparator);

    vector<int> scheduledMeetings;

    // Select the first meeting.
    scheduledMeetings.push_back(meetings[0].pos);
    int lastFinishTime = meetings[0].end;

    // Schedule remaining meetings.
    for (int i = 1; i < n; i++) {

        if (meetings[i].start > lastFinishTime) {

            scheduledMeetings.push_back(meetings[i].pos);
            lastFinishTime = meetings[i].end;
        }
    }

    return scheduledMeetings.size();
}