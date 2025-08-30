class Solution {
public:
    long long flowerGame(int n, int m) {
        long long x =n;
        long long y= m;
        return ((x+1)/2)*(y/2)+(x/2)*((y+1)/2);;
    }
};