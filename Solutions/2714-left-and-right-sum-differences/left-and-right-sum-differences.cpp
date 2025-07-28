class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> l={0};
        vector<int> r = {0};
        // for(int i = 0; i<nums.size(); i++){
        //     int left = 0;
        //     int mid = i;
        //     int right = 0;
        //     while()
        // }
        for(int i = 0; i<nums.size()-1; i++){
            l.push_back(l[i]+nums[i]);
            r.push_back(r[i]+nums[nums.size()-1-i]);
        }
        
        for(int i = 0; i<nums.size(); i++)
            l[i]=abs(l[i]-r[nums.size()-i-1]);
        
        return l;
    }
};