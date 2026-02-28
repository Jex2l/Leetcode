class Codec {
public:
    string encode(vector<string>& strs) {
        string encodedString;
        for (string &s : strs) {
            encodedString += to_string(s.size()) + "/:" + s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        size_t i = 0;
        while (i < s.size()) {
            size_t delim = s.find("/:", i);
            int length = stoi(s.substr(i, delim - i));
            string str = s.substr(delim + 2, length);
            decodedStrings.push_back(str);
            i = delim + 2 + length;
        }
        return decodedStrings;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));