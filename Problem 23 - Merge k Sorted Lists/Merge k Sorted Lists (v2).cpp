#include <iostream>
#include <algorithm>    // heap tree
#include <assert.h>     // assert
#include <vector>


using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &);
static bool isNull(const ListNode*);
static bool minHeapCmp(const ListNode*, const ListNode*);

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
    auto it_begin = begin(lists);   // auto linked to vector<ListNode *>::iterator
    auto it_end = end(lists);

    it_end = remove_if(it_begin, it_end, isNull);   // Removes empty lists

    if (it_begin == it_end)  // All lists are empty
        return nullptr;

    make_heap(it_begin, it_end, minHeapCmp);    // Builds the minHeap with elements coming from the first node of all lists

    ListNode *head = *it_begin, *tail = *it_begin;  // 1st element in the heap is the head of the merged list

    while (distance(it_begin, it_end) > 1) {
        pop_heap(it_begin, it_end, minHeapCmp); // Moves the 1st list from the head to the back of the minHeap

        *(it_end-1) = (*(it_end-1))->next;  // Remove the 1st node of that last list by going to its next node

        if (*(it_end-1))    // If the list is not empty, inserts the current node back into the minHeap and maintain the heap property
            push_heap(it_begin, it_end, minHeapCmp);
        else    // If the heap is empty, remove it from the minHeap
            it_end--;

        tail->next = *it_begin; // Since the heap property is maintained, the min node comes from the head of the minHeap
        tail = tail->next;
    }
    return head;
}

static bool isNull(const ListNode* a) {
    return (a == nullptr);
}

static bool minHeapCmp(const ListNode* a, const ListNode* b) {  // Here assert is used to abort the program execution if a or b is called with a null pointer as attribute
    assert(a); assert(b);
    return (a->val > b->val);
}
