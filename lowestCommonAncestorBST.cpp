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
        int maxi = max(p->val,q->val);
        int mini = min(p->val,q->val);
        TreeNode* ans;
        if(root->val>maxi){
            ans = lowestCommonAncestor(root->left,p,q);
            return ans;
        }
        if(root->val<mini){
            ans = lowestCommonAncestor(root->right,p,q);
            return ans;
        }
        else if (root->val<maxi && root->val>mini){
            return root;
        }
        return ans;
    }
};