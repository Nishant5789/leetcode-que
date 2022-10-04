class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        queue<int> q;
        q.push(start);
        unordered_map<int,int> mymap;
        mymap[start]=1;
        bool found=false;
        int dest = nums.size()-1;
        if(!nums[start])
            return true;
        
        while(!q.empty())
        {
            int value=q.front(), jump=nums[value];
            q.pop();
            if(found)
                break;
            if((value+jump) <= dest && !mymap[value+jump])
            {
                q.push(value+jump);
                mymap[value+jump]=1;
                if(!nums[value+jump])
                {
                    found=true;
                    break;
                }  
            } 
            if( (value-jump)>=0  && !mymap[value-jump])
            {
                q.push(value-jump);
                mymap[value-jump]=1;
                if(!nums[value-jump])
                {
                    found=true;
                    break;
                }  
            }   
        }
        return found;
    }
};