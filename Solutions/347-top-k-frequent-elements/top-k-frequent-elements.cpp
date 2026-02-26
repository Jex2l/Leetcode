class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }
        vector<pair<int,int>> v;
        for(auto &p : freq){
            v.push_back({p.first, p.second});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        vector<int> ans;
        int i = 0;
        while(k > 0){
            ans.push_back(v[i].first);
            i++;
            k--;
        }
        return ans;
    }
};