class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int x = 0;
        vector<int> asd;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                asd.push_back(nums[i]);
                x++;
            }
        }
        nums = asd;
        return x;
    }
};