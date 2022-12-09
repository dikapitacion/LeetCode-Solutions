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
    int ans=0;
    void help(TreeNode* root , int mi,int ma){
        if(!root){
            return;
        }
        mi = min(root->val,mi);
        ma = max(root->val,ma);
        ans = max(abs(mi-ma),ans);
        help(root->left,mi,ma);
        help(root->right,mi,ma);
    }
    int maxAncestorDiff(TreeNode* root) {
        help(root,1000000,0);
        return ans;
    }
};