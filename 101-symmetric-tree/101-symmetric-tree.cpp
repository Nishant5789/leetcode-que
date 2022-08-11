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
    bool check(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        
        if(root1==NULL && root2!=NULL || root1!=NULL && root2==NULL)
            return false;
        
        bool check1 = check(root1->left, root2->right);
        bool check2 = check(root1->right, root2->left);
        bool check3 = (root1->val==root2->val) ? 1 : 0;
        
        if(check2 && check1 && check3)
        {
            return true;
        }
        else
            return false;
    }
public:
    bool isSymmetric(TreeNode* root)
    {  
        if(root->left==NULL && root->right==NULL)
            return true;
        
       if(root->left==NULL && root->right!=NULL || root->left!=NULL && root->right==NULL)
            return false;
        
        if(root->left->val!=root->right->val)
            return false;
        
        return check(root->left, root->right);
    }
};