class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastPos;
        int best = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            if (lastPos.count(c) && lastPos[c] >= left) {
                left = lastPos[c] + 1;
            }
            lastPos[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};