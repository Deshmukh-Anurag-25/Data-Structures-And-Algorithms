#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Finds the maximum score obtainable by picking exactly k cards
 * from either end of the array.
 *
 * Initially, the first k cards are chosen. The algorithm then gradually
 * replaces cards taken from the left end with cards taken from the right
 * end, considering every possible combination.
 *
 * Example:
 * cardScore = {1, 2, 3, 4, 5, 6, 1}
 * k = 3
 *
 * Possible selections:
 * {1,2,3} → 6
 * {1,2,1} → 4
 * {1,6,1} → 8
 * {5,6,1} → 12
 *
 * Returns:
 * 12
 *
 * Algorithm:
 * 1. Compute the sum of the first k cards.
 * 2. This represents taking all k cards from the left.
 * 3. One by one:
 *    - Remove a card from the left side.
 *    - Add a card from the right side.
 *    - Update the maximum score.
 * 4. Continue until all possible left/right combinations are examined.
 *
 * Note:
 * - Exactly k cards are always selected.
 * - There are only (k + 1) possible combinations.
 *
 * @param cardScore Array containing the score of each card.
 * @param k Number of cards to pick.
 * @return int Maximum obtainable score.
 *
 * Time Complexity: O(k)
 * Space Complexity: O(1)
 * where:
 * - k = number of cards selected.
 */
int maxScore(vector<int>& cardScore, int k) {

    int currentScore = 0;

    // Take the first k cards.
    for (int i = 0; i < k; i++) {
        currentScore += cardScore[i];
    }

    int maximumScore = currentScore;

    int left = k - 1;
    int right = cardScore.size() - 1;

    // Replace left cards with right cards one by one.
    while (left >= 0) {

        currentScore -= cardScore[left];
        currentScore += cardScore[right];

        maximumScore = max(maximumScore, currentScore);

        left--;
        right--;
    }

    return maximumScore;
}