#include <iostream>

using namespace std;

int reverse(int);

int main()
{
    int x;

    cin >> x;

    cout << reverse(x);

    return 0;
}

int reverse(int x)
{
    int x_r = 0;
    int x_temp = x;

    while (x_temp != 0){
        x_r = x_r + x_temp%10;
        if((x_temp = x_temp/10) != 0)
            x_r = x_r*10;
    }

    return x_r;
}
