/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    pair<int, bool> checkbalance(TreeNode* root)
    {
        if(root==NULL)
        {
            pair<int, bool> p=make_pair(0,true);
            return p;
        }
        
        pair<int, bool> left = checkbalance(root->left);
        pair<int, bool> right = checkbalance(root->right);
        
        if(abs(left.first - right.first)<=1 && left.second && right.second)
        {
            pair<int, bool> p = make_pair(max(left.first,right.first)+1,true);
            return p;
        }
        else
        {
            pair<int, bool> p=make_pair(max(left.first,right.first)+1,false);
            return p;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        
        return checkbalance(root).second;
    }
};