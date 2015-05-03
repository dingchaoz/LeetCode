#include <iostream>

using namespace std;

int strStr(const char*, const char*);

int main()
{
    const char* haystack = "mississippi";
    const char* needle = "issip";

    cout << strStr(haystack, needle);

    return 0;
}

int strStr(const char *haystack, const char *needle)
{
    int i = 0;  // Navigate through haystack
    int j = 0;  // Navigate through needle

    if (!needle[0])
        return 0;

    while (haystack[i]) {
        if (haystack[i++] == needle[j]) {
            if (!needle[++j]) return i-j;
        }
        else {
            i = i-j;
            j = 0;
        }
    }
    return -1;
}
