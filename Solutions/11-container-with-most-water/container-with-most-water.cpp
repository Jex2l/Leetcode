class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 1;
        int r = height.size();
        int h1 = height[l-1];
        int h2 = height[r-1];
        int maxi = 0;
        while(l < r){
            int temp = (r - l)*(min(h1, h2));
            maxi = max(maxi, temp);
            if(h1 < h2){
                l++;
                h1 = height[l-1];
            }
            else{
                r--;
                h2 = height[r-1];
            }
        }
        return maxi;
    }
};