#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Comparator used to sort jobs in descending order of profit.
 *
 * If two jobs have the same profit, the job with the smaller deadline
 * is given higher priority.
 *
 * Job representation:
 * jobs[i] = {jobId, deadline, profit}
 *
 * @param a First job.
 * @param b Second job.
 * @return true if job 'a' should appear before job 'b'; otherwise false.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
static bool comparator(const vector<int>& a,
                       const vector<int>& b) {

    if (a[2] == b[2])
        return a[1] < b[1];

    return a[2] > b[2];
}

/**
 * @brief Schedules jobs to maximize the total profit while meeting
 * their deadlines using a greedy algorithm.
 *
 * Each job requires exactly one unit of time.
 *
 * A job can only be performed if it finishes on or before its deadline.
 * At most one job can be executed in a single time slot.
 *
 * Job format:
 * jobs[i] = {jobId, deadline, profit}
 *
 * Example:
 *
 * Jobs:
 * {1, 4, 20}
 * {2, 1, 10}
 * {3, 1, 40}
 * {4, 1, 30}
 *
 * After sorting by profit:
 * {3, 1, 40}
 * {4, 1, 30}
 * {1, 4, 20}
 * {2, 1, 10}
 *
 * Scheduled Jobs:
 * Job 3 → Slot 1
 * Job 1 → Slot 4
 *
 * Total Jobs:
 * 2
 *
 * Total Profit:
 * 60
 *
 * Algorithm:
 * 1. Sort all jobs in decreasing order of profit.
 * 2. Find the maximum deadline to determine the number of available
 *    time slots.
 * 3. Create an array representing the schedule.
 * 4. For every job:
 *      - Try to place it in the latest available slot before its
 *        deadline.
 *      - If a free slot exists, schedule the job.
 * 5. Return:
 *      - Number of scheduled jobs.
 *      - Total profit earned.
 *
 * Note:
 * - Scheduling a job as late as possible leaves earlier slots available
 *   for jobs with smaller deadlines.
 * - This greedy strategy produces the maximum possible profit.
 *
 * @param jobs Array containing {jobId, deadline, profit}.
 * @return vector<int>
 *         result[0] = Number of jobs scheduled.
 *         result[1] = Maximum profit earned.
 *
 * Time Complexity: O(n log n + n × d)
 * Space Complexity: O(d)
 * where:
 * - n = number of jobs.
 * - d = maximum deadline.
 */
vector<int> JobScheduling(vector<vector<int>>& jobs) {

    // Sort jobs by decreasing profit.
    sort(jobs.begin(), jobs.end(), comparator);

    int maximumDeadline = -1;

    // Find the largest deadline.
    for (const auto& job : jobs)
        maximumDeadline = max(maximumDeadline, job[1]);

    // Time slots.
    vector<int> schedule(maximumDeadline, -1);

    int jobsCompleted = 0;
    int totalProfit = 0;

    for (const auto& job : jobs) {

        // Try to place the job in the latest available slot.
        for (int slot = job[1] - 1; slot >= 0; slot--) {

            if (schedule[slot] == -1) {

                schedule[slot] = job[0];
                jobsCompleted++;
                totalProfit += job[2];

                break;
            }
        }
    }

    return {jobsCompleted, totalProfit};
}