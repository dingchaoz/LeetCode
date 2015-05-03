#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string addBinary(string, string);

int main()
{
    string a("1");
    string b("111");

    cout << addBinary(a, b);

    return 0;
}

string addBinary(string a, string b)
{
    int n = max(a.size(), b.size());
    int i_a = 0, i_b = 0;               // Integer value of a[j] and b[j]
    int carry = 0;
    string c(n, '0');

    for (int i = 0; i < n; i++) {
        if (i < a.size())
            i_a = a[a.size()-1-i]-'0';  // Perform addition from the end of string a
        else
            i_a = 0;                    // Once i runs larger than a.size()-1, take i_a = 0 for performing the addition

        if (i < b.size())
            i_b = b[b.size()-1-i]-'0';
        else
            i_b = 0;

        c[n-1-i] = '0'+(i_a+i_b+carry)%2;   // Performing addition at digit i and cast to char type
        carry = (i_a+i_b+carry) > 1? 1: 0;  // When the addition at some digit is larger than 1, carry  = 1
    }
    if (carry > 0)                      // If the addition at the largest digit is larger than 1, put 1 in the front
        c.insert(c.begin(), '1');

    return c;
}
