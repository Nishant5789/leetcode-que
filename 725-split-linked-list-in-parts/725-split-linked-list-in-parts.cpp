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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int len=0; 
        ListNode* temp=head;
        
    //finding length of linked list
        while(temp){
            len++;
            temp=temp->next;
        }
        
    // parts->number of nodes every splitted part should have 
    // extc-> number of initial splitted part should have
        int parts=len/k;
        int extc=len%k;
        
        temp=head;     
        vector<ListNode*> v;
        
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<parts -1 + (i<extc?1:0);j++){ 
                if(temp){
                    temp=temp->next;
                }
            }
     //push splitted list head into answer vector       
            v.push_back(head);
            if(temp){
                head=temp->next;
                temp->next=NULL;
                temp=head;
            }   
        }
        return v;

    }
};