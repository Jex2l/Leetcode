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


void inorder(TreeNode* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> a, vector<int> b){
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while( i < a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }
    while(i<a.size()){
        ans[k++] = a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++] = b[j];
        j++;
    }
    return ans;
}


TreeNode *inordertobest(int s, int e, vector<int> &in){
    if(s>e){
        return NULL;
    }
    int mid = s + (e-s)/2;
    TreeNode* root = new TreeNode (in[mid]);
    root->left = inordertobest(s, mid-1, in);
    root->right = inordertobest(mid+1, e, in);
    return root;
}


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        TreeNode* merged = new TreeNode(root1->val + root2->val);
        merged->left = mergeTrees(root1->left, root2->left);
        merged->right = mergeTrees(root1->right, root2->right);
        return merged;
    }
};
