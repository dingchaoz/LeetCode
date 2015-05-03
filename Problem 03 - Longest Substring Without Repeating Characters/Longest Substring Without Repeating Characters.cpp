#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string);

int main()
{
    const char* a_s = "ggububgvfk";
    string s(a_s);
    cout << lengthOfLongestSubstring(s);
    return 0;
}

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
    return 0;

    int gMaxLength = 0, lMaxLength = 0; // gMaxLength is the global maximum length and lMaxLength is the local maximum length

    const int nCh = 96;     // In the ASCII table all 96 meaningful characters starts from ' '
    int ch[nCh] = {0};      // Record the number of occurrence of different characters in the substring
    int recPos[nCh] = {0};  // Record at which index does a specific character occur in string s
    int i_ch, j_ch;         // Transform the char to int value
    int headPos = 0;        // Specify the head position of the local substring

    int i = 0;
    while (s[i]) {
        i_ch = s[i] - ' ';
        if (++(ch[i_ch]) > 1) { // If there has been more than one identical char in the substring
            for (int j = headPos; j <= recPos[i_ch]; j++) { // Update the info of ch[] for the substring
                j_ch = s[j] - ' ';
                ch[j_ch]--; // by removing elements between headPos and where the duplication of the char occurs
            }
            headPos = recPos[i_ch]+1;   // The new headPos is next position of where the duplication of the char occurs
            lMaxLength = i-headPos+1;   // The new lMaxLength counts the elements between new headPos and i, the current index
        }
        else    // When no duplication occurs, increase lMaxLength
            lMaxLength++;
        recPos[i_ch] = i;   // Record i as the index where s[i] occurs in this substring

        if (lMaxLength > gMaxLength)    // Keep track of gMaxLength by inspecting if lMaxLength > gMaxLength
            gMaxLength = lMaxLength;
        i++;
    }
    return gMaxLength;
}
