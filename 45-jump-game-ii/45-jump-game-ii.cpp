class Solution {
public:
    int jump(vector<int>& nums) {
        queue<int> q;
        q.push(0);
        unordered_map<int,int> mymap, level;
        mymap[0]=1;
        bool found=false;
        int dest=nums.size()-1, ans=0;
        if(dest==0)
            return 0;
        
        while(!q.empty())
        {
            int value=q.front(), jump=nums[value];
            q.pop();
            if(found)
                break;
            for(int i=1; i<=jump; i++)
            {
                if(!mymap[value+i])
                {
                    q.push(value+i);
                    level[value+i]=level[value]+1;
                    mymap[value+i]=1;
                    if(dest<=value+i)
                    {
                        ans=level[value+i];
                        found=true;
                        break;
                    }  
                }   
            }
        }
        return ans;
    }
};