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
    int height(TreeNode* node)
    {
        if(node == NULL)
            return 0;
        
        int left=height(node->left);
        int right=height(node->right);
        
        int ans= max(right, left)+1;
        return ans;
    }
    int diameter(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        int op1= diameter(root->left);
        int op2= diameter(root->right);
        int op3= height(root->right)+1+height(root->left);

        int ans=max(op1, max(op2, op3));
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        return diameter(root)-1;
    }
};