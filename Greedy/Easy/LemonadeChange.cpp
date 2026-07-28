#include <vector>
using namespace std;

/**
 * @brief Determines whether correct change can be provided to every
 * customer in a lemonade stand.
 *
 * Each lemonade costs $5.
 *
 * Customers pay using one of the following bills:
 * - $5
 * - $10
 * - $20
 *
 * Initially, the seller has no money.
 *
 * For every customer:
 * - A $5 bill requires no change.
 * - A $10 bill requires one $5 bill as change.
 * - A $20 bill requires either:
 *      - One $10 bill and one $5 bill, or
 *      - Three $5 bills.
 *
 * Example:
 * Bills:
 * 5 5 5 10 20
 *
 * Transactions:
 * - Receive $5
 * - Receive $5
 * - Receive $5
 * - Give one $5, receive one $10
 * - Give one $10 and one $5
 *
 * Returns:
 * true
 *
 * Algorithm:
 * 1. Maintain the number of available $5 and $10 bills.
 * 2. For each customer:
 *      - If the bill is $5, simply store it.
 *      - If the bill is $10, give one $5 as change.
 *      - If the bill is $20:
 *          - Prefer giving one $10 and one $5.
 *          - Otherwise, give three $5 bills.
 *          - If neither is possible, return false.
 * 3. If every customer receives correct change, return true.
 *
 * Note:
 * - Giving one $10 and one $5 for a $20 bill is always preferred,
 *   since it preserves more $5 bills for future transactions.
 *
 * @param bills Array containing the bill paid by each customer.
 * @return bool True if correct change can be given to every customer;
 *         otherwise false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * where:
 * - n = number of customers.
 */
bool lemonadeChange(vector<int>& bills) {

    // Number of available $5 and $10 bills.
    int fiveDollarBills = 0;
    int tenDollarBills = 0;

    for (int bill : bills) {

        if (bill == 5) {

            fiveDollarBills++;
        }
        else if (bill == 10) {

            if (fiveDollarBills == 0)
                return false;

            fiveDollarBills--;
            tenDollarBills++;
        }
        else {

            // Prefer giving one $10 and one $5.
            if (tenDollarBills > 0 && fiveDollarBills > 0) {

                tenDollarBills--;
                fiveDollarBills--;
            }
            else if (fiveDollarBills >= 3) {

                fiveDollarBills -= 3;
            }
            else {

                return false;
            }
        }
    }

    return true;
}