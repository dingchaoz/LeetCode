#include <iostream>

using namespace std;

void mergeAB(int [], int, int [], int);

int main()
{
    const int m = 75;
    const int n = 34;
    int A[m+n] = {-10,-10,-10,-9,-9,-8,-8,-8,-8,-8,-7,-7,-7,-7,-6,-6,-6,-5,-5,-5,-5,-5,-4,-4,-4,-4,-4,-4,-4,-3,-3,-3,-3,-3,-3,-2,-2,-2,-1,-1,-1,0,1,1,1,1,1,1,2,2,2,3,3,4,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9};
    int B[n] = {-10,-9,-9,-9,-8,-7,-7,-7,-6,-5,-5,-5,-3,-2,-2,-1,1,1,2,3,4,4,4,4,5,5,6,6,7,7,8,8,9,9};

    mergeAB(A, m, B, n);

    return 0;
}

void mergeAB(int A[], int m, int B[], int n)
{
    if (m == 0) // if A[] is empty, mergedAB = B; if B[] is empty, mergeAB = A
        for (int k = 0; k < n; k++)
            A[k] = B[k];

    if ((m != 0)&&(n != 0)) {   // if A[] and B[] are both non-empty
        const int sizeC = m+n;
        int C[sizeC];
        int i = 0, j = 0;

        while (1) {
            if (A[i] < B[j])
                C[i+j] = A[i++];
            else
                C[i+j] = B[j++];

            if (i == m) {   // A[] has been depleted
                for (int k = j; k < n; k++)
                    C[m+k] = B[k];  // Attach the remaining of B[] to mergeAB and finish the process
                break;
            }
            if (j == n) {   // B[] has been depleted
                for (int k = i; k < m; k++)
                    C[n+k] = A[k];  // Attach the remaining of A[] to mergeAB and finish the process
                break;
            }
        }
        for (int k = 0; k < m+n; k++)
            A[k] = C[k];
    }

    for (int k = 0; k < m+n; k++)
        cout << A[k] << " ";
}
