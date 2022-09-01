class Solution {
    
//     Idea behid this solution is that, whenever there is an node which indulges in a cycle then we will have at leats one path from that node which will not lead to terminal node. So, to put it simply every node which is part of cycle is not our answer/safe state.

// Steps :

// Take two arrays named as 'vis' and 'dfsVis'.
// Then we will simply traverse the graph using dfs and mark vis[node] = 1 and dfVis[node] = 1.
// When we wil not find the cycle we will make dfsVis[node] = 0 when we are backtracking.
// If cycle is found we will simply return true and will not update dfsVis[node] = 0 in this case.
// Then we will put all the elements in answer vector where dfsVis[i] = 0;

    bool isCycle(int node, vector<vector<int>> &graph, vector<int> &vis, 
                 vector<int> &dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto i:graph[node]){
            if(vis[i]==0){
                if(isCycle(i, graph, vis, dfsVis))
                    return true;
            }
            else if(dfsVis[i])
                return true;
        }
        dfsVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
                int n = graph.size();
        vector<int> vis(n, 0), dfsVis(n, 0);
        
        for(int i=0; i<n; i++){
            if(vis[i]==0)
                if(isCycle(i, graph, vis, dfsVis))
                    continue;
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(dfsVis[i]==0)
                ans.push_back(i);
        
        return ans;
    }
};