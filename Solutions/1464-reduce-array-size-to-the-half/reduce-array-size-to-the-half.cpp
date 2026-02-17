class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> count;
        for(auto i : arr) count[i]++;
        int x = 0;
        vector<int> bucket(n + 1, 0);
        for(auto &p : count) bucket[p.second]++;
        int removed = 0, ans = 0;
        for(int f = n; f > 0 && removed < n/2; f--) {
            while(bucket[f] > 0 && removed < n/2) {
                removed += f;
                bucket[f]--;
                ans++;
            }
        }
        return ans;
    }
};