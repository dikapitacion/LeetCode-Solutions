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
    pair<int,int> dFast(TreeNode* root){
        if(!root){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = dFast(root->left);
        pair<int,int> right = dFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second+right.second;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second)+1;

        return ans;
    }
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(!root){
        //     return 0;
        // }
        // int left = diameterOfBinaryTree(root->left);
        // int right = diameterOfBinaryTree(root->right);
        // int both = height(root->left) + height(root->right);
        // int ans = max(left,right);
        // return max(ans,both);

        pair<int,int> ans = dFast(root);
        return ans.first;
    }
};