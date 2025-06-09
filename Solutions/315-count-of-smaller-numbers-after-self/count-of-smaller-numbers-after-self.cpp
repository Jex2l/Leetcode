// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int> ans;
//         int count = 0;
//         for(int i = 0; i<nums.size()-1; i++){
//             for(int j = i; j<nums.size(); j++){
//                 if(nums[j]<nums[i]){
//                     count++;
//                 }
//             }
//             ans.push_back(count);
//             count = 0;
//         }
//         ans.push_back(0);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // Step 1: Coordinate compression
        set<int> sorted_set(nums.begin(), nums.end());
        unordered_map<int, int> ranks;
        int rank = 0;
        for (int num : sorted_set) {
            ranks[num] = rank++;
        }

        // Step 2: Fenwick Tree (Binary Indexed Tree)
        vector<int> BIT(rank + 1, 0); // size = max rank + 1

        auto update = [&](int i) {
            i++; // BIT is 1-indexed
            while (i < BIT.size()) {
                BIT[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;
            i++; // BIT is 1-indexed
            while (i > 0) {
                sum += BIT[i];
                i -= i & -i;
            }
            return sum;
        };

        // Step 3: Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            int r = ranks[nums[i]];
            result[i] = query(r - 1);  // count of smaller elements to the left
            update(r);                 // add current element to BIT
        }

        return result;
    }
};

