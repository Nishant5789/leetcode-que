class Solution {
public:
    int majorityElement(vector<int>& a) {
                int cnt=0;
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(cnt==0)
            ans=a[i];
            if(ans==a[i])
            cnt++;
            else
            cnt--;
        }
        return ans;

        
        
    }
};