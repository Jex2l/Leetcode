/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        dfs(root, mp);
        int maxKey = INT_MIN;
        unordered_map<int, vector<int>> mp2;
        for(auto it : mp){
            mp2[it.second].push_back(it.first);
            maxKey = max(maxKey, it.second);
        }
        return mp2[maxKey];
    }
    int dfs(TreeNode* root, unordered_map<int, int> &mp){
        if(root == nullptr) return 0;
        int val = root->val + dfs(root->left, mp) + dfs(root->right, mp);
        mp[val]++;
        return val;
    }
};