class Solution {
    void makeset(vector<int> &parent, int n)
    {
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }
    }
    
    int findparent(vector<int> &parent, int node)
    {
        if(parent[node]== node)
            return node;
        // for compress the path
        return  parent[node] = findparent(parent,  parent[node]);
    }
    
    void unionset(int u, int v, vector<int> &parent)
    {
        u = findparent (parent, u);
        v = findparent (parent, v);
        parent[v]=u;
    }
    
public:
    int findCircleNum(vector<vector<int>>& isconnect) {
        
        int n=isconnect.size(), m=isconnect[0].size();
        vector<int> parent(n);
        makeset(parent, n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(isconnect[i][j])
                unionset(i, j, parent);
            }
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(parent[i]==i)
                count++;
        }
        return count;
    }
};