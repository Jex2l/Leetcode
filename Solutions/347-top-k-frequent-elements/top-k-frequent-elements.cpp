class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }
        vector<int> ans;
        for (auto &p : freq) {
            int num = p.first;
            ans.push_back(num);
            int i = (int)ans.size() - 1;
            while (i > 0 && freq[ans[i]] > freq[ans[i - 1]]) {
                int temp = ans[i];
                ans[i] = ans[i - 1];
                ans[i - 1] = temp;
                i--;
            }
        }
        vector<int> final;
        for(int i = 0; i < k; i++) final.push_back(ans[i]);
        return final;
    }
};