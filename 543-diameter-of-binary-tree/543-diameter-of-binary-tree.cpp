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
    pair<int,int> diameter(TreeNode* root)
    {
        if(root==NULL)
        {
            pair<int, int> p=make_pair(0,0);
            return p;
        }

        pair<int,int> left=diameter(root->left);
        pair<int,int> right=diameter(root->right);
        
        pair<int,int> result=make_pair(max(left.first,max(left.second+right.second+1,right.first)), max(left.second,right.second)+1);

        return result;
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        return diameter(root).first-1;
    }
};