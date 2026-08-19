class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> x(nums.begin(), nums.end());

        int result = 0;

        for (int num : x) {
            if (x.find(num - 1) == x.end()) {
                int curr = num;
                int length = 1;

                while (x.find(curr + 1) != x.end()) {
                    curr++;
                    length++;
                }

                result = max(result, length);
            }
        }

        return result;
    }
};