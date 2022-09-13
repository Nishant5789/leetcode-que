class Solution {
//     int dijkstra(int n, int source, vector<pair<int,int>> graph[])
//     {
        
//     }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> graph[n+1];
        for(int i=0; i<times.size(); i++)
        {
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        // int K=1;
        // for(auto i: graph)
        // {
        //     cout << k++ << "- ";
        //     cout << i.first << " " << i.second<< endl;
        // }
        vector<int> distance(n+1,INT_MAX);
        vector<bool>visited(n+1,false);
        set<pair<int,int>> st;
        st.insert({0,k});
        distance[k]=0;
        while(st.size()>0)
        {
            auto node = *st.begin();
            int v=node.second, dist = node.first;
            st.erase(st.begin());
            
            if(visited[v]) continue;
            visited[v]=true;
            for(auto child : graph[v])
            {
                int wt=child.second, child_v = child.first;
                // cout << wt << " " << child_v<< endl;
                if(distance[v]+wt < distance[child_v])
                {
                    distance[child_v]=distance[v]+wt;
                    st.insert({distance[child_v],child_v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n; i++)
        {
            if(distance[i]==INT_MAX)
                return -1;
            ans=max(ans, distance[i]);
            cout << distance[i] << " ";
        }
        return ans;
    }
};