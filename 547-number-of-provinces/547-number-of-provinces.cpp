class Solution {
    
void dfs(int node,unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    
    //for all conected node called recursive call
    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            dfs(i, visited, adj);
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isconnect) {
        unordered_map<int, list<int>> adj;
        int n=isconnect.size(), m=isconnect[0].size();
        for(int i=1; i<=n; i++)
        {
            adj[i].push_front(i);
            for(int j=1; j<=m; j++)
            {
                if(isconnect[i-1][j-1])
                adj[i].push_front(j);
            }
        }
        int count=0;
        queue<int> q;
        unordered_map<int,bool> visited;
   
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs(i, visited, adj);
                count++;
            }
        }
        return count;
    }
};