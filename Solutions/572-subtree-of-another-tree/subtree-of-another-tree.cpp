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

bool sametree(TreeNode* root, TreeNode* subRoot){
    if(root == nullptr && subRoot == nullptr) return true;
    if(root == nullptr || subRoot == nullptr) return false;
    if(root->val != subRoot->val) return false;
    return sametree(root->left, subRoot->left) && sametree(root->right, subRoot->right);
}

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(sametree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

