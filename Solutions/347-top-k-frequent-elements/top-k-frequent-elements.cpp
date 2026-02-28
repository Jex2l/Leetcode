class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto &p : freq){
            int number = p.first;
            int count  = p.second;
            buckets[count].push_back(number);
        }
        vector<int> result;
        for(int i = nums.size(); i >= 1 && result.size() < k; i--) {
            for(int num : buckets[i]) {
                result.push_back(num);
                if(result.size() == k) break;
            }
        }
        return result;
    }
};