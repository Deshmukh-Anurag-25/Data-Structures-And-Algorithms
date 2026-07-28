#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Computes the average waiting time of all processes using the
 * Shortest Job First (SJF) scheduling algorithm.
 *
 * In the non-preemptive SJF algorithm:
 * - The process with the smallest burst time is executed first.
 * - Once a process starts execution, it runs to completion.
 *
 * The waiting time of a process is the total time it spends waiting
 * before its execution begins.
 *
 * Example:
 * Burst Times:
 * 4 3 7 1
 *
 * After sorting:
 * 1 3 4 7
 *
 * Waiting Times:
 * 0 1 4 8
 *
 * Average Waiting Time:
 * (0 + 1 + 4 + 8) / 4 = 3
 *
 * Algorithm:
 * 1. Sort all burst times in ascending order.
 * 2. The first process has a waiting time of 0.
 * 3. Every subsequent process waits for the sum of all previous burst
 *    times.
 * 4. Compute the total waiting time.
 * 5. Return the average waiting time.
 *
 * Note:
 * - Sorting the burst times minimizes the average waiting time.
 * - Integer division is used, matching the problem's return type.
 *
 * @param burstTime Array containing the burst time of each process.
 * @return long long Average waiting time of all processes.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * where:
 * - n = number of processes.
 */
long long solve(vector<int>& burstTime) {

    // Execute shorter jobs first.
    sort(burstTime.begin(), burstTime.end());

    int n = burstTime.size();

    // Waiting time for each process.
    vector<int> waitingTime(n);

    waitingTime[0] = 0;

    for (int i = 1; i < n; i++) {

        waitingTime[i] =
            waitingTime[i - 1] +
            burstTime[i - 1];
    }

    long long totalWaitingTime = 0;

    for (int time : waitingTime)
        totalWaitingTime += time;

    return totalWaitingTime / n;
}