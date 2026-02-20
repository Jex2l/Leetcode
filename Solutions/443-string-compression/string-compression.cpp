void addCount(int count, vector<char>& y) {
    if(count > 1) {
        string temp = "";
        int t = count;
        while(t > 0) {
            temp += char(t % 10 + '0');
            t /= 10;
        }
        for(int j = temp.size() - 1; j >= 0; j--) y.push_back(temp[j]);
    }
}

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<int> x;
        vector<char> y;
        int n = chars.size();
        int count = 1;
        for(int i = 1; i<n; i++){
            if(chars[i] != chars[i-1]){
                y.push_back(chars[i-1]);
                addCount(count, y);
                count = 1;
            }
            else count++;
        }
        y.push_back(chars[n-1]);
        addCount(count, y);
        chars = y;
        return y.size();
    }
};