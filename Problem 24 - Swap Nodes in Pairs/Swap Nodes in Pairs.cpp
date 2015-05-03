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

ListNode* swapPairs(ListNode*);

int main()
{
    int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int nIntArray = sizeof(intArray)/sizeof(int);

    ListNode *head = new ListNode(0);
    ListNode *tail  = head;

    for (int i = 0; i < nIntArray; i++) {
        ListNode *newNode = new ListNode(intArray[i]);
        tail->next = newNode;
        tail = newNode;
    }
    head = head->next;

    ListNode *spHead = swapPairs(head);

    while (spHead != NULL) {
        cout << spHead->val << " ";
        spHead = spHead->next;
    }

    return 0;
}

ListNode* swapPairs(ListNode* head)
{
    ListNode *spHead = new ListNode(0);
    ListNode *spTail = spHead;
    ListNode *n1, *n2;

    if (!head)  // The list is NULL
        return nullptr;
    if (!(head->next))  // Only one node in the list
        return head;

    // At least 2 nodes
    n1 = head;      // Assign node 1
    n2 = n1->next;  // Assign node 2
    while (1) {
        n1->next = n2->next;    // Connect node 1 -> node 3
        n2->next = n1;          // Connect node 2 -> node 1
        spTail->next = n2;      // Connect the old tail node to node 2, the head of the new pair
        spTail = n1;            // Update the new tail to be node 1

        if(!(n1 = n1->next))    // If number of node in the list is even, i.e., the list is are exactly divided into pairs
            break;
        if(!(n2 = n1->next)) {  // If number of node in the list is even, i.e., the list is are divided into pairs with one node left
            spTail->next = n1;
            break;
        }
    }
    return spHead->next;
}
