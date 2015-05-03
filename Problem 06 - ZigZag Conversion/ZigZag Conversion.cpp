#include <string>
#include <iostream>

using namespace std;

string convert(string, int);

int main()
{
    string text;
    int nRows;

    cin >> text >> nRows;

    cout << convert(text, nRows);

    return 0;
}

string convert(string text, int nRows)
{
    string text_c;
    int n = min(nRows, int(text.size()));
    int Diff = (nRows > 1)? (nRows*2-2): 1;     // Periodic Difference dependent on nRows
    int diff;                                   // Variable Difference on every Row
    int index;                                  // Index of the picked Character

    for (int i = 0; i < n; i++) {               // Navigating on the i-th Row
        if ((diff = Diff - i*2) == 0)
            diff = Diff;
        index = i;
        while (index < text.size()) {
            text_c.push_back(text[index]);
            index = index + diff;
            if ((diff = Diff - diff) == 0)
                diff = Diff;
        }
    }
    return text_c;
}
