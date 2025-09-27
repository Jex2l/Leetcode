class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0;
        int e = numbers.size() - 1;
        vector <int> x;
        while(s < e){
            if((numbers[s] + numbers[e]) == target){
                x.push_back(s+1);
                x.push_back(e+1);
                return x;
            }
            else if((numbers[s] + numbers[e]) > target){
                e--;
            }
            else{
                s++;
            }
        }
        return x;
    }
};