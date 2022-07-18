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
    void reverse(ListNode* &head, ListNode* &prev, ListNode* &curr)
{
    if(curr==NULL)
    {
        head=prev;
        return ;
    }
    reverse(head, curr, curr->next);
    curr->next=prev;
}
    
 void Reverse(ListNode* &l1,ListNode* &l2)
 {
        ListNode* prev=NULL, *curr=l1;
        reverse(l1, prev, curr);
        prev=NULL;
        curr=l2;
        reverse(l2, prev, curr);
 }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        Reverse(l1,l2);
        int remainder=0;
        while(l1!=NULL && l2!=NULL)
        {
            int sum=l1->val+l2->val+remainder;
            int digit=sum%10;
            temp->next = new ListNode(digit);
            remainder=sum/10;
            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }
            while(l1!=NULL)
        {
            int sum=l1->val+remainder;
            int digit=sum%10;
            temp->next = new ListNode(digit);
            remainder=sum/10;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2!=NULL)
        {
            int sum=l2->val+remainder;
            int digit=sum%10;
            temp->next = new ListNode(digit);
            remainder=sum/10;
            l2=l2->next;
            temp=temp->next;
        }
        
        while(remainder!=0)
        {
            int sum=remainder;
            int digit=sum%10;
            temp->next = new ListNode(digit);
            remainder=sum/10;
            temp=temp->next;       
        }
        ListNode* curr=ans->next,*head=ans->next, *prev=NULL;
        reverse(head, prev, curr);
        return head;
    }
};