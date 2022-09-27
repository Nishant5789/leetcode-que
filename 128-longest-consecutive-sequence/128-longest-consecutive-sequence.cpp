class Solution {
    void makeset(unordered_map<int, int> &parent, int n,unordered_map<int, int> &size)
    {
        parent[n]=n;
        size[n]=1;
    }
    int findparent(unordered_map<int, int> &parent, int node )
    {
        if(parent[node]== node)
            return node;
        // for compress the path
        return  parent[node] = findparent(parent,  parent[node]);
    }
    
    void unionset(int u, int v, unordered_map<int, int> &parent, unordered_map<int, int> &size)
    {
        u = findparent (parent, u);
        v = findparent (parent, v);
        parent[v]=u;
        if(u!=v)
        size[u]+=size[v];
    }
public:
    int longestConsecutive(vector<int>& nums) {

    int n = nums.size(), maxi=INT_MIN;
    if(n==0)
        return 0;
    unordered_map<int, int> parent, size;
    for(int i=0; i<n; i++)
    {
        makeset(parent, nums[i], size);
    }  
    for(int i=0; i<n; i++)
    {
        if(parent.count(nums[i]+1))
        {
            unionset(nums[i], nums[i]+1, parent, size);
        }
    }
    for(auto i: size)
    {
        maxi = max(maxi, i.second);
    }
    return maxi;
    }
};