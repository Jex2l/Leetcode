class Solution {
private:
    void maxstr(vector<int> &z, vector<int>& a){
        if(z.empty()) return;
        a.push_back(z[0]);
        int d = z[0];
        z.erase(z.begin());
        for(int i = 0; i< z.size(); ){
            if(d < z[i]){
                a.push_back(z[i]);
                d = z[i];
                if (i < z.size()) z.erase(z.begin() + i);
            }
            else{
                i++;
            }
        }
    }
    void minstr(vector<int> &z, vector<int>& a){
        if(z.empty()) return;
        a.push_back(z[0]);
        int d = z[0];
        z.erase(z.begin());

        for(int i = 0; i < z.size(); ) {
            if(d > z[i]){
                a.push_back(z[i]);
                d = z[i];
                z.erase(z.begin() + i);
            }
            else i++;
        }
    }

public:
    string sortString(string s) {
        vector<int> x;
        for(int i = 0; i<s.size(); i++){
            int z = s[i];
            x.push_back(z);
        }
        sort(x.begin(), x.end());
        vector<int> a;
        while(x.size() > 0){
            maxstr(x, a);
            reverse(x.begin(), x.end());
            if(x.empty()) break;   
            minstr(x, a);
            reverse(x.begin(), x.end());
        }
        string ans;
        for(int i = 0; i< a.size(); i++){
            ans.push_back(a[i]);
        }
        return ans;
    }
};