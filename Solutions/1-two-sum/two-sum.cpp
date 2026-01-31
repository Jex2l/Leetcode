class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>a;
        // for(int i = 0; i<nums.size(); i++){
        //     for(int j = i+1; j<nums.size(); j++){
        //         if(nums[i]+nums[j] == target){
        //             a.push_back(i);
        //             a.push_back(j);
        //         }
        //     }
        // }
        // return a;


        // vector<int> d = nums;
        // sort(d.begin(), d.end());
        // vector<int> x;
        // int s = 0;
        // int e = d.size() - 1;
        // while(s <= e){
        //     int sum = d[s] + d[e];
        //     if(sum == target){
        //         x.push_back(d[s]);
        //         x.push_back(d[e]);
        //         break;
        //     }
        //     else if(sum < target){
        //         s++;
        //     }
        //     else{
        //         e--;
        //     }
        // }
        // int first = -1, second = -1;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == x[0]) {
        //         first = i;
        //         break;
        //     }
        // }
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == x[1] && i != first) {
        //         second = i;
        //         break;
        //     }
        // }

        // x[0] = first;
        // x[1] = second;
        // return x;

        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.count(need))
                return {mp[need], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};