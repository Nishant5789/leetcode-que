class Solution {
    void calc(int i,int j,vector<vector<int>>& grid,vector<pair<int,int>>&iland)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        return ;
    
    grid[i][j]=0;
    iland.push_back({i,j});
    
    calc(i+1,j,grid,iland);
    calc(i-1,j,grid,iland);
    calc(i,j+1,grid,iland);
    calc(i,j-1,grid,iland);
           
}
public:
    int shortestBridge(vector<vector<int>>& grid) 
{
    vector<pair<int,int>>iland1; //For storing all the co-ordinates of first iland
    vector<pair<int,int>>iland2; //For storing all the co-ordinates of second iland
    int count=0;
    
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]==1)
            {
                count++;
                if(count==1)
                {
                    calc(i,j,grid,iland1);
                }
                else if(count==2)
                {
                    calc(i,j,grid,iland2);
                }
            }
        }
    }
    int mini=INT_MAX;
    //This part is for calculating the distance b/w every co-ordiantes and finding minimum
    for(int i=0;i<iland1.size();i++)
    {
        for(int j=0;j<iland2.size();j++)
        {
            int dis;
            dis=abs(iland1[i].first-iland2[j].first)+abs(iland1[i].second-iland2[j].second)-1;
            if(dis<mini)
                mini=dis;
        }
    }
    return mini;
}

};


