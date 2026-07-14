#include <algorithm>
#include <stack>
#include <string>
using namespace std;

/**
 * @brief Removes exactly k digits from a number to produce the smallest
 * possible value.
 *
 * The algorithm uses a monotonic increasing stack.
 *
 * While traversing the digits from left to right:
 * - If the current digit is smaller than the digit at the top of the stack,
 *   removing the larger digit produces a smaller overall number.
 * - Continue removing larger digits while removals are still allowed.
 *
 * After processing all digits, if removals remain, remove digits from the
 * end since they are the largest remaining suffix.
 *
 * Leading zeros are removed before returning the final answer.
 *
 * Example:
 * num = "1432219"
 * k = 3
 *
 * Process:
 * 1432219
 * ↓ remove 4
 * 132219
 * ↓ remove 3
 * 12219
 * ↓ remove 2
 * 1219
 *
 * Returns:
 * "1219"
 *
 * Example:
 * num = "10200"
 * k = 1
 *
 * Returns:
 * "200"
 *
 * Algorithm:
 * 1. Traverse each digit from left to right.
 * 2. While:
 *    - the stack is not empty,
 *    - removals remain,
 *    - the current digit is smaller than the stack's top,
 *    remove the stack's top.
 * 3. Push the current digit.
 * 4. If removals remain, remove digits from the end.
 * 5. Build the answer from the stack.
 * 6. Remove leading zeros.
 * 7. If the result becomes empty, return "0".
 *
 * Note:
 * - Every digit is pushed and popped at most once.
 * - The stack maintains digits in increasing order whenever possible.
 *
 * @param num String representation of a non-negative integer.
 * @param k Number of digits to remove.
 * @return string The smallest possible number after removing exactly k digits.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of digits in the input string.
 */
string removeKdigits(string num, int k) {
    stack<char> st;

    for (char digit : num) {

        while (!st.empty() &&
               k > 0 &&
               st.top() > digit) {
            st.pop();
            k--;
        }

        st.push(digit);
    }

    // Remove remaining digits from the end.
    while (k > 0) {
        st.pop();
        k--;
    }

    if (st.empty())
        return "0";

    string result;

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    // Remove leading zeros (currently at the end because the string is reversed).
    while (!result.empty() && result.back() == '0')
        result.pop_back();

    reverse(result.begin(), result.end());

    return result.empty() ? "0" : result;
}