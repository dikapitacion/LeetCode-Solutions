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
    // vector<int> all;
    // void in(TreeNode* root){
    //     if(!root){return;}

    //     in(root->left);
    //     all.push_back(root->val);
    //     in(root->right);
    // }
     void solve(TreeNode* root, int &cnt, int &ans, int k){
        if(root == NULL)    return;
        //left, root, right 
        solve(root->left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        solve(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;        
        int ans;
        solve(root, cnt, ans, k);
        return ans;
    }
};