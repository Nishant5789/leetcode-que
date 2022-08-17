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
    void solve(TreeNode* root,int &result, vector<int> &path)
    {
        if(root==NULL)
        {
            return; 
        }
        path.push_back(root->val);
        
        solve(root->left, result, path);
        solve(root->right, result, path);    
       
        if(root->left == NULL && root->right == NULL)
        {
            int sum=0;
            for(int i=0; i<path.size(); i++)
            {
                // cout << path[i] << " ";
                sum=sum*10+path[i];
            }
            // cout << sum;
            result+=sum;
        }
        
        path.pop_back();
        return;
    }
    
    int sumNumbers( TreeNode* root) 
    {
        vector<int> path;
        int count = 0;
        solve(root, count, path);
        return count;
    }

};