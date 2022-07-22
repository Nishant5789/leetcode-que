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
    vector<int> nextLargerNodes(ListNode* head) {
        
        ListNode* curr=head;
	    stack <int> s;
	    vector<int> arr;
	    int cnt=0;
	    while(curr!=NULL)
	    {
	        arr.push_back(curr->val);
	        curr=curr->next;
	        cnt++;
	    }
	    vector<int> nextsmaller(cnt);
        // cout << arr[0] << arr[2];
		for(int i=0; i<cnt; i++)
		{
		    while(s.size()!=0 && arr[s.top()]<arr[i])
		    {
		        nextsmaller[s.top()]=i;
		        s.pop();
		    }
		    s.push(i);
		}
		while(s.size()!=0)
		{
		        nextsmaller[s.top()]=-1;
		        s.pop();
		}
		for(int i=0; i<cnt; i++)
		{
		    if(nextsmaller[i]==-1)
		        nextsmaller[i]=0;
		    else
		        nextsmaller[i]=arr[nextsmaller[i]];
		}
        return nextsmaller;
	}
};