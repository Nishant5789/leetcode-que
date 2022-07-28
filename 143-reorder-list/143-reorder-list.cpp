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
        // first find the middle node of list and divide into two part 
        // after we reverse the second the part 
        // after than we insert the reverse list node one by one in first list; 
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
        // reverse the second list
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
        // for odd size of list
        if(cnt%2==1)
        {
            temp->next=slow;
        }
        return;
    }
};