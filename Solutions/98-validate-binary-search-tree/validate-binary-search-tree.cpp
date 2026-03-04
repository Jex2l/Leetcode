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
    bool validate(TreeNode* root, TreeNode* left, TreeNode* right){
        if(root == nullptr) return true;
        if((left != nullptr && root->val <= left->val)||(right != nullptr &&root->val >= right->val)) return false;
        return validate(root->right, root, right) && validate(root->left, left, root);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};