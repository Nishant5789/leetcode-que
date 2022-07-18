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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=slow->next;
        
        while(fast!=NULL && slow->next!=NULL)
        {
            if(slow->val==fast->val)
            {   
                if(fast->next!=NULL)
                {         
                    slow->next=fast->next;
                    fast=slow->next;
                }
                else
                {
                    slow->next=NULL;
                }
            }
                else
                {
                    fast=fast->next;
                    slow=slow->next;
                }
        }
         return head;
    }
};