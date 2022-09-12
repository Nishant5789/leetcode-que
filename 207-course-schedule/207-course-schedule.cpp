class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {   
        
        unordered_map<int, list<int>> adj;
        for(int i=0; i<prerequisites.size(); i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<int> indgree(n);
        for(auto i:adj)
        {
            for(auto j: i.second)
            {
                indgree[j]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indgree[i] == 0)
                q.push(i);
        }
        int ans=0;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            // ans store
            ans++;
            // neighbour indegree update
            for(auto neighbour: adj[front])
            {
                indgree[neighbour]--;
                if(indgree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        if(n==ans)
            return true;
        return false;
    }
};