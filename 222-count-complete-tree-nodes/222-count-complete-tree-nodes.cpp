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
    int solve(TreeNode* root,int &count)
    {
        if(root==NULL)
            return 0;
        
        int leftcount = solve(root->left, count);
        int rightcount = solve(root->right, count);
        
        return leftcount+1+rightcount;
    }
public:
    int countNodes(TreeNode* root) {
        
        int count=0;
        return solve(root, count);
    }
};