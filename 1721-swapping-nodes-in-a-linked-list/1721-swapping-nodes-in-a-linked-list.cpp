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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* curr2=head, *curr1=head;
        int cnt=1;
        while(cnt<k+1)
        {
            curr2=curr2->next;
            cnt++;
        }
        while(curr2)
        {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        cnt=1;
        curr2=head;
        while(cnt<k)
        {
            curr2=curr2->next;
            cnt++;
        }
        swap(curr2->val, curr1->val);
        return head;
    }
};