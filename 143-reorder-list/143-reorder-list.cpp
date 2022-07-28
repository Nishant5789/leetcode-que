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
            return head;
        
        ListNode* temp=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
public:
    void reorderList(ListNode* head)
    {
          if(head==NULL || head->next==NULL)
            return ;
        ListNode* fast=head, *slow=head, *pre=NULL;
        int cnt=0;
        while(fast)
        {
            fast=fast->next;
            cnt++;
            if(fast)
            {
                fast=fast->next;
                pre=slow;
                slow=slow->next;
                cnt++;
            }
        }
        pre->next=NULL;
        slow = reverse(slow);
        ListNode* curr2=slow, *temp=NULL;
        fast=head;
        while(fast)
        {
            temp=slow;
            slow=slow->next;
            temp->next=fast->next;
            fast->next=temp;
            fast=temp->next;
        }
        if(cnt%2==1)
        {
            temp->next=slow;
        }
        return;
    }
};