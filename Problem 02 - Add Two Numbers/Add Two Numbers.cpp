#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *, ListNode *);

int main()
{
    ListNode *l1 = new ListNode(0);
    ListNode *l1Node = l1;

    ListNode *l2 = new ListNode(0);
    ListNode *l2Node = l2;

    const int nl1 = 1;
    int a_l1[nl1] = {0};

    const int nl2 = 1;
    int a_l2[nl2] = {0};

    for (int i = 0; i < nl1; i++) {
        ListNode *newNode = new ListNode(a_l1[i]);
        l1Node->next = newNode;
        l1Node = newNode;
    }
    l1 = l1->next;

    for (int i = 0; i < nl2; i++) {
        ListNode *newNode = new ListNode(a_l2[i]);
        l2Node->next = newNode;
        l2Node = newNode;
    }
    l2 = l2->next;

    ListNode* currNode;
    currNode = addTwoNumbers(l1, l2);
    while (currNode != NULL) {
        cout << currNode->val << " ";
        currNode = currNode->next;
    }

    return 0;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode* aTN = new ListNode(0);
    ListNode* aTNnode = aTN, *l1Node = l1, *l2Node = l2;
    int l1Val, l2Val, sum, carry = 0;       // l1Val, l2Val are the proper values for performing addition at every digits
    bool l1Done = false, l2Done = false;    // Whether l1 and l2 have been navigated through

    if (!l1 && !l2)
        return NULL;

    while (1) {
        if (l1Node) {
            l1Val = l1Node->val;
            l1Node = l1Node->next;
        }
        else {
            l1Done = true;
            l1Val = 0;
        }

        if (l2Node) {
            l2Val = l2Node->val;
            l2Node = l2Node->next;
        }
        else {
            l2Done = true;
            l2Val = 0;
        }

        if ((sum = l1Val + l2Val + carry) > 9) {    // When sum > 9: carry = 1
            ListNode* newNode = new ListNode(sum-10);
            aTNnode->next = newNode;
            aTNnode = newNode;
            carry = 1;
        }
        else if (!l1Done || !l2Done || sum > 0) {   // Cannot simply put sum > 0: if the sum at the digit happen to be 0, then we will go to the else case
            ListNode* newNode = new ListNode(sum);
            aTNnode->next = newNode;
            aTNnode = newNode;
            carry = 0;
        }
        else
            return aTN->next;
    }
}
