#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCombinations(string);

int main()
{
    string digits("25");
    vector<string> LC;

    LC = letterCombinations(digits);

    for (int i = 0; i < LC.size(); i++)
        cout << LC[i] << " ";
    cout << endl;

    return 0;
}

vector<string> letterCombinations(string digits)
{
    vector<string> LC;

    if (digits.empty()) {
        LC.push_back("");
        return LC;
    }

    char num3LetterMap[6][3] = {{'a', 'b', 'c'},
                                {'d', 'e', 'f'},
                                {'g', 'h', 'i'},
                                {'j', 'k', 'l'},
                                {'m', 'n', 'o'},
                                {'t', 'u', 'v'}};

    char num4LetterMap[2][4] = {{'p', 'q', 'r', 's'},
                                {'w', 'x', 'y', 'z'}};

    vector<char> numLetterMap[10];
    int j = 0, k = 0;
    for (int i = 2; i < 10; i++) {
        if ((i == 7)||(i == 9)) {
            numLetterMap[i].assign(num4LetterMap[k], num4LetterMap[k]+4);
            k++;
        }
        else {
            numLetterMap[i].assign(num3LetterMap[j], num3LetterMap[j]+3);
            j++;
        }
    }

    string lC;  // Concatenated string up to nDigits-2 digit
    const int nDigits = digits.size();
    int iBound[nDigits];    // index boundary at some digit
    int index[nDigits];     // index at some digit
    int digit = 0;

    fill(index, index+nDigits, 0);  // Initialize index[] = {0};

    for (int i = 0; i < nDigits; i++)
        iBound[i] = numLetterMap[digits[i]-'0'].size(); // Initialize iBound[i] with number of possible combinations of digits[i]

    while (digit >= 0) {
        if (digit == nDigits-1) {   // When the last digit is reached
            for (int i = 0; i < iBound[digit]; i++)
                LC.push_back(lC + numLetterMap[digits[digit]-'0'][i]);
            if (--digit >= 0)   // Caution about the last case: cannot pop_back() if lC is empty
                lC.pop_back();  // When going back to the previous digit, the last number has to be pop out
        }
        else if (index[digit] == iBound[digit]) {   // When index is reaching the index boundary
            index[digit] = 0;
            if (--digit >= 0)   // Caution about the last case: cannot pop_back() if lC is empty
                lC.pop_back();  // When going back to the previous digit, the last number has to be pop out
        }
        else {  // When neither the last digit or the index boundary is reached
            lC.push_back(numLetterMap[digits[digit]-'0'][index[digit]]);    // Record the possible combination number at (digit, index[digit])
            index[digit++]++;
        }
    }
    return LC;
}
