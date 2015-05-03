#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &);

int main()
{
    vector<string> strs;
    string word;
    int nWords;     // Numbers of strings in vector<string> strs

    cin >> nWords;

    for (int i = 0; i < nWords; i++) {
        cin >> word;
        strs.push_back(word);
    }
    cout << longestCommonPrefix(strs);

    return 0;
}

string longestCommonPrefix(vector<string> &strs)
{
    string lCP;         // Longest Common Prefix
    if (!strs.empty())
        for (int i = 0; i < strs[0].size(); i++) {  // Take every characters in the 1st string as reference
            for (int j = 1; j < strs.size(); j++) { // Navigate through the remaining (nWords-1) strings
                if (strs[0][i] != strs[j][i])       // Compare the i-th character in the 1st and j-th string
                    return lCP;
            }
            lCP = lCP + strs[0][i];
        }
    return lCP;
}
