class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> count;
        for(auto i : arr){
            count[i]++;
        }
        int x = 0;
        vector<int> freq;
        for(auto &p : count){
            freq.push_back(p.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int removed = 0, ans = 0;
        for(int f : freq) {
            removed += f;
            ans++;
            if(removed >= n/2) break;
        }
        return ans;
    }
};