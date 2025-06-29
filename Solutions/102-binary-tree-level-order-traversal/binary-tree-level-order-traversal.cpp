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

void levelOrderRec(TreeNode* root, int level, vector<vector<int>>& res) {
    // Base case: If node is null, return
    if (root == nullptr) return;

    // Add a new level to the result if needed
    if (res.size() <= level)
        res.push_back({});
  
    // Add current node's data to its corresponding level
    res[level].push_back(root->val);

    // Recur for left and right children
    levelOrderRec(root->left, level + 1, res);
    levelOrderRec(root->right, level + 1, res);
}


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; 
        levelOrderRec(root, 0, res);
        return res;
    }
};