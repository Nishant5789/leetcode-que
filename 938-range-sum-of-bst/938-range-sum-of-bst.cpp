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
   void  range(int &ans,TreeNode* root, int low,int high)
    {
        if(root==NULL)
            return ;
        if(low<=root->val && root->val<=high)
        {
            ans+=root->val;
           
        }
        range(ans, root->right, low, high);
        range(ans, root->left, low, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        range(ans, root, low, high);
        return ans;
    }
};