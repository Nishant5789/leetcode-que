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
    ListNode* reverse(ListNode* head, ListNode* last)
    {
        if(head==last || head->next==last)
        {
            return head;
        }
        ListNode* temp = reverse(head->next, last);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* curr1=head, *curr2=head, *prev=NULL;
        int flag=1, cnt=1;
        while(curr1!=NULL )
        {
            
            if(cnt!=l)
            {
                prev=curr1;
                curr1=curr1->next;
            } 
            else
                break; 
             cnt++;
        }
        flag=1;cnt=1;
        while(curr2!=NULL)
        {
            if(cnt!=r)
                curr2=curr2->next;
            else
                break;
            cnt++;
        }
         // cout << curr1->val << " " << curr2->val ;
        if(curr1 == NULL && curr2 == NULL)
        {
            return reverse(head, NULL);
        }
        ListNode* chotuhead=curr2->next;
        ListNode* temphead = reverse(curr1, curr2->next);
        
        if(curr1!=head)
        {
             prev->next=temphead;
             curr1->next=chotuhead;
             return head;
        }
        else
        {
             head->next=chotuhead;
             return temphead;
        }
    }
};