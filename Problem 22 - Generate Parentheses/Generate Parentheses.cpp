#include <iostream>
#include <vector>

using namespace std;

vector<string> generateParenthesis(int);
void parRecursion(int, int, vector<string>&, string);

int main()
{
    int n;
    vector<string> gP;

    cin >> n;
    gP = generateParenthesis(n);

    for (int i = 0; i < gP.size(); i++)
        cout << gP[i] << endl;
    return 0;
}

vector<string> generateParenthesis(int n)
{
    vector<string> gP;  // gP: Vector of strings that contains all possible parenthesis combinations
    string ps;          // ps: One of the possible parenthesis combination

    parRecursion(n, n, gP, ps);

    return gP;
}

void parRecursion(int nLPar, int nRPar, vector<string>& gP, string ps)  // nLPar(nRPar): Number of the unused left(right) parenthesis
{
    if (nLPar < nRPar) {    // When nLPar < nRPar, either a "(" or a ")" can be the next parenthesis in ps
        if (nLPar > 0)  // nLPar has not depleted
            parRecursion(nLPar-1, nRPar, gP, ps+"(");
        parRecursion(nLPar, nRPar-1, gP, ps+")");
    }
    else if (nRPar == 0)    // End of configuring a possible parenthesis combination
        gP.push_back(ps);
    else    // The case of nLPar == nRPar != 0: only a "(" can be the next parenthesis in ps
        parRecursion(nLPar-1, nRPar, gP, ps+"(");
}
