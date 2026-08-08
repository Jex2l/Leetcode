// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> x;
//         vector<vector<string>> ans;
//         if(strs.size() <= 1) return {strs};
//         for(int i = 0; i<strs.size(); i++){
//             string tempq = sort(strs[i].begin(), strs[i].end());
//             x[tempq].push_back(strs[i]);
//         }
//         int y = 0;
//         for(auto i : x){
//             for(auto j : i.second){
//                 ans[y].push_back(j);
//             }
//             y++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> x;
        vector<vector<string>> ans;
        for(string i : strs){
            vector<int> freq(26, 0);
            for(char c : i){
                freq[c - 'a']++;
            }
            string tempo = "";
            for(int i : freq){
                string e = to_string(i);
                tempo+=e;
                tempo+='#';
            }
            x[tempo].push_back(i);
        }
        for (auto i : x) {
            ans.push_back(i.second);
        }
        return ans;
    }
};