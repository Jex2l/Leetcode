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
    int dfs(TreeNode* root, unordered_map<int, int> &x){
        if(root == nullptr) return 0;
        int val = root->val + dfs(root->left, x) + dfs(root->right, x);
        x[val]++;
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == nullptr) return {};
        unordered_map<int, int> x;
        dfs(root, x);
        unordered_map<int, vector<int>> y;
        int ans = INT_MIN;
        for(auto i : x){
            y[i.second].push_back(i.first);
            ans = max(ans, i.second);
        }
        return y[ans];
    }
};