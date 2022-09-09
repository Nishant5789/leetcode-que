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
   void  find_leaf(TreeNode* root, vector<int> &ans)
    {
        if(root==NULL)
           return ;
       
        find_leaf(root->left, ans);
        find_leaf(root->right, ans);
       
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->val);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaf1, leaf2;
        find_leaf(root1, leaf1);
        find_leaf(root2, leaf2);

        if(leaf1==leaf2)
            return true;
        
        return false;
    }
};