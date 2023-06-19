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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==1&&n==1)return NULL;
        if(count==n)return head->next;
        temp=head;
        for(int i=1;i<count-n;i++)
        temp=temp->next;
        ListNode* temp1=temp->next->next;
        temp->next=temp1;
        cout<<temp->val;
        return head;
    }
};