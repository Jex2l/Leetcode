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
    void createMapping(vector<int> in, map<int, int> &nodeToIndex, int n){
        for(int i = 0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    TreeNode* solve(vector<int> in, vector<int> pre,int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex){
        if(index >= n || inorderStart > inorderEnd){
            return NULL;
         }
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        root->left = solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);
        root->right = solve(in, pre, index, position+1, inorderEnd, n, nodeToIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        TreeNode* ans = solve(inorder, preorder, preOrderIndex, 0, n-1,n, nodeToIndex);
        return ans;
    }
};