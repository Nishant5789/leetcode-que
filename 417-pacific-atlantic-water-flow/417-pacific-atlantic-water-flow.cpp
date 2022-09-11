class Solution {
        vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    bool valid(int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    void DFS(vector<vector<int>>& heights, int i, int j, int prev,vector<vector<bool>>& anyOcean){
        if(heights[i][j] < prev || anyOcean[i][j]) return;
        anyOcean[i][j] = true;
        for(int k = 0; k < 4; k++){
            int row = dx[k] + i;
            int col = dy[k] + j;
            if(valid(row, col, heights.size(), heights[0].size()) && !anyOcean[row][col])
                DFS(heights, row, col, heights[i][j], anyOcean);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> atlantic(n, vector<bool>(m)), pacific(n, vector<bool>(m));
        
        // check for columns
        for(int i = 0; i < m; i++){
            DFS(heights, 0, i, INT_MIN, pacific);
            DFS(heights, n-1, i, INT_MIN, atlantic);
        }
        
        // check for rows
        for(int i = 0; i < n; i++){
            DFS(heights, i, 0, INT_MIN, pacific);
            DFS(heights, i, m-1, INT_MIN, atlantic);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(atlantic[i][j] && pacific[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};