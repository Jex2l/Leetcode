// class Solution {
// public:
//     string removeDuplicates(string s) {
//         string x;
//         stack<char> y;
//         for(int i = 0; i<s.size(); i++){
//             if(y.empty() || y.top() != s[i]) y.push(s[i]);
//             else y.pop();
//         }
//         while(!y.empty()){
//             x.push_back(y.top());
//             y.pop();
//         }
//         reverse(x.begin(), x.end());
//         return x;
//     }
// };

class Solution {
public:
    string removeDuplicates(string s) {
        string st;

        for(char c : s) {
            if(!st.empty() && st.back() == c) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }

        return st;
    }
};