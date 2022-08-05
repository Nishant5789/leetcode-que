class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        vector<int> num;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                num.push_back(matrix[i][j]);
            }
        }
        sort(num.begin(), num.end());
        return num[k-1];
    }
};