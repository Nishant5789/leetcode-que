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
    ListNode* reverse(ListNode* &head)
 {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    ListNode* temp=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}
    
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return 1;
        ListNode *fast= head;
        ListNode *slow= head, *pre=NULL;
        int cnt=0;
        while(fast != NULL)
        {
            fast=fast->next;
            if(fast != NULL)
            {
                fast=fast->next; 
                pre=slow;
                slow=slow->next;
                cnt+=2;
            }
            else
                cnt++;
        }
        ListNode* curr=slow,prev=NULL;
        if(cnt&1)
        {
            curr=slow->next;
            pre->next=reverse(slow->next);
        }
        else
        {
            pre->next=reverse(slow);
        }
        pre=pre->next;
        
        while(pre!=NULL)
        {
            if(pre->val!=head->val)
                return 0;
            pre=pre->next;
            head=head->next;
        }
        return 1;
    }
};