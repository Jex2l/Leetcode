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
private:
    TreeNode* ans;
public:
    bool recurseTree(TreeNode* currentNode, TreeNode* p, TreeNode* q){
        if(currentNode == nullptr) return false;
        int left = this -> recurseTree(currentNode->left, p, q) ? 1 : 0;
        int right = this -> recurseTree(currentNode->right, p, q) ? 1 : 0;
        int mid = (currentNode == p || currentNode == q) ? 1 : 0;
        if(mid + left + right >= 2) this->ans = currentNode;
        return (mid + left + right > 0);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this ->recurseTree(root, p, q);
        return this->ans;
    }
};