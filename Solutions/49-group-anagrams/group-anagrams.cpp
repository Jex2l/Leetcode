const int MAX_CHAR = 26;

// function to generate hash of word s
string getHash(string &s) {
    string hash;
	vector<int> freq(MAX_CHAR, 0);
    // Count frequency of each character
    for(char ch: s)
        freq[ch - 'a'] += 1;
    // Append the frequency to construct the hash
    for(int i = 0; i < MAX_CHAR; i++) {
        hash.append(to_string(freq[i]));
    	hash.append("$");
    }
    return hash;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>> res;
        // unordered_map<string, int> mp;
        // for (int i = 0; i < strs.size(); i++) {
        //     string key = getHash(strs[i]);
        
        //     // If key is not present in the hash map, add
        //     // an empty group (vector) in the result and
        //     // store the index of the group in hash map
        //     if (mp.find(key) == mp.end()) {
        //         mp[key] = res.size();
        //         res.push_back({});
        //     }
        
        //     // Insert the string in its correct group
        //     res[mp[key]].push_back(strs[i]);
        // }
        // return res;
        unordered_map<string, vector<string>> buckets;

        for (const auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());   // signature
            buckets[key].push_back(s);           // keep original
        }

        vector<vector<string>> result;
        result.reserve(buckets.size());
        for (auto& kv : buckets) {
            result.push_back(move(kv.second));
        }
        return result;
    }
};