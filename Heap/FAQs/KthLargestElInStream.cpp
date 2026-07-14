#include <queue>
#include <vector>
using namespace std;

/**
 * @brief Maintains the kth largest element in a stream of integers.
 *
 * The class uses a min heap of fixed size k.
 *
 * - The heap always stores the k largest elements seen so far.
 * - The smallest element among these k elements (the heap's top)
 *   is the kth largest element overall.
 *
 * Example:
 * k = 3
 * Stream:
 * 4, 5, 8, 2
 *
 * Heap after construction:
 * {4, 5, 8}
 *
 * add(3):
 * Heap = {4, 5, 8}
 * Returns 4
 *
 * add(10):
 * Heap = {5, 8, 10}
 * Returns 5
 *
 * add(9):
 * Heap = {8, 9, 10}
 * Returns 8
 *
 * Algorithm:
 * 1. Maintain a min heap of size at most k.
 * 2. Insert every incoming value into the heap.
 * 3. If the heap size exceeds k, remove the smallest element.
 * 4. The top of the heap is always the kth largest element.
 *
 * Time Complexity:
 * - Constructor: O(n log k)
 * - add(): O(log k)
 *
 * Space Complexity: O(k)
 * where:
 * - k = required largest position.
 */
class KthLargest {
public:
    /// Min heap storing the k largest elements seen so far.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    /// Maximum size of the heap.
    int capacity = 0;

    /**
     * @brief Constructs the data structure.
     *
     * Inserts all initial numbers while ensuring the heap never
     * contains more than k elements.
     *
     * @param k Required largest position.
     * @param nums Initial stream of numbers.
     */
    KthLargest(int k, vector<int>& nums) {
        capacity = k;

        for (int value : nums) {
            minHeap.push(value);

            if (minHeap.size() > capacity)
                minHeap.pop();
        }
    }

    /**
     * @brief Adds a new value to the stream.
     *
     * The value is inserted into the min heap. If the heap grows
     * beyond size k, the smallest element is removed.
     *
     * @param val New value to insert.
     * @return int The current kth largest element.
     *
     * Time Complexity: O(log k)
     * Space Complexity: O(k)
     */
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > capacity)
            minHeap.pop();

        return minHeap.top();
    }
};