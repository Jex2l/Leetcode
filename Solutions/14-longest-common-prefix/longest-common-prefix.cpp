class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int minLen = INT_MAX;
        for (auto &s : strs) minLen = min(minLen, (int)s.size());
        for (int i = 0; i < minLen; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) return ans;
            }
            ans.push_back(c);
        }
        return ans;
    }
};