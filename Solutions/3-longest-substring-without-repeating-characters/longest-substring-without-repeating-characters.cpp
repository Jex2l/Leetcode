class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> x;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++){
            if(x.count(s[right])){
                left = max(left, x[s[right]] + 1);
            }
            ans = max(ans, right - left + 1);
            x[s[right]] = right;
        }
        return ans;
    }
};