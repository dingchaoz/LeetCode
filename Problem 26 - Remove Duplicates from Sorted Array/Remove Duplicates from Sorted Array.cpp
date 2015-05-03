#include <iostream>

using namespace std;

int removeDuplicates(int [], int);

int main()
{
    const int n = 8;
    int A[n] = {0, 0, 1, 1, 2, 2, 2, 3};
    cout << removeDuplicates(A, n);
    return 0;
}

int removeDuplicates(int A[], int n)
{
    int n_ = n;        // Length of A[] after removing the duplicates
    int j = 1;         // index for the updated A[]

    if (n > 1) {
        int v = A[0];  // Current non-duplicated value
        for (int i = 1; i < n; i++) {
            if(v != A[i])
                A[j++] = v = A[i];
            else       // Encounter a duplicate
                n_--;
        }
    }
    return n_;
}
