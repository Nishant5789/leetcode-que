class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int colum=matrix[0].size();
        
        map<int,vector<int>> num;
        
        for(int i=0; i<row; i++)
        {
            vector<int> temp;
            for(int j=0; j<colum; j++)
            {
                temp.push_back(matrix[i][j]);
            }
            num[row-i-1]=temp;
        }
        int i=0,j=0;
        for(auto &m: num)
        {
            for(auto &n: m.second)
            {
                matrix[j][i]=n;
                j++;
            }
            i++;
            j=0;
        }
    }
};