#include <iostream>

using namespace std;

int atoi(const char*);

int main()
{
    //const char* str = "  -2147483646+ 80vdxv";   // Has to be constant char* type
    const char* str = "    -00134";   // Has to be constant char* type

    cout << atoi(str);

    return 0;
}

int atoi(const char *str)
{
    int ustoi = 0;   // unsigned string to int
    int stoi = 0;    // signed string to int
    // preNum: before building int; startNum: start building int; inNum: in the process of building int
    bool preNum = true, startNum = false, inNum = false;

    if (!str)
        return 0;

    int i = 0;
    int sign = 1;   // Positive when sign = 1 and negative when sign = -1
    long long int _intMAX = 2147483647; // Note long int is not enough to hold -_intMAX = -2147483648

    int a;
    while (a = str[i]) {
        if (a == ' ') {     // ' ' can only occur when preNum = true and inNum = true
            if (startNum)
                return 0;
            if (inNum)      // Indicate the end of building int
                break;
        }
        else if ((a == '+')||(a == '-')) {  // '+', '-' triggers startNum = true
            if (preNum) {
                preNum = false;
                startNum = true;
            }
            else if (startNum)  // Consecutive '+' or '-' is invalid
                return 0;
            else
                break;

            if ((sign = 44 - a) < 0)  // ASCII: '+' = 43, ',' = 44, '-' = 45
                _intMAX = 2147483648;   // For negative number, the lower bound is -2147483648
        }
        else if ((a > '0'-1)&&(a < '9'+1)) {    // Building int
            if (preNum||startNum) {
                preNum = false;
                startNum = false;
                inNum = true;
            }
            if (ustoi <= (_intMAX - (a-'0'))/10) {  // Check if the resulting ustoi < _intMAX. Note the usage of <= instead of <
                ustoi = ustoi*10 + a-'0';
                stoi = sign*ustoi;
            }
            else
                return sign*_intMAX;
        }
        else {  // Any other character can only occur in the preNum stage, which mark the end of building int
            if (preNum||startNum)
                return 0;
            else
                break;
        }
        i++;
    }
    return stoi;
}
