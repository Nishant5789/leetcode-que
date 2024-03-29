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
    int dif = 10e5;
    int prev = -1;
    public:
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL ) return 0;
        
        getMinimumDifference(root->left);
        if(prev != -1){
            dif = min(dif, root->val - prev);

        }
        prev = root->val;
        getMinimumDifference(root->right );
        return dif;
    }

};
