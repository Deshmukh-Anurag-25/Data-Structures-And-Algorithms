#include <string>
#include <vector>
using namespace std;

/**
 * @brief Counts the number of substrings containing at least one
 * occurrence of 'a', 'b', and 'c'.
 *
 * The algorithm uses the sliding window technique.
 *
 * Two pointers (`left` and `right`) maintain a window over the string.
 * The window is expanded by moving the right pointer until it contains
 * at least one 'a', one 'b', and one 'c'.
 *
 * Once the condition is satisfied:
 * - Every substring starting at `left` and ending at any position from
 *   `right` to the end of the string is also valid.
 * - Therefore, `(n - right)` valid substrings are counted at once.
 * - The window is then shrunk from the left to search for additional
 *   valid windows.
 *
 * Example:
 * s = "abcabc"
 *
 * Valid substrings include:
 * "abc"
 * "abca"
 * "abcab"
 * "abcabc"
 * "bca"
 * ...
 *
 * Returns:
 * 10
 *
 * Algorithm:
 * 1. Expand the window by moving the right pointer.
 * 2. Maintain the frequency of 'a', 'b', and 'c'.
 * 3. Whenever the window contains all three characters:
 *    - Add (n - right) to the answer.
 *    - Remove the leftmost character.
 *    - Continue shrinking the window while it remains valid.
 * 4. Continue until the right pointer reaches the end.
 *
 * Note:
 * - The window is always the smallest possible valid window before
 *   moving the right pointer again.
 * - Every character enters and leaves the window at most once.
 *
 * @param s Input string consisting only of 'a', 'b', and 'c'.
 * @return int Number of substrings containing at least one occurrence
 *         of each character.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = length of the string.
 */
int numberOfSubstrings(string s) {
    int n = s.size();

    // Frequency of 'a', 'b', and 'c' inside the current window.
    vector<int> frequency(3, 0);

    int left = 0;
    int right = 0;
    int count = 0;

    while (right < n) {

        // Expand the window.
        frequency[s[right] - 'a']++;

        // Shrink the window while it remains valid.
        while (frequency[0] > 0 &&
               frequency[1] > 0 &&
               frequency[2] > 0) {

            // Every extension of this window is also valid.
            count += (n - right);

            frequency[s[left] - 'a']--;
            left++;
        }

        right++;
    }

    return count;
}