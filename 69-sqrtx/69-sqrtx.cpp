class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        if(x==0) return 0;
        int l=0, h=x,flag;
        while(h-l>1)
        {
            long long mid=(h+l)/2;
            if(mid*mid<=x)
            {
                flag=mid;
                l=mid;
            }
             else
            {
                h=mid;
            }  
        }
        return flag;
    }
};