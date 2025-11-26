class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        int n = candyType.size();
        vector<int> x;
        x.push_back(candyType[0]);
        int a = 1;
        for(int i = 1; i<n; i++){
            if(x[a-1] != candyType[i]){
                x.push_back(candyType[i]);
                a++;
            }
        }
        if(n/2 >= a){
            return a;
        }
        return n/2;
    }
};