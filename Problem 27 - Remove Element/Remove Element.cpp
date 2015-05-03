#include <iostream>
#include <algorithm>

using namespace std;

int removeElement(int [], int, int);

int main()
{
    const int n = 2;
    int A[n] = {1, 1};
    int n_;
    n_= removeElement(A, n, 0);

    for (int i = 0; i < n_; i++)
        cout << A[i] << " ";
    return 0;
}

int removeElement(int A[], int n, int elem)
{
    int n_ = n;        // Length of A[] after removing the instances

    if (n_ != 0)
        for (int i = 0; i < n_; i++) {
            if (A[i] == elem) {
                A[i] = A[n_-1];
                i--;
                n_--;
            }
        }
    return n_;
}
