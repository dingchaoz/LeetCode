#include <iostream>
#include <climits>

using namespace std;

int divide(int, int);

int main()
{
    int dividend = 20, divisor = 3;
    int quotient;

    quotient = divide(dividend, divisor);

    cout << quotient;

    return 0;
}

int divide(int dividend, int divisor)
{
    long a = labs(dividend); // labs: the absolute value in long int form
    long b = labs(divisor);
    long sign = (dividend < 0)^(divisor < 0)? -1: 1;   // ^ is the XOR operator

    if (b == 0) // If divisor is 0
        return INT_MAX;
    if ((dividend == INT_MIN)&&(divisor == -1))
        return INT_MAX;

    if (divisor == 1)
        return dividend;

    long quotient = 0;  // Quotient
    long qExp;  // Exponentially grown number of b that fills a

    while (a >= b) {
        qExp = 1;
        while (a >= b*qExp) {
            a -= b*qExp;        // b*qExp exponentially grows
            quotient += qExp;
            qExp = (qExp << 1);
        }
    }
    return int(quotient*sign);
}
