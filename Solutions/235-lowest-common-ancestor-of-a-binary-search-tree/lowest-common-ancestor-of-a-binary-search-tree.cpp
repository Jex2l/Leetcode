/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootval = root->val;
        int pval = p->val;
        int qval = q->val;
        if(pval < rootval && qval<rootval) return lowestCommonAncestor(root->left, p, q);
        if(pval > rootval && qval>rootval) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};