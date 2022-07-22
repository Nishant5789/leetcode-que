/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    int getlength(ListNode * curr)
    {
        int count=0;
        while(curr)
        {
            curr=curr->next;
            count++;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *curr1=headA, *curr2=headB;
        int l1=getlength(curr1), l2=getlength(curr2);
        int diff=abs(l1-l2);
        
        // cout << l1 << " " << l2;
        if(l1<l2)
        {
            curr1=headB;
            curr2=headA;
        }
        else
            if(l1>l2)
        {
            curr1=headA;
            curr2=headB;

        }
        int cnt=0;
        while(curr1 && cnt<diff)
        {
            curr1=curr1->next;
            cnt++;
        }
        while(curr1!=curr2)
        {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return curr1;
    }
};