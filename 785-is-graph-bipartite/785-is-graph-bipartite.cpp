class Solution {
    bool bfs_bipartite(int start, int V, vector<vector<int>> adj, vector<int> &color){
        queue<int> q;
	    q.push(start); 
	    color[start] = 0; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        
	        for(auto it : adj[node]) {
	            if(color[it] == -1) {
	                
	                color[it] = !color[node]; 
	                q.push(it); 
	            }
	            else if(color[it] == color[node]) {
	                return false; 
	            }
	        }
	    }
	    return true; 
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V=graph.size();
         vector<int> color(V); 
	    for(int i=0;i<V;i++) color[i] = -1; 
	    for(int i=0; i<V; i++)
        {
            if(color[i]==-1 && !bfs_bipartite(i, V, graph, color))
                return false;
        }
        return true;
    }
};