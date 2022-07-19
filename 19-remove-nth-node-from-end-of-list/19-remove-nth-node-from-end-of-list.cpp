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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head->next==NULL)
        {
            return NULL;
        }
        ListNode* curr=head, *prev=NULL;
        int length=0, cnt=0;
        while(curr!=NULL)
        {
            curr=curr->next;
            length++;
        }
        n=length-n;
        curr=head;
        while(curr!=NULL && cnt<n)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        cout << curr->val;
        if(curr->next==NULL)
        {
            prev->next=NULL;
        }
        else
            if(curr==head)
            {
                head=head->next;
            }
        else
        {
            prev->next=curr->next;
            curr->next=NULL;
        }
        return head;
    }
};