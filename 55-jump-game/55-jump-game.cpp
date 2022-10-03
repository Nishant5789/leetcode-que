class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<int> q;
        q.push(0);
        unordered_map<int,int> mymap;
        mymap[0]=1;
        bool found=false;
        int dest=nums.size()-1;
        
        while(!q.empty())
        {
            int value=q.front(), jump=nums[value];
            q.pop();
            if(found)
                break;
            if(dest<=value)
            {
                found=true;
                break;
            }  
            for(int i=1; i<=jump; i++)
            {
                if(!mymap[value+i])
                {
                    q.push(value+i);
                    mymap[value+i]=1;
                    if(dest<=value+i)
                    {
                        found=true;
                        break;
                    }  
                }   
            }
        }
        return found;
    }
};