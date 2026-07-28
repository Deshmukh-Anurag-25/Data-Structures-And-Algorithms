#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief Finds the maximum number of students that can be satisfied by
 * assigning cookies using a greedy approach.
 *
 * Each student has a minimum cookie size requirement, and each cookie
 * has a fixed size.
 *
 * A student is satisfied if:
 * cookieSize >= studentGreed
 *
 * Each cookie can be assigned to at most one student, and each student
 * can receive at most one cookie.
 *
 * Example:
 * Students:
 * 1 2 3
 *
 * Cookies:
 * 1 1
 *
 * Only the first student can be satisfied.
 *
 * Returns:
 * 1
 *
 * Algorithm:
 * 1. Sort both the students' greed factors and the cookie sizes.
 * 2. Start with the least greedy student and the smallest cookie.
 * 3. If the current cookie satisfies the current student:
 *      - Assign the cookie.
 *      - Move to the next student.
 * 4. Otherwise:
 *      - Try a larger cookie.
 * 5. Continue until either all students or all cookies have been processed.
 *
 * Note:
 * - Assigning the smallest possible cookie to the least greedy student
 *   preserves larger cookies for greedier students, producing the
 *   maximum number of satisfied students.
 *
 * @param Student Array containing the greed factor of each student.
 * @param Cookie Array containing the size of each cookie.
 * @return int Maximum number of students that can be satisfied.
 *
 * Time Complexity: O(n log n + m log m)
 * Space Complexity: O(1)
 * where:
 * - n = number of students.
 * - m = number of cookies.
 */
int findMaximumCookieStudents(vector<int>& Student,
                              vector<int>& Cookie) {

    // Sort greed factors and cookie sizes.
    sort(Student.begin(), Student.end());
    sort(Cookie.begin(), Cookie.end());

    int student = 0;
    int cookie = 0;

    // Number of satisfied students.
    int satisfiedStudents = 0;

    while (student < Student.size() &&
           cookie < Cookie.size()) {

        // Current cookie satisfies the current student.
        if (Student[student] <= Cookie[cookie]) {
            satisfiedStudents++;
            student++;
        }

        // Move to the next cookie.
        cookie++;
    }

    return satisfiedStudents;
}