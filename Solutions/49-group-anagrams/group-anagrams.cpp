class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        for(string &s : strs) {
            vector<int> freq(26, 0);
            for(char c : s) freq[c - 'a']++;
            string key;
            for(int i = 0; i < 26; i++) {
                if(freq[i] > 0) {
                    key += char(i + 'a');
                    key += to_string(freq[i]);
                }
            }
            buckets[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &p : buckets) result.push_back(p.second);
        return result;
    }
};