#include <iostream>
#include <string>

using namespace std;

int romanToInt(string);

int main()
{
    string s;

    cin >> s;

    cout << romanToInt(s);

    return 0;
}
# TO add another function
int romanToInt(string s)
{
    int rInt = 0;
    const int nRL = 7;  // Number of Roman Letters
    char sym[nRL] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int value[nRL] = {1, 5, 10, 50, 100, 500, 1000};
    int sLen = s.size()-1;
    int maxDigit = 0;
    int j;      // sym[j] is the current letter in i-th digit

    for (int i =sLen; i>=0; i--) {
        j = 0;
        while (s[i] != sym[j]) j++;

        if (j >= maxDigit) {
            maxDigit = j;
            rInt = rInt + value[j];
        }
        else
            rInt = rInt - value[j];
    }
    return rInt;
}
