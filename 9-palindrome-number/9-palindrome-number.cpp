class Solution {
public:
    bool isPalindrome(int n) {
        long long reverse_num = 0;
        int temp = abs(n), digit;
        while(n != 0)
        {
            digit = n % 10;
            reverse_num = reverse_num * 10 + digit;
            n /= 10;
        }
        // cout << reverse_num << endl;
        if(temp == reverse_num)
            return 1;
        else
            return 0;
    }
};