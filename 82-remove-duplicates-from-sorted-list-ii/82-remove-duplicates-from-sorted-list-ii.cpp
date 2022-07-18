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
        ListNode* ans= new ListNode(0);
        ListNode* curr=ans;
        ListNode* fast=head->next;
        int flag=0, temp;
        while(fast!=NULL)
        {
            if(head->val!=fast->val)
            {
                curr->next=new ListNode(head->val);
                fast=fast->next;
                head=head->next;
                curr=curr->next;
            }
            else
            {
                temp=head->val;
                while(head->val==temp)
                {
                    if(head->next!=NULL)
                    {
                        head=head->next;
                    }
                    else
                    {
                        break;
                    }
                }
                fast=head->next;
            }
            // cout << temp << " " << head->val;
        }
        if(temp!=head->val)
            curr->next=new ListNode(head->val);
        return ans->next;
    }
};