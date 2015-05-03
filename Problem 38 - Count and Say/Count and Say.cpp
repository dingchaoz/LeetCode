#include <iostream>
#include <string>

using namespace std;

string countAndSay(int);

int main()
{
    int n;

    cin >> n;
    cout << countAndSay(n);

    return 0;
}

string countAndSay(int n)
{
    string cAS("1");
    string cAS_;

    int j;
    int k = 1;                          // Count for the identical figures

    for (int i = 0; i < n-1; i++) {     // Within the loop calculate i-th cAS
        j = 0;
        cAS_ = "";
        while (cAS[j]) {                // Navigate through each j-th character in i-th cAS
            if ((cAS[j] == cAS[j+1]))
                k++;
            else {
                cAS_.append(to_string(k));  // Insert number of counted identical figures
                cAS_.push_back(cAS[j]);     // Insert the figure
                k = 1;
            }
            j++;
        }
        cAS = cAS_;
    }
    return cAS;
}
