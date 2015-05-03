#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intToRoman(int);

int main()
{
    int num = 4015;
    cout << intToRoman(num);

    return 0;
}

string intToRoman(int num)
{
    string numRoman;            // Roman representation of num
    string iTR;                 // Roman representation at each digit
    const int nRL = 2;          // Number of Roman letters
    const int nDigit = 4;       // Number of possible digits with systematic representation

    string syms[nDigit][nRL] = {{"I", "V"},
                                {"X", "L"},
                                {"C", "D"},
                                {"M", "MMMMM"}};
    int digit = 0;
    int numDigit;               // Number at the digit
    while (num != 0) {
        iTR = "";
        numDigit = num%10;
        if ((numDigit == 4)&&(digit < nDigit-1))        // Notice the special representation of 4 does not work at digit of 10^3
            iTR = syms[digit][0] + syms[digit][1];
        else if ((numDigit == 9)&&(digit < nDigit-1))   // Notice the special representation of 9 does not work at digit of 10^3
            iTR = syms[digit][0] + syms[digit+1][0];
        else {                                          // For numbers other than 4 or 9, represent them w/wo a 5 and 1s
            if (numDigit >= 5) {
                iTR = syms[digit][1];
                numDigit = numDigit - 5;
            }
            for (int i = 0; i < numDigit; i++)
                iTR = iTR + syms[digit][0];
        }
        numRoman = iTR + numRoman;
        num = num/10;
        digit++;
    }
    return numRoman;
}
