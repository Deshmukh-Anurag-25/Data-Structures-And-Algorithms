#include <vector>
using namespace std;

/**
 * @brief Counts the number of subarrays containing at most k odd numbers.
 *
 * The function uses the sliding window technique.
 *
 * Instead of storing the actual sum of elements, the window maintains the
 * count of odd numbers. Every even number contributes 0, while every odd
 * number contributes 1.
 *
 * Whenever the number of odd elements exceeds k, the window is shrunk from
 * the left until it becomes valid again.
 *
 * For every valid window ending at index `right`, all subarrays starting
 * between `left` and `right` are also valid.
 *
 * @param nums Input array.
 * @param k Maximum number of odd elements allowed.
 * @return int Number of subarrays containing at most k odd numbers.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of elements in the array.
 */
int countSubarray(vector<int>& nums, int k) {

    // No subarray can contain fewer than 0 odd numbers.
    if (k < 0)
        return 0;

    int left = 0;
    int right = 0;
    int oddCount = 0;
    int count = 0;

    while (right < nums.size()) {

        // Add the current element.
        oddCount += nums[right] % 2;

        // Shrink the window until it contains at most k odd numbers.
        while (oddCount > k) {
            oddCount -= nums[left] % 2;
            left++;
        }

        // Count all valid subarrays ending at 'right'.
        count += (right - left + 1);

        right++;
    }

    return count;
}

/**
 * @brief Counts the number of "nice" subarrays containing exactly k odd numbers.
 *
 * A nice subarray is one that contains exactly k odd numbers.
 *
 * Instead of counting these directly, the solution uses the identity:
 *
 * Exactly(k) =
 *     AtMost(k) − AtMost(k − 1)
 *
 * where:
 * - AtMost(k) counts all subarrays containing at most k odd numbers.
 * - AtMost(k − 1) removes those containing fewer than k odd numbers.
 *
 * Example:
 * nums = {1, 1, 2, 1, 1}
 * k = 3
 *
 * Valid subarrays:
 * {1,1,2,1}
 * {1,2,1,1}
 *
 * Returns:
 * 2
 *
 * Algorithm:
 * 1. Count subarrays containing at most k odd numbers.
 * 2. Count subarrays containing at most (k − 1) odd numbers.
 * 3. Their difference equals the number of subarrays containing exactly
 *    k odd numbers.
 *
 * Note:
 * - Each odd number contributes 1 to the window.
 * - Each even number contributes 0.
 * - Every element enters and leaves the sliding window at most once.
 *
 * @param nums Input array.
 * @param k Required number of odd elements.
 * @return int Number of nice subarrays.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of elements in the array.
 */
int numberOfSubarrays(vector<int>& nums, int k) {
    return countSubarray(nums, k) -
           countSubarray(nums, k - 1);
}