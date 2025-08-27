class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int max=nums[0];
        int i=0;
        while(i<nums.size() && nums[i]<0)
        {
            if(nums[i]>max)
                max=nums[i];
            i++;
        }
        for(; i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(sum<0)
                sum=0;
            if(sum>max)
                max=sum;
        }
        return max;
    }     
};