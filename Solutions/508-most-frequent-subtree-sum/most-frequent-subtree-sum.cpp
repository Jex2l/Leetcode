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
        unordered_map<int, int> x;
        dfs(root, x);
        int maxcnt = INT_MIN;
        unordered_map<int, vector<int>> x2;
        for(auto i : x){
            x2[i.second].push_back(i.first);
            maxcnt = max(maxcnt, i.second);
        }
        return x2[maxcnt];
    }
    int dfs(TreeNode* root, unordered_map<int, int> &x){
        if(root == nullptr) return 0;
        int val = root->val + dfs(root->left, x) + dfs(root->right, x);
        x[val]++;
        return val;
    }
};