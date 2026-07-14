#include <stack>
#include <vector>
using namespace std;

/**
 * @brief Finds the Next Greater Element (NGE) for every element in an array.
 *
 * The Next Greater Element of an element is the first element to its right
 * that is strictly greater than it. If no such element exists, -1 is returned.
 *
 * The algorithm processes the array from right to left while maintaining a
 * monotonic decreasing stack. The stack stores potential next greater
 * elements for future indices.
 *
 * Example:
 * nums = {6, 8, 0, 1, 3}
 *
 * Result:
 * {8, -1, 1, 3, -1}
 *
 * Explanation:
 * 6 → 8
 * 8 → -1
 * 0 → 1
 * 1 → 3
 * 3 → -1
 *
 * Algorithm:
 * 1. Traverse the array from right to left.
 * 2. Remove all elements from the stack that are less than or equal to the
 *    current element since they cannot be the next greater element.
 * 3. If the stack is empty, the answer is -1.
 *    Otherwise, the top of the stack is the next greater element.
 * 4. Push the current element onto the stack.
 *
 * Note:
 * - The stack always remains monotonically decreasing from bottom to top.
 * - Every element is pushed and popped at most once.
 *
 * @param arr Input array.
 * @return vector<int> Array containing the next greater element for each index.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * where:
 * - n = number of elements in the array.
 */
vector<int> nextLargerElement(vector<int>& arr) {
    stack<int> st;
    vector<int> answer(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        answer[i] = st.empty() ? -1 : st.top();

        st.push(arr[i]);
    }

    return answer;
}