#include <iostream>
#include <algorithm>    // heap tree
#include <utility>      // std::pair
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &);
static inline bool compMin(const pair<int, int>&, const pair<int, int>&);   // Declare inline for efficiency

int main()
{
    const int k = 3;
    int sizeL[k] = {5, 3, 4};

    const int maxSizeL = 5;
    int arrayL[k][maxSizeL] = {{1, 2, 4, 7, 11},
                               {3, 4, 5},
                               {1, 3, 5, 6}};

    vector<ListNode *> lists;
    for (int i = 0; i < k; i++) {
        ListNode *head = new ListNode(0);
        ListNode *currNode = head;
        for (int j = 0; j < sizeL[i]; j++) {
            ListNode* newNode = new ListNode(arrayL[i][j]);
            currNode->next = newNode;
            currNode = newNode;
        }
        lists.push_back(head->next);
    }
    lists.push_back(NULL);
    lists.push_back(NULL);

    ListNode *mKL = mergeKLists(lists);

    while (mKL != NULL) {
        cout << mKL->val << " ";
        mKL = mKL->next;
    }

    return 0;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *mKL = new ListNode(0);
    ListNode *nextNode = mKL;

    vector<pair<int, int>> nToCmp;

    int i = 0;
    while (i < lists.size()) {
        if (lists[i]) {
            nToCmp.push_back(make_pair(lists[i]->val, i));
            i++;
        }
        else
            lists.erase(lists.begin()+i);
    }

    if (!nToCmp.empty())  // Initialize the heap tree with elements coming from the first node of all lists
      make_heap(nToCmp.begin(), nToCmp.end(), compMin);

    int nListsMerged = 0;
    int nLists = lists.size();
    int minVal, minInx;

    while (nListsMerged < nLists) {
      minVal = (nToCmp.front()).first;
      minInx = (nToCmp.front()).second;

      pop_heap(nToCmp.begin(), nToCmp.end(), compMin);
      nToCmp.pop_back();

      ListNode *newNode = new ListNode(minVal);
      nextNode->next = newNode;
      nextNode = newNode;

      if (lists[minInx] = lists[minInx]->next) {
        nToCmp.push_back(make_pair(lists[minInx]->val, minInx));
        push_heap(nToCmp.begin(), nToCmp.end(), compMin);
      }
      else
        nListsMerged++;
    }

    sort_heap(nToCmp.begin(), nToCmp.end());

    for (int i = 0; i < nToCmp.size(); i++) {
      ListNode *newNode = new ListNode(nToCmp[i].first);
      nextNode->next = newNode;
      nextNode = newNode;
    }

    return mKL->next;
}

static inline bool compMin(const pair<int, int>& lh, const pair<int, int>& rh) // LeetCode require the function handle to be static
{
    return lh.first > rh.first;
}
