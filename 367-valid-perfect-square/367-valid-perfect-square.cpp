class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=0, h=num;
        if(num==1)
            return true;
        while(h-l>1)
        {
            long long mid=(l+h)/2;
            if(mid*mid == num)
            {
                return true;
            }
            else
                if(mid*mid < num)
                {
                    l=mid;
                }
            else
            {
                h=mid;
            }
        }
        return false;
        
    }
};