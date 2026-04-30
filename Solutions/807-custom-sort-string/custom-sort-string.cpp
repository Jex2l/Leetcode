class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> x;
        for(char c : s) x[c]++;
        string ans;
        for(char c : order){
            if(x.find(c) != x.end()){
                while(x[c] > 0){
                    ans.push_back(c);
                    x[c]--;
                }
            }
        }
        for(auto i : x){
            if(i.second > 0){
                while(i.second > 0){
                    ans.push_back(i.first);
                    i.second--;
                }
            }
        }
        return ans;
    }
};