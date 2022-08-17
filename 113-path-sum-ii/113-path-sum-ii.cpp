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
public:
    
    void solve(TreeNode* root, int target, vector<int> &path, vector<vector<int>> &result)
    {
        if(root==NULL)
        {
            return; 
        }
        path.push_back(root->val);
        
        solve(root->left, target, path, result);
        solve(root->right, target, path, result);    
       
        if(root->left == NULL && root->right == NULL)
        {
            int sum=0;
            for(int i=0; i<path.size(); i++)
                sum+=path[i];
            
            if(sum==target)
            {
                result.push_back(path);
                path.pop_back();
                return;
            }
        }
         path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        
        solve(root, targetSum, path, result);
        return result;
    }
};