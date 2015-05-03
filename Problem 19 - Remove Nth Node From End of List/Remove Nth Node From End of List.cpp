#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode*, int);

int main()
{
    int N, n;   // N: Number of nodes in the linkList; n: n-th node from the tail will be removed

    cin >> N >> n;

    ListNode *head = new ListNode(0);
    ListNode *currNode = head;
    for (int i = 1; i < N; i++) {
        ListNode* newNode = new ListNode(i);
        currNode->next = newNode;
        currNode = newNode;
    }

    currNode = removeNthFromEnd(head, n);

    while (currNode != NULL) {
        cout << currNode->val << " ";
        currNode = currNode->next;
    }
    return 0;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *currNode = head, *breakNode = head;
    int i = 0;

    if (head != NULL) {
        while (currNode != NULL) {
            currNode = currNode->next;
            if (i++ > n)
                breakNode = breakNode->next;
        }
        if (i == n) // Special case that the head node is removed
            head = head->next;
        else
            breakNode->next = (breakNode->next)->next;
    }
    return head;
}
