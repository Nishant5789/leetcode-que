/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast=head, *slow=head;
        int flag=1;
        if(fast->next==NULL || fast==NULL)
        {
            ListNode *temp=NULL;
            return temp;
        }
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
                if(flag!=1)
                {
                    slow=slow->next;
                }
                else
                    flag++;
            }
        }
        slow->next=slow->next->next;
        return head;
    }
};