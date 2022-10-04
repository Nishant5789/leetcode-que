struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};

class Solution {

    public:
    bool isvalid(int i, int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m ;
    }

    void dfs(queue<pair<int,int>> &q,unordered_map<pair<int,int>, bool, HASH> &visited,int n,int m,vector<int> &ans,vector<vector<int>> mat)
    {   
        while(!q.empty())
        {
            auto index=q.front();
            q.pop();
            int i=index.first, j=index.second;
            ans.push_back(mat[i][j]);
            vector<pair<int,int>> movements{{0,1}, {1,0}, {0,-1}, {-1,0}};

            for(auto movment: movements)
            {
                int move_x=i+movment.first, move_y=j+movment.second;
                if(movment.first==0 && movment.second==1)
                {
                    if( isvalid(i-1, j, n, m) && !visited[{i-1, j}] && (isvalid(i, j+1, n, m) && !visited[{i, j+1}]))
                    {
                        q.push({i-1, j});
                        visited[{i-1,j}]=true;
                        dfs(q, visited, n, m, ans, mat);
                    }
                }
                if(isvalid(move_x, move_y, n, m) && !visited[{move_x, move_y}])
                {
                    q.push({move_x, move_y});
                    visited[{move_x,move_y}]=true;
                    dfs(q, visited, n, m, ans, mat);
                }
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        vector<int> ans;
        int r = mat.size(), c = mat[0].size();
        queue<pair<int,int>> q;
        unordered_map<pair<int,int>, bool, HASH> visited;
        q.push({0,0});
        visited[{0,0}]=true;
        dfs(q, visited, r, c, ans, mat);
        return ans;
    }
};