class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i< intervals.size(); i++){
            int curr = ans.back()[1];
            int next = intervals[i][0];
            if (next <= curr) {
                ans.back()[1] = max(curr, intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};