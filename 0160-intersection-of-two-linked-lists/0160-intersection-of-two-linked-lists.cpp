/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)return NULL;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){
            temp1=temp1==NULL?headA:temp1->next;
            temp2=temp2==NULL?headB:temp2->next;

        }
        return temp1;
    }
};