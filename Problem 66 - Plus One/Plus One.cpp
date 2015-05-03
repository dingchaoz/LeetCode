#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>&);

int main()
{
    const int sizeA = 3;
    int a[sizeA] = {7, 9, 9};
    vector<int> digits(a, a+sizeA);
    vector<int> pO;

    pO = plusOne(digits);

    for (vector<int>::iterator it = pO.begin(); it < pO.end(); it++)
        cout << *it;

    return 0;
}

vector<int> plusOne(vector<int> &digits)
{
    int sum;
    int carry = 1;  // For the initial "plus one"

    for (int i = digits.size()-1; i >= 0; i--) {
        sum = (digits[i] + carry);  // Addition at each digit
        digits[i] = sum%10;
        carry = sum > 9? 1: 0;
    }
    if (carry > 0)  // If the addition at the largest digit is larger than 1, put 1 in the front
        digits.insert(digits.begin(), 1);

    return digits;
}
