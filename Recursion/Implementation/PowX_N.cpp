#include <cmath>
using namespace std;

/**
 * @brief Computes x raised to the power n using Binary Exponentiation.
 *
 * Binary Exponentiation (Exponentiation by Squaring) reduces the number of
 * multiplications by repeatedly squaring the base and halving the exponent.
 * This makes the algorithm much faster than multiplying x by itself n times.
 *
 * The function also correctly handles negative exponents by computing the
 * reciprocal of the positive exponent result.
 *
 * Example:
 * x = 2, n = 10
 *
 * Computation:
 * 2^10 = (2^2)^5
 *      = 4^5
 *      = 4 × (4^2)^2
 *      = 4 × 16^2
 *      = 4 × 256
 *      = 1024
 *
 * Example:
 * x = 2, n = -2
 *
 * Returns:
 * 1 / (2^2) = 0.25
 *
 * Algorithm:
 * 1. If n is 0, return 1.
 * 2. If n is 1, return x.
 * 3. If n is even:
 *    - Square the base.
 *    - Recur for n / 2.
 * 4. If n is odd:
 *    - Multiply one x.
 *    - Recur for n - 1.
 * 5. If the original exponent is negative, return the reciprocal.
 *
 * Note:
 * - The exponent is converted to long long to safely handle INT_MIN.
 * - Binary exponentiation reduces the complexity from O(n) to O(log n).
 *
 * @param x The base.
 * @param n The exponent.
 * @return double The value of x raised to the power n.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 * where:
 * - n = absolute value of the exponent.
 */

double power(double x, long long n) {
    if (n == 0)
        return 1.0;

    if (n == 1)
        return x;

    if (n % 2 == 0)
        return power(x * x, n / 2);

    return x * power(x, n - 1);
}

double myPow(double x, int n) {
    long long exponent = n;

    if (exponent < 0)
        return 1.0 / power(x, -exponent);

    return power(x, exponent);
}