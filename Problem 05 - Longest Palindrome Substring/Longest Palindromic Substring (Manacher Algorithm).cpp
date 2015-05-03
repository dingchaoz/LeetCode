#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string);
int newSpan(string, int, int);

int main()
{
    string s("esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq");

    cout << longestPalindrome(s);

    return 0;
}

string longestPalindrome(string s)
{
    if (s.empty())
        return s;

    string t(".");

    for (int i = 0; i < s.size(); i++) {    // If s = 12345, then t is transformed to .1.2.3.4.5.
        t.push_back(s[i]);
        t.push_back('.');
    }

    const int tSize = t.size();
    int p[tSize];   // Record the largest span at each position i. This essentially record the largest palindrome at i, [i-span, i+span]

    int R = 0, C = 0;   // R is the rightward boundary set by center i = C and its span
    int j;  // i is the mirrored index of i with respect of mirror center C: j = 2C - i

    int indexLP = 0;    // Keep track of the center where the longest palindrome happens
    int spanLP = 0;     // Keep track of the span of the longest palindrome

    for (int i = 0; i < t.size(); i++) {
        j = 2*C - i;
        if (i + p[j] < R)   // Read the 1st reply on Page 8 of the pdf: Manacher Algorithm
            p[i] = p[j];
        else
            p[i] = newSpan(t, i, R-i);

        if (i + p[i] > R) {
            C = i;
            R = i + p[i];
        }

        if (p[i] > spanLP) {    // Update the info of the longest palindrome
            spanLP = p[i];
            indexLP = i;
        }
    }
    return s.substr(indexLP/2-spanLP/2, spanLP); // indexLP/2 is the center of palindrome of s, and the length of palindrome in s happens to be span
}

inline int newSpan(string t, int i, int span)   // Return the new span given that at i we know its span >= span
{
    int j = span+1;
    while (1) {
        if ((i+j >= t.size())||(i-j < 0))   // Reaching left or right boundary of the string
            break;
        if (t[i+j] != t[i-j])
            break;
        j++;
    }
    j--;
    return j;
}
