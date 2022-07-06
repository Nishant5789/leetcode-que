class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.size();
        int st = 0, en = 0, maxlen = n > 0? 1: 0;


        for(int i = 0; i < n; i++) {
            for(int l = i, r = i+1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if((r-l+1) > maxlen) {
                    maxlen = r-l+1;
                    st=l; en = r;
                }
            }

            for(int l = i-1, r = i+1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                if((r-l+1) > maxlen) {
                    maxlen = r-l+1;
                    st=l; en = r;
                }
            }
        }

        return s.substr(st, maxlen);

    }
};