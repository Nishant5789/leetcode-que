class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // if there is only one node then 0 will be root of MHT
        
        if(n == 1)
            return {0};
        
        // make a adjacency list
        
        vector<vector<int>> adj(n);
        
        // find the indegree of every node
        
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
            
            indegree[u]++;
            
            indegree[v]++;
        }
        
        // push the node with indegree 1 into queue
        
        queue<int> q;
        
        for(int u = 0; u < n; u++)
        {
            if(indegree[u] == 1)
            {
               q.push(u);
            }
        }
        
        // run the loop while there is more than 2 node present
        
        while(n > 2)
        {
            int size = q.size();
            
            // remove the size no. of node from graph
            
            n = n - size;
            
            for(int i = 0; i < size; i++)
            {
                // take the front node
                
                int u = q.front();
                
                q.pop();
                
                // decrement the indegree of adjacent node
                
                for(auto v : adj[u])
                {
                    indegree[v]--;
                    
                    // if indegree becomes 1, then push into the queue
                    
                    if(indegree[v] == 1)
                    {
                        q.push(v);
                    }
                }
            }
        }
        
        // remaining node will be the root of MHT
        
        vector<int> res;
        
        while(!q.empty())
        {
            res.push_back(q.front());
            
            q.pop();
        }
        
        return res;
    }
};
