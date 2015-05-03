#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode*, ListNode*);

int main()
{
    int N1 =5, N2 = 3;
    int v1 = 0, v2 = 1;
    ListNode *currNode;

    ListNode *l1 = new ListNode(v1);
    currNode = l1;
    for (int i = 1; i < N1; i++) {
        v1 = v1 +3;
        ListNode* newNode = new ListNode(v1);
        currNode->next = newNode;
        currNode = newNode;
    }

    ListNode *l2 = new ListNode(v2);
    currNode = l2;
    for (int i = 1; i < N2; i++) {
        v2 = v2 +2;
        ListNode* newNode = new ListNode(v2);
        currNode->next = newNode;
        currNode = newNode;
    }

    ListNode *lm = mergeTwoLists(l1, l2);
    currNode = lm;
    while (currNode != NULL) {
        cout << currNode->val << " ";
        currNode = currNode->next;
    }

    return 0;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1 && !l2)
        return NULL;

    ListNode *lm = new ListNode(0);
    ListNode *lastNode = lm;
    ListNode *n1 = l1, *n2 = l2;    // n1, n2 are the remaining list of l1, l2 after some elements have been processed to the merged list

    while (1) {
        if (!n1) {                  // If the end of l1 is reached: append n2 to the merged list
            lastNode->next = n2;
            return lm->next;
        }
        if (!n2) {                  // If the end of l2 is reached: append n1 to the merged list
            lastNode->next = n1;
            return lm->next;
        }

        ListNode* newNode = new ListNode(0);    // If both n1, n2 have not reached the end, create a new node to merged list
        // Assign the right value
        if (n1->val < n2->val) {
            newNode->val = n1->val;
            n1 = n1->next;
        }
        else {
            newNode->val = n2->val;
            n2 = n2->next;
        }

        lastNode->next = newNode;
        lastNode = newNode;
    }
}
