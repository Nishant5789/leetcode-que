class Solution {
    void dfs(int node,unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    
        cout << node << " ";
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int>> adj;
        if(connections.size()<n-1)
            return -1;
        for(int i=0; i<connections.size(); i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            
            adj[u].push_front(v);
            adj[v].push_front(u);
        }
        int count=0;
        queue<int> q;
        unordered_map<int,bool> visited;
   
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i, visited, adj);
            }
        }
        return count-1;
    }
};