// class Solution {
// public:
//     string sortString(string s) {
//         int cnt[26] = {0};
//         for (char ch : s) cnt[ch - 'a']++;
//         string res = "";
//         int n = s.size();
//         while (res.size() < n) {
//             for (int i = 0; i < 26; i++) {
//                 if (cnt[i] > 0) {
//                     res += char(i + 'a');
//                     cnt[i]--;
//                 }
//             }
//             for (int i = 25; i >= 0; i--) {
//                 if (cnt[i] > 0) {
//                     res += char(i + 'a');
//                     cnt[i]--;
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
private:
    void maxstr(vector<int> &z, vector<int>& a, vector<bool>& used){
        int d = -1e9;

        for(int i = 0; i < z.size(); i++){
            if(!used[i] && z[i] > d){
                a.push_back(z[i]);
                d = z[i];
                used[i] = true;
            }
        }
    }

    void minstr(vector<int> &z, vector<int>& a, vector<bool>& used){
        int d = 1e9;

        for(int i = z.size()-1; i >= 0; i--){
            if(!used[i] && z[i] < d){
                a.push_back(z[i]);
                d = z[i];
                used[i] = true;
            }
        }
    }


public:
    string sortString(string s) {
        vector<int> x;
        for(int i = 0; i<s.size(); i++){
            int z = s[i];
            x.push_back(z);
        }
        sort(x.begin(), x.end());
        vector<int> a;
        vector<bool> used(x.size(), false);
        int remaining = x.size();
        while(remaining > 0){
            int before = a.size();
            maxstr(x, a, used);
            remaining -= (a.size() - before);
            before = a.size();
            minstr(x, a, used);
            remaining -= (a.size() - before);
        }
        string ans;
        for(int i = 0; i< a.size(); i++){
            ans.push_back(a[i]);
        }
        return ans;
    }
};