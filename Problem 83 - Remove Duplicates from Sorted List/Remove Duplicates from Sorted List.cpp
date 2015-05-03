#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *);

int main()
{
    int N;

    cin >> N;

    ListNode *head = new ListNode(0);
    ListNode *currNode = head;
    for (int i = 1; i < N; i++) {
        ListNode* newNode = new ListNode(i/4);
        currNode->next = newNode;
        currNode = newNode;
    }

    // List of head: 0->0->0 for N = 3

    currNode = deleteDuplicates(head);

    while (currNode != NULL) {
        cout << currNode->val << " ";
        currNode = currNode->next;
    }

    return 0;
}

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
        return NULL;

    ListNode* currNode = head, *nextNode;
    int dupVal = currNode->val;                // Record of the duplication value

    while (currNode->next) {
        // If the next element is the same as the current one
        if (dupVal == (currNode->next)->val) { // If the next element is the same as the current one
            nextNode = (currNode->next)->next;  // Delete the next node. nextNode is needed as an intermediate step
            delete currNode->next;
            currNode->next = nextNode;          // Connect currNode->next to (currNode->next)->next
        }                                       // Note we only re-connect the next node but do not go to the next node
        // If the next element is different than the current one
        else {
            currNode = currNode->next;          // Go to next node
            dupVal = currNode->val;            // Update dupVal for next evaluation of duplication
        }
    }
    return head;
}
