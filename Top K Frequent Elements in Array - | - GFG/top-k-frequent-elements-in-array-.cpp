// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& n, int k) {
        map<int,int> num1;
        for(auto &i: n)
        {
            num1[i]++;
        }
        multimap<int,int> num2;
        for(auto &i : num1)
        {
            num2.insert({i.second, i.first});
        }
    // for(auto &i: num2)
    // {
    //     cout << i.first << " " << i.second ;
    // }
        vector<int> temp;
        auto it = num2.end();
        while(k--)
        {
            it--;
            temp.push_back(it->second);
        }
        return temp;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends