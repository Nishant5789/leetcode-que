class Solution {
    
queue<int> bfs(int node, vector<vector<int>>& adj, int n, int level) {
        vector<int> vis(n, 0);
        queue<int>q;
        
        q.push(node);
        int dist = 0;
        vis[node] = 1;
        
        while(!q.empty()) {
            int size = q.size();
            if(dist == level) break;
            dist++;
            
            for(int i = 0; i < size; i++) {
                auto u = q.front();
                q.pop();
                
                for(auto &v: adj[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        return q;
    }
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level)
    {
        int n = friends.size();
        vector<string>ans;
        set<pair<int, string>>v;
        queue<int>levelFriends = bfs(id, friends, n, level);
        unordered_map<string, int>m;
        
        
        while(!levelFriends.empty()) {
            int i = levelFriends.front();
            levelFriends.pop();
            for(auto &it: watchedVideos[i]) m[it]++;
        }
          
        for(auto &it: m) {
            v.insert({it.second, it.first});
        }
        
        for(auto &it: v) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};