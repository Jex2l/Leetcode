class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int> > heap;
        for (int i = 0; i < k; i++) heap.push({ nums[i], i });
        res.push_back(heap.top().first);
        for (int i = k; i < nums.size(); i++) {
            heap.push({ nums[i], i });
            while (heap.top().second <= i - k) heap.pop();
            res.push_back(heap.top().first);
        }
        return res;
    }
};