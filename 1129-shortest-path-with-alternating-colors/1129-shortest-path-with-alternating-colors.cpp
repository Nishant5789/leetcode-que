class Solution {

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)
    {
    vector<vector<int>> red(n),blue(n);
		for(int i=0;i<redEdges.size();i++) {
			red[redEdges[i][0]].push_back(redEdges[i][1]);
		}
		for(int i=0;i<blueEdges.size();i++) {
			blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
		}
		queue<vector<int>> pq;
		pq.push({0,0,0});
		vector<int> distr(n,INT_MAX),distb(n,INT_MAX),vis(n);
		distr[0]=0,distb[0]=0;
		while(pq.size()) {
			int du=pq.front()[0];
			int u=pq.front()[1];
			int typeU=pq.front()[2];
			pq.pop();
			if(typeU!=1) {
				for(int i=0;i<red[u].size();i++) {
					int v=red[u][i];
					if(distr[v]>du+1) {
						distr[v]=du+1;
						pq.push({distr[v],v,1});
					}
				}
			}
			if(typeU!=2) {
				for(int i=0;i<blue[u].size();i++) {
					int v=blue[u][i];
					if(distb[v]>du+1) {
						distb[v]=du+1;
						pq.push({distb[v],v,2});
					}
				}
			}
		}
		vector<int> dist(n);
		for(int i=0;i<n;i++) {
			int d=min(distr[i],distb[i]);
			if(d==INT_MAX) dist[i]=-1;
			else dist[i]=d;
		}
		return dist;
	}
};
