#include <iostream>

using namespace std;

int climbStairs(int);
int C(int, int);

int main()
{
    int n;

    cin >> n;
    cout << climbStairs(n);

    return 0;
}

int climbStairs(int n)
{
    int nC = 0; // Number of combinations of 1 or 2 steps

    for (int i = 0; i < n/2+1; i++) {
        nC = nC + C(n-i, i);
    }

    return nC;
}

int C(int n, int m)
{
    long int Cnm = 1;   // long int is used to deal with large factoring numbers

    // Do not calculate the nominator and denominator separately and divide: each of them can be too large and will violate the int format
    for (int i = 0; i < m; i++)
        Cnm = Cnm*(n-i)/(i+1);

    return Cnm;
}
