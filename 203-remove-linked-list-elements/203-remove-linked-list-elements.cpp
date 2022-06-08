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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return head;
        ListNode *fast=head->next, *slow=head;
        while(fast!=NULL)
        {
            if(fast->val==val)
            {
                if(fast->next!=NULL)
                {
                    slow->next=fast->next;
                    fast=fast->next;
                }
                else
                {
                    slow->next=NULL;
                    fast=NULL;
                }
            }
            else
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        if(head->val==val)
            return head->next;
        return head;
    }
};