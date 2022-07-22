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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* curr1=head, *prev=NULL, *ans=new ListNode(0), *curr2=ans;
        int cnt=1;
        while(curr1!=NULL)
        {
            if(curr1->val<x)
            {
                curr2->next=new ListNode(curr1->val);
                curr2=curr2->next;
                if(prev!=NULL)
                {
                    if(curr1->next!=NULL)
                    {   
                        prev->next=curr1->next;
                        curr1=curr1->next;
                    }
                    else
                    {
                        prev->next=NULL; 
                        curr1=curr1->next;
                    }
                }
                else
                {
                    head=head->next;
                    curr1=head,prev=NULL;
                }
            }
            else
            {
                prev=curr1;
                curr1=curr1->next;
            }
        }
        curr2->next=head;
        return ans->next;
    }
};