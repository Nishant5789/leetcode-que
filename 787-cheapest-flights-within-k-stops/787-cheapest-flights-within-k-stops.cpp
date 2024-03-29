class Solution {
public:
    struct Edge {
        int val, cost;
        Edge() {}
        Edge(int dst, int cost) : val(dst), cost(cost) {}
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<Edge>> graph(n); // node -> list of edges
        for(auto flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        queue<Edge> que;
        vector<int> dist(n, INT_MAX);
        que.push({src, 0});
        int stops = -1;
        while(stops <= k && !que.empty()) {
            int len = que.size();
            for(int i=0; i<len; i++) {
                Edge n = que.front();
                que.pop();
                if(n.cost > dist[n.val]) continue;
                dist[n.val] = n.cost;
                for(Edge nei : graph[n.val])
                    que.push({nei.val, nei.cost + n.cost});
            }
            ++stops;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};