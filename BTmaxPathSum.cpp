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
    int maxi = INT_MIN;
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return(make_pair(0,0));
        }
        pair<int,int>left = solve(root->left);
        pair<int,int> right = solve(root->right);
        int op1 = max(left.first,left.second) + root->val;
        int op2 = max(right.first,right.second) + root->val;
        int op3 = root->val;
        int op4 = op1+op2-op3;
        int take = max(max(op1,op2),max(op3,op4));
        maxi = max(take,maxi);
        return(make_pair(0,max(op1,op2)));
    }
    int maxPathSum(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return maxi;
    }
};