/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int len(ListNode* head)
 {
    int l = 0;
    while(head->next != NULL)
    {
        ++l;
        head = head->next;
    }
    return l;
 }
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
        return NULL;
    int lenDiff = len(headA) - len(headB);
    ListNode *la = headA;
    ListNode *lb = headB;
    if(lenDiff > 0) {
        while(lenDiff != 0) {
            la = la->next;
            lenDiff--;
        }
    }
    else if(lenDiff < 0) {
        while(lenDiff != 0) {
            lb = lb->next;
            lenDiff++;
        }
    }
    while(la && lb) {
        if(la == lb)
            return la;
        la = la->next;
        lb = lb->next;
    }
    return NULL;
    }
};