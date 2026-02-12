class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ (1 << (s[i] - 'a'));
        }
        vector<bool> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];     
            int mask = prefix[r + 1] ^ prefix[l];
            int oddCount = __builtin_popcount(mask);
            ans.push_back(oddCount / 2 <= k);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
//         vector<bool> ans;
//         for(int i = 0; i< queries.size(); i++){
//             vector<int> x = queries[i];
//             int k = x[2]; 
//             if(x[0] == x[1]){
//                 ans.push_back(true);
//                 continue;
//             }
//             string a = s.substr(x[0], x[1]-x[0] + 1);
//             unordered_map<char, int> freq;
//             for (char c : a) {
//                 freq[c]++;
//             }
//             int oddCount = 0;
//             for (auto &pair : freq) {
//                 if (pair.second % 2 != 0) {
//                     oddCount++;
//                 }
//             }
//             if(oddCount / 2 <= k){
//                 ans.push_back(true);
//             }
//             else{
//                 ans.push_back(false);
//             }
//         }
//         return ans;
//     }
// };