/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*  temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if (count == 0)
         return NULL;
        if (k >= count)
         k = k % count;

        if(k==0)return head;
        ListNode* headprev=head;
        for(int i=1;i<=count-k-1;i++)
        headprev=headprev->next;
        ListNode* Head=headprev->next;
        ListNode* end=head;
        while(end->next!=NULL)
        end=end->next;
        headprev->next=NULL;
        end->next=head;
       
       
        return Head; 
    }
};