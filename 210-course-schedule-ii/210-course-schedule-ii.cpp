class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for(int i=0; i<prerequisites.size(); i++)
        {
            int u=prerequisites[i][0], v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int> indegree(n);
        for(auto i: adj)
        {
            for(auto j: i.second)
            {
                indegree[j]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto child: adj[front])
            {
                indegree[child]--;
                if(indegree[child]==0)
                    q.push(child);
            }
        }
        reverse(ans.begin(), ans.end());
        if(ans.size()==n)
            return ans;
        
        return vector<int>();
    }
};