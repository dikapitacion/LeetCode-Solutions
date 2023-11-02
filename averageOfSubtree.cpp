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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(!root) return{0,0};

        auto [ls,lc] = solve(root->left);
        auto [rs,rc] = solve(root->right);

        int cur = ls+rs+root->val;
        int curc = 1+lc+rc;

        if(cur/curc == root->val){
            ans++;
        }
        return {cur,curc};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};