class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
{
    int n=rooms.size();
    vector<bool>vis(n,false);
    int i=0;
    queue<int>q;
    q.push(i);
    while(!q.empty())
    {
        vis[i]=true;
        int node=q.front();
        q.pop();
        for(auto child:rooms[node])
        {
            if(vis[child]==false)
            {
                vis[child]=true;
                q.push(child);
            }
        }
        i=q.front();
    }
    
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
            return false;
    }
    return true;
}
};