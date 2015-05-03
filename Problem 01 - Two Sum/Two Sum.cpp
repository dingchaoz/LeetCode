#include <iostream>
#include <vector>
#include <utility>      // std::pair
#include <algorithm>    // std::sort


using namespace std;

vector<int> twoSum(vector<int> &, int);
static inline bool compare(const pair<int, int>&, const pair<int, int>&);   // Declare inline for efficiency

int main()
{
    const int nSize = 3;
    int a_numbers[nSize] = {3,2,4};
    int target = 6;
    vector<int> numbers(a_numbers, a_numbers+nSize);
    vector<int> tS;

    tS = twoSum(numbers, target);

    for (vector<int>::iterator it = tS.begin(); it < tS.end(); it++)
        cout << *it << " ";

    return 0;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> tS(2, 0);
    vector<pair<int, int>> numPairs;    // Create the vector of the pairs to record the value - index relation

    vector<pair<int, int>>::iterator it;    // To return the position of the found element from the binary search of the vector of pairs

    for (int i = 0; i < numbers.size(); i++)
        numPairs.push_back(make_pair(numbers[i], i));

    sort(numPairs.begin(), numPairs.end()); // Sort numPairs so that the binary search can be applied

    pair<int, int> lookUp;  // Create the pair object with lookUp.first being the number to search for
    int index;  // tS[0] and tS[1] has to be reported in the ascending order, and index helps the implementation

    for (int i = 0; i < numPairs.size(); i++) {
        lookUp = make_pair(target-numPairs[i].first, 0);
        it = lower_bound(numPairs.begin()+i+1, numPairs.end(), lookUp, compare);    // Report the position of the lower bound. "compare" is the function handle
        if ((it != numPairs.end())&&((*it).first == lookUp.first)) {    // Check if it is found and the same with the searched element
            index = (numPairs[i].second < (*it).second)? 0: 1;
            tS[index] = numPairs[i].second+1;
            tS[1-index] = (*it).second+1;
            return tS;
        }
    }
    return tS;
}

static bool compare(const pair<int, int>& lh, const pair<int, int>& rh) // LeetCode require the function handle to be static
{
    return lh.first < rh.first;
}
