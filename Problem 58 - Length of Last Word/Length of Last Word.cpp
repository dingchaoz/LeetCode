#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(const char*);

int main()
{
    const char* s = "ab ab ";

    cout << lengthOfLastWord(s);

    return 0;
}

int lengthOfLastWord(const char *s)
{
    int c = 0;              // Character count of last word
    bool isWord = true;     // Whether it is in the state of "a word"

    int i = 0;
    while (s[i]) {
        if (s[i] != ' ') {
            if (isWord)     // Whether the previous state is in "a word"
                c++;        // If yes, keep accumulating counts
            else
                c = 1;      // If not, start a new count from 1
            isWord = true;
        }
        else
            isWord = false;
        i++;
    }

    return c;
}
