#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

bool isValid(string);

int main()
{
    string s;
    cin >> s;
    cout << isValid(s);
    return 0;
}

bool isValid(string s)
{
    const int nPar = 3;
    char rParPool[nPar] = {'(', '[', '{'};
    char lParPool[nPar] = {')', ']', '}'};
    stack<char> rParStack;   // Right-hand parentheses
    char* pos;                 // Position of the found left-hand parentheses

    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (find(rParPool, rParPool+nPar, *it) != rParPool+nPar)
            rParStack.push(*it);
        else if ((pos = find(lParPool, lParPool+nPar, *it)) != lParPool+nPar) {
            if (rParStack.empty())
                return false;
            else if (rParStack.top() == rParPool[distance(lParPool, pos)])  // distance(a, b) give the index difference between pointers a and b
                rParStack.pop();    // .pop() is of type void
            else
                return false;
        }
        else {}
    }
    if (rParStack.empty())
        return true;
    else
        return false;
}
