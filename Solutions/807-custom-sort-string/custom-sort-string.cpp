class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> x;
        for(char c : s) x[c]++;
        string ans;
        for(int i = 0; i<order.size(); i++){
            if(x.find(order[i]) != x.end()){
                while(x[order[i]] > 0){
                    ans.push_back(order[i]);
                    x[order[i]]--;
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