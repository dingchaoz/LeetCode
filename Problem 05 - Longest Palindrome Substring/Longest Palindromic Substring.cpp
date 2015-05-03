#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string);

int main()
{
//    string s("fngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvy");
    string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    cout << longestPalindrome(s);

    return 0;
}

string longestPalindrome(string s)
{
    if (s.empty())
        return s;

    // The string s will be reversed and slide along the original one in both forward and backward directions to match palindromes in overlapping cases
    int fwdCount, backCount;
    int fwdMaxCount = 0, backMaxCount = 0;  // local max counts on the mirrored-matched substring in both directions within each overlapping case
    int maxCount = 0, maxCountTemp; // maxCount is the global max counts on the longest palindrome
    int fwdTail, backTail, maxTail, maxTailTemp;    // The tails mark the end positions of the palindromes

    int i = 0;
    while (i < s.size()) {
        fwdCount = 0;
        backCount = 0;

        for (int j = i; j < s.size(); j++) {    // Slide in the forward direction to find the longest mirrored-matched substring
            if (s[j] == s[s.size()-1-j+i])
                fwdCount++;
            else
                fwdCount = 0;
            // For it to be palindromic, extra constrain has to be put on top of a mirrored substring: centered in the overlapping area of s and s reversed
            if ((fwdCount > fwdMaxCount) && (2*j-fwdCount+1 == i+s.size()-1)) { // Second condition is essentially (head + tail) = (i + (s.size()-1))/2
                fwdMaxCount = fwdCount;
                fwdTail = j;
                break;  // It is unique so once found we can terminate
            }
        }
        for (int k = 0; k < s.size()-i; k++) {    // Slide in the backward direction to find the longest matched mirrored substring
            if (s[k] == s[s.size()-1-i-k])
                backCount++;
            else
                backCount = 0;

            if ((backCount > backMaxCount) && (2*k-backCount+1 == s.size()-i-1)) {
                backMaxCount = backCount;
                backTail = k;
                break;
            }
        }

        maxCountTemp = (fwdMaxCount > backMaxCount)? fwdMaxCount: backMaxCount;
        maxTailTemp = (fwdMaxCount > backMaxCount)? fwdTail: backTail;

        if (maxCountTemp > maxCount) {
            maxCount = maxCountTemp;
            maxTail = maxTailTemp;
        }

        if (s.size()-i < maxCount)  // If the max counts on the longest palindrome has exceeded the overlapping area of s and s reversed, then terminate
            break;
        else
            i++;
    }
    return s.substr(maxTail-maxCount+1, maxCount);
}
