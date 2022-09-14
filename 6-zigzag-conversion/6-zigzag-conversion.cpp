class Solution {
public:
    string convert(string s, int numRows) {
                int n = s.size() ;
        int x = 0 ;
        string temp[numRows] ;
        string ans ; 
        bool down = true ;
        bool up = false ;
        if(numRows != 1)
        {
        for(int i = 0 ; i < n ; i++)
        {
            if(down)
            {
                temp[x] += s[i] ;
                x++ ;
            }
            
            if(up)
            {
                x-- ;
                temp[x] += s[i] ;
                
            }
            
            if(x==numRows || x == 0)
            {
                if(down)
                {
                    x-- ;
                    up = true ;
                    down = false;
                }else{
                    x++ ;
                    down =true ;
                    up = false ;
                }
            }
            
        }
        }else{
            return s ;
        }
        
        for(int i = 0 ; i < numRows ; i++)
        {
            ans += temp[i] ;
        }
        
        return ans ;

        
    }
};