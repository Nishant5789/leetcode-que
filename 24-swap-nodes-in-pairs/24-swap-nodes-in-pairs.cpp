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
    ListNode* swappair(ListNode* head)
    {
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        
        ListNode* curr=head, *pre=NULL, *next=NULL; 
        int cnt=0;
        while(cnt<2)
        {
            next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
            cnt++;
        }
        
        if(next!=NULL)
        {
            head->next=swappair(next);
        }
        return pre;
    }
public:
    ListNode* swapPairs(ListNode* head)
    {
        return swappair(head);
    }
};