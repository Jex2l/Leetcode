// class Solution {
// public:
//     string simplifyPath(string path) {
//         string token = "";
//         stringstream ss(path);
//         stack<string> st;
//         while(getline(ss, token, '/')){
//             if(token == "" || token == ".") continue;
//             if(token != ".."){
//                 st.push(token);
//             }
//             else if(!st.empty()) st.pop();
//         }
//         if(st.empty()) return "/";
//         string result = "";
//         while(!st.empty()){
//             result = "/" + st.top() + result;
//             st.pop();
//         }
//         return result;
//     }
// };
class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        stack<char> st;
        st.push('/');
        int n = (int)path.size();
        int i = 0;
        while (i < n) {
            while (i < n && path[i] == '/') i++;
            int j = i;
            while (j < n && path[j] != '/') j++;
            string seg = path.substr(i, j - i);
            i = j;
            if (seg.empty() || seg == ".") {
                continue;
            }
            if (seg == "..") {
                if ((int)st.size() > 1) {
                    if (!st.empty() && st.top() == '/') st.pop();
                    while ((int)st.size() > 1 && st.top() != '/') st.pop();
                    if (st.empty()) st.push('/');
                }
                continue;
            }
            if (!st.empty() && st.top() != '/') st.push('/');
            for (char c : seg) st.push(c);
            st.push('/');
        }
        if ((int)st.size() > 1 && st.top() == '/') st.pop();
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "/" : result;
    }
};
