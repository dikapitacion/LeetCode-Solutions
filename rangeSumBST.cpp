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
    int solve(TreeNode* root,int low,int high,int& sum){
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        if(root->left){
            solve(root->left,low,high,sum);
        }
        if(root->right){
            solve(root->right,low,high,sum);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        ans = solve(root,low,high,ans);
        return ans;
    }
};