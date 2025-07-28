class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> l={0};
        // for(int i = 0; i<nums.size(); i++){
        //     int left = 0;
        //     int mid = i;
        //     int right = 0;
        //     while()
        // }
        int r =0;
        for(int i = 0; i<nums.size()-1; i++){
            l.push_back(l[i]+nums[i]);
        }
        for(int i = nums.size()-1; i>=0; i--){
            l[i]=abs(l[i]-r);
            r+=nums[i];
        }
            
        
        return l;
    }
};