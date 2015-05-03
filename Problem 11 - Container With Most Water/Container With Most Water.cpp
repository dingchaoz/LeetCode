#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &);

int main()
{
    const int sizeH = 10;
    int a_height[sizeH] = {1, 2, 1, 3, 5, 7, 6, 4, 1, 2};

    vector<int> height(a_height, a_height+sizeH);

    cout << maxArea(height);

    return 0;
}

int maxArea(vector<int> &height)
{
    vector<int> lBounds;        // Left boundaries. Ex: {1, 3, 5, ... }
    vector<int> idxLBounds;     // Index of the left boundaries. Ex: {0, 1, 3, ...}

    vector<int> rBounds;        // Right boundaries. Ex: {..., 6, 4, 2}
    vector<int> idxRBounds;     // Index of the right boundaries. Ex: {..., 6, 7, 9}

    int maxLBound = 0, maxRBound = 0;   // Record the max value of the left and right boundaries

    int j = height.size()-1;
    int idxMaxLBound = 0, idxMaxRBound = j;
    for (int i = 0; i < height.size(); i++, j--) {
        if (idxMaxRBound < idxMaxLBound)    // When the indexes of the maxRBound and maxLBound have passed each other, all cases have been covered
            break;
        if (maxLBound < height[i]) {    // Update info of the left boundaries
            maxLBound = height[i];
            idxMaxLBound = i;
            lBounds.push_back(height[i]);
            idxLBounds.push_back(i);
        }
        if (maxRBound < height[j]) {    // Update info of the right boundaries
            maxRBound = height[j];
            idxMaxRBound = j;
            rBounds.push_back(height[j]);
            idxRBounds.push_back(j);
        }
    }

    int mA = 0;
    int h = 0, k = 0;
    while ((h < lBounds.size())&&(k < rBounds.size())) {
        if (idxLBounds[h] >= idxRBounds[k])     // When the indexes of the rBound and lBound have passed each other, all cases have been covered
            break;
        else if (lBounds[h] < rBounds[k]) {     // Calculate the max area bounded by lBounds[h] and rBounds[k] if lBounds[h] < rBounds[k]
            mA = max(mA, lBounds[h]*(idxRBounds[k]-idxLBounds[h]));
            h++;
        }
        else {                                  // Calculate the max area bounded by lBounds[h] and rBounds[k] if lBounds[h] >= rBounds[k]
            mA = max(mA, rBounds[k]*(idxRBounds[k]-idxLBounds[h]));
            k++;
        }
    }
    return mA;
}
