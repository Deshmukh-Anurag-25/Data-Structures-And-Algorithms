#include <vector>
using namespace std;

/**
 * @brief Computes the minimum number of candies required to distribute
 * among children based on their ratings.
 *
 * Rules:
 * 1. Every child must receive at least one candy.
 * 2. A child with a higher rating than an adjacent child must receive
 *    more candies than that neighbor.
 *
 * This solution uses the slope approach, treating increasing and
 * decreasing rating sequences as upward and downward slopes.
 *
 * - An increasing slope assigns candies as:
 *      1, 2, 3, ...
 * - A decreasing slope assigns candies as:
 *      ..., 3, 2, 1
 *
 * If a decreasing slope is longer than the preceding increasing slope,
 * the peak child must receive additional candies so that it remains
 * greater than both neighbors.
 *
 * Example:
 * ratings = [1,0,2]
 *
 * Candies:
 * 2 1 2
 *
 * Total = 5
 *
 * Example:
 * ratings = [1,2,2]
 *
 * Candies:
 * 1 2 1
 *
 * Total = 4
 *
 * Algorithm:
 * 1. Give the first child one candy.
 * 2. Skip equal ratings by giving one candy.
 * 3. Count the length of every increasing slope.
 * 4. Count the length of every decreasing slope.
 * 5. If the decreasing slope is longer than the increasing slope,
 *    increase the peak candy count accordingly.
 * 6. Continue until every child is processed.
 *
 * @param ratings Rating of each child.
 * @return int Minimum total candies required.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of children.
 */
class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        int i = 1;
        int totalCandies = 1;

        while (i < n) {

            // Equal ratings.
            if (ratings[i] == ratings[i - 1]) {
                totalCandies++;
                i++;
                continue;
            }

            // Increasing slope.
            int peakCandies = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peakCandies++;
                totalCandies += peakCandies;
                i++;
            }

            // Decreasing slope.
            int downCandies = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                totalCandies += downCandies;
                downCandies++;
                i++;
            }

            // Adjust the peak if the descending slope is longer.
            if (downCandies > peakCandies) {
                totalCandies += (downCandies - peakCandies);
            }
        }

        return totalCandies;
    }
};