class Solution {
    int bfs(int node,unordered_map<int, list<int>> &adj,vector<int> &ans, vector<int>& informTime)
    {   
        queue<int> q;
        q.push(node);
        int maxi=0;
        // cout << node << endl;
        while(!q.empty())
        {
            node=q.front();
            q.pop();
            for(auto i: adj[node])
            {
                ans[i]=ans[node]+informTime[node];
                maxi=max(maxi,ans[i]);
                q.push(i);
            }
        }
        return maxi;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        int l=manager.size();
        unordered_map<int, list<int>> adj;
        for(int i=0; i<l; i++)
        {
            if(manager[i]!=-1)
            adj[manager[i]].push_front(i);
        }
        vector<int> ans(n,0);
        return bfs(headID, adj, ans, informTime);
    }
};