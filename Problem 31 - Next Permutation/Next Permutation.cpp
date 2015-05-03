#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &);

int main()
{
    int numArray[] = {1, 1, 5};
    vector<int> num(numArray, numArray + sizeof(numArray)/sizeof(int));

    nextPermutation(num);

    for (int i = 0; i < num.size(); i++)
        cout << num[i] << " ";

    return 0;
}

void nextPermutation(vector<int> &num)
{
    // We will eventually find 2 positions i, j (j is behind i) in num to swap. Then after swap i is behind j and we will sort the remaining numbers after i
    auto posTail = end(num)-1;
    auto posSwapHead = begin(num)-1;    // To record the most updated position i. Note the initial value is not begin(num) but begin(num)-1 so that we can distinguish if posSwapHead has ever been updated
    auto posSwapTail = posTail;         // To record the most updated position j
    auto posComp = posSwapTail-1;       // Navigate to find possible posSwapHead

    while (posSwapHead < posTail) {     // Start looking for possible position j from the tail of num
        posComp = posTail-1;
        while (posSwapHead < posComp) { // Navigate posComp toward the head of num
            if ((*posTail > *posComp)&&(posSwapHead < posComp)) {   // Update posSwapHead and posSwapTail only if the swapping will make new num larger and if the updated posSwapHead is closer to the tail of num
                posSwapHead = posComp;
                posSwapTail = posTail;
                break;
            }
            posComp--;
        }
        posTail--;
    }

    int temp;
    if (posSwapHead >= begin(num)) {    // posSwapHead < begin(num) would imply posSwapHead has never been updated and no swap should be performed
        temp = *posSwapTail;
        *posSwapTail = *posSwapHead;
        *posSwapHead = temp;
    }

    sort(posSwapHead+1, num.end());     // Sort is performed for the portion behind posSwapHead
}
