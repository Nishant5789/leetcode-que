class Solution {
public:
    int lengthOfLongestSubstring(string str) {
  vector <int> v(256, -1);
  int maxlen = 0, start = -1;
  for(int i = 0; i < str.size() ;i++)
  {
    if(v[str[i]] > start)
        start = v[str[i]];
      v[str[i]] = i;
      maxlen = max(maxlen, i - start);
  }
        return maxlen;
        
    }
};