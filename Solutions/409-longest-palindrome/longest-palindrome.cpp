class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        for(char c : s) freq[c]++;
        int len = 0;
        bool odd = false;
        for(int f : freq) {
            len += (f / 2) * 2;
            if(f % 2 == 1) odd = true;
        }
        if(odd) len++;
        return len;
    }
};