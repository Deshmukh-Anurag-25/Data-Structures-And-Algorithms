#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Computes the maximum points a ninja can earn over n days using
 * space-optimized dynamic programming.
 *
 * Each day, the ninja can perform one of three tasks:
 * - Task 0
 * - Task 1
 * - Task 2
 *
 * The ninja cannot perform the same task on two consecutive days.
 *
 * Example:
 * matrix =
 * {
 *   {10, 40, 70},
 *   {20, 50, 80},
 *   {30, 60, 90}
 * }
 *
 * One optimal schedule:
 * Day 0 → Task 2 (70)
 * Day 1 → Task 1 (50)
 * Day 2 → Task 2 (90)
 *
 * Total Points:
 * 70 + 50 + 90 = 210
 *
 * Algorithm:
 * 1. Let prev[last] represent the maximum points achievable up to the
 *    previous day when the last performed task is 'last'.
 * 2. Initialize the values for Day 0.
 * 3. For every remaining day:
 *      - Try every possible last task.
 *      - For every valid task different from the last task:
 *            currentPoints =
 *                points[day][task] + prev[task]
 *      - Store the maximum value.
 * 4. Replace prev with the newly computed values.
 * 5. Return prev[3], which represents no restriction on the previous task.
 *
 * Note:
 * - State meanings:
 *      last = 0 → Task 0 cannot be performed today.
 *      last = 1 → Task 1 cannot be performed today.
 *      last = 2 → Task 2 cannot be performed today.
 *      last = 3 → No previous task restriction.
 * - Only the previous day's results are required, so the DP table is
 *   reduced to two arrays.
 *
 * @param matrix matrix[day][task] represents the points earned by
 *               performing a task on a particular day.
 * @return int Maximum points obtainable.
 *
 * Time Complexity: O(n × 4 × 3) ≈ O(n)
 * Space Complexity: O(4) ≈ O(1)
 * where:
 * - n = number of days.
 */
int ninjaTraining(vector<vector<int>>& matrix) {

    int n = matrix.size();

    // prev[last] stores the maximum points until the previous day.
    vector<int> prev(4, 0);

    // Base case: Day 0.
    prev[0] = max(matrix[0][1], matrix[0][2]);
    prev[1] = max(matrix[0][0], matrix[0][2]);
    prev[2] = max(matrix[0][0], matrix[0][1]);
    prev[3] = max(matrix[0][0],
                  max(matrix[0][1], matrix[0][2]));

    // Process each remaining day.
    for (int day = 1; day < n; day++) {

        vector<int> current(4, 0);

        for (int last = 0; last < 4; last++) {

            for (int task = 0; task < 3; task++) {

                if (task != last) {

                    current[last] = max(
                        current[last],
                        matrix[day][task] + prev[task]);
                }
            }
        }

        prev = current;
    }

    return prev[3];
}

/**
 * @brief Recursively computes the maximum points using memoization.
 *
 * The function explores every valid task choice while remembering
 * previously computed states.
 *
 * @param day Current day.
 * @param last Task performed on the previous day.
 * @param matrix Points matrix.
 * @param dp Memoization table.
 * @return int Maximum points obtainable up to the current day.
 *
 * Time Complexity: O(n × 4 × 3)
 * Space Complexity: O(n × 4) + O(n)
 */
int solve(int day,
          int last,
          vector<vector<int>>& matrix,
          vector<vector<int>>& dp) {

    if (day == 0) {

        int maximumPoints = 0;

        for (int task = 0; task < 3; task++) {

            if (task != last)
                maximumPoints = max(maximumPoints,
                                    matrix[0][task]);
        }

        return maximumPoints;
    }

    if (dp[day][last] != -1)
        return dp[day][last];

    int maximumPoints = 0;

    for (int task = 0; task < 3; task++) {

        if (task != last) {

            int points =
                matrix[day][task] +
                solve(day - 1, task, matrix, dp);

            maximumPoints = max(maximumPoints, points);
        }
    }

    return dp[day][last] = maximumPoints;
}