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
ListNode *oddEvenList(ListNode *head)
{
    //We will create 2 linked lists even and odd for storing
    //respective types of nodes indices

    if (!head || !head->next || !head->next->next)
        return head;
    
    //If no node , single node or only two nodes are present
    ListNode *oddStart = head;
    //Linked list containing nodes at odd indices
    ListNode *evenStart = head->next;
    //Linked List containing nodes at even indices
    ListNode *evenPointer = head->next;
    //Dummy node for storing starting point of even linked list
    //will help in connecting odd and even linked list
    
    while (oddStart->next && evenStart->next)
    {
        oddStart->next = evenStart->next;
        //connecting odd nodes
        evenStart->next = oddStart->next->next;
        //connecting even nodes
        oddStart = oddStart->next;
        //traversing in odd liinked list
        evenStart = evenStart->next;
        //traversing in even linked list
    }
    oddStart->next = evenPointer;
    //connecting odd and even linked list
    return head;
}
};