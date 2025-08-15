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

bool isbst(TreeNode *root, long long minVal, long long maxVal) {
    if (root == nullptr) {
        return true;
    }
    if (root->val > minVal && root->val < maxVal) {
        bool left = isbst(root->left, minVal, root->val);
        bool right = isbst(root->right, root->val, maxVal);
        return left && right;
    } else {
        return false;
    }
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isbst(root, LLONG_MIN, LLONG_MAX);
    }
};
