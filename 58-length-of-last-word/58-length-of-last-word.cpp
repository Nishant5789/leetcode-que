class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int end = s.length()-1;
        int length=0;
        while(end!=0)
        if(s.at(end)==' ')
            end--;
        else
            break;
        if(end==0)
            return 1;
         while(s.at(end)!= ' ' && end!=0){ 
                length++;
                end--;
            }
        if(end==0 && s.at(end)!=' ')
            return length+1;
        return length;
    }
};