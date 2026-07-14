#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Finds the kth largest element in an array using a max heap.
 *
 * A max heap stores the largest element at the top. By repeatedly removing
 * the largest element (k - 1) times, the top of the heap becomes the kth
 * largest element.
 *
 * Example:
 * nums = {3, 2, 1, 5, 6, 4}
 * k = 2
 *
 * Max Heap:
 * 6, 5, 4, 3, 2, 1
 *
 * Remove:
 * - 6
 *
 * Top of heap:
 * 5
 *
 * Returns:
 * 5
 *
 * Algorithm:
 * 1. Build a max heap from all elements in the array.
 * 2. Remove the largest element (k - 1) times.
 * 3. The top of the heap is the kth largest element.
 *
 * Note:
 * - This approach modifies only the heap, not the input array.
 * - A min heap of size k can reduce the space complexity to O(k).
 *
 * @param nums Input array.
 * @param k Position of the required largest element (1-based).
 * @return int The kth largest element in the array.
 *
 * Time Complexity: O(n + k log n)
 * Space Complexity: O(n)
 * where:
 * - n = number of elements in the array.
 */
int kthLargestElement(vector<int>& nums, int k) {
    priority_queue<int> maxHeap(nums.begin(), nums.end());

    while (k > 1) {
        maxHeap.pop();
        k--;
    }

    return maxHeap.top();
}