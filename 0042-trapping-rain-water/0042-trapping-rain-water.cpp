class Solution {
public:
    int trap(vector<int>& height) {
        int l=height.size();
        if(l<3)
            return 0;
        vector<int> maxi(height.size(),0), mini(height.size(), 0);
        int ans=0, start=-1, flag=1;
        maxi[0]=height[0];
        mini[height.size()-1]=height[height.size()-1];
        
        for(int i=1; i<height.size(); i++)
        {
            if(height[i-1]!=0 && flag)
            {
                start=i-1;
                flag=0;
            }
            maxi[i]=max(maxi[i-1], height[i]);
            mini[l-i-1]=max(mini[l-i],height[l-i-1]);
        }
        int begin=height[start];
        // cout << begin ;
        for(int i=start+1; i<height.size(); i++)
        {
            if(begin>height[i])
            {
                int temp=abs(height[i]-min(begin,mini[i]));
                // cout << temp << " ";
                ans+=temp;
            }
            else
            {
                // ans+=abs(height[i-1]-begin);
                begin=height[i];
            }
        }
        return ans;
    }
};