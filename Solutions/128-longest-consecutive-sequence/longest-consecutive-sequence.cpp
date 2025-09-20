class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> s(nums.begin(), nums.end());
    int maxLen = 0;

    for (int num : s) {
        if (!s.count(num - 1)) {
            int cur = num;
            int len = 1;
            while (s.count(cur + 1)) {
                cur++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}
};