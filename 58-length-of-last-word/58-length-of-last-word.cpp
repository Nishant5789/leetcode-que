class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int end = s.length()-1;
        int length=0;
        while(end!=0){
        if(s.at(end)==' ')
            end--;
            
         if(s.at(end)!= ' ' && end!=0)
         { 
            length++;
            end--;
         
            if(s.at(end)==' ' || end==0) 
                break;
         }   
        }
        if(s.at(end)!=' ' )
            return length+1;
        return length;

    }
};