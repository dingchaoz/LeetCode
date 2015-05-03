#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int);

int main()
{
    int x;

    cin >> x;

    cout << isPalindrome(x);

    return 0;
}

bool isPalindrome(int x)
{
    int n = 0;                  // Number of Digits
    int x_temp = x;

    if (x < 0)                  // Negative number not viewed as Palindrome
        return false;

    while ((x_temp = x_temp/10) != 0)
        n++;

    for (int i = 0; i < n/2+1; i++)
        if ((x/int(pow(10.0, double(n-i))))%10 != (x/int(pow(10.0, double(i))))%10) // Compare i-th digit and (n-i)-th digit
            return false;

    return true;
}
