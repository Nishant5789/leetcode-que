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
    ListNode* mergeNodes(ListNode* head)
    {
       ListNode *curr=head,*curr1=head, *first=NULL;
       int res=-1;
        while(curr1)
        {
            // when the first node.value appering zero then save it's address after sum of all 
            // non zero number and when another zero have node is come hen do neccessary process
            if(curr1->val==0 && res==-1)
            {
                res=0;
                first=curr1->next;
            }
            else
             if(curr1->val!=0)
            {
                res+=curr1->val;
            }
            else
                if(curr1->val==0 && res!=-1)
            {
                first->val=res;
                curr->next=first;
                curr=first;
                res=0;
                if(curr1->next==NULL)
                    first->next=NULL;
                first=curr1->next;
            }
            curr1=curr1->next;
        }
        return head->next;
    }
};