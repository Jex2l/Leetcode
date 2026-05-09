class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.size();
        int maxi = 0;
        unordered_map<char, int> x;
        for(int i = 0; i< n; i++){
            if(x.find(s[i]) != x.end() && x[s[i]]>=l){
                l = x[s[i]]+1;
            }
            x[s[i]] = i;
            maxi = max(maxi, i-l+1);
        }
        return maxi;
    }
};