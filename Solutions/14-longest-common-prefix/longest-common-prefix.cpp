class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans = "";
        for (size_t i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];
            bool match = true;
            for (size_t j = 1; j < strs.size(); ++j){
                if (i >= strs[j].size() || strs[j][i] != ch){
                    match = false;
                    break;
                }
            }
            if (!match) break;
            ans.push_back(ch);
        }
        return ans;
    }
};
