class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int c = 0;
        // vector<int> x;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] == 0){
                a++;
            }
            else if(nums[i] == 1){
                b++;
            }
            else{
                c++;
            }
        }
        nums.clear();
        while(a>0){
            nums.push_back(0);
            a--;
        }
        while(b>0){
            nums.push_back(1);
            b--;
        }
        while(c>0){
            nums.push_back(2);
            c--;
        }
    }
};