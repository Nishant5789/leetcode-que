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
    
    bool solve(TreeNode* root, int target, vector<int> &path)
    {
        if(root==NULL)
        {
            return false; 
        }
        
        path.push_back(root->val);
        
        bool leftpath = solve(root->left, target, path);
        bool rightpath = solve(root->right, target, path);    
       
        if(root->left == NULL && root->right == NULL)
        {
            int sum=0;
            for(int i=0; i<path.size(); i++)
                sum+=path[i];
            cout << sum << " ";
            if(sum==target)
            {
                cout << sum ;
                return true;
            }
        }
        
        if(leftpath==true || rightpath==true)
            return true;
        
         path.pop_back();
        
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        vector<int> path;
        return solve(root, targetSum, path);
    }
};