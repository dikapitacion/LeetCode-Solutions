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
    void solve(TreeNode* root,vector<int>& freq,int& ans){
        freq[root->val]++;

        if(!root->left && !root->right){
            int odd = 0;
            for(auto i:freq){
                if(i%2 != 0){
                    odd++;
                }
            }
            if(odd<=1){
                ans++;
            }
            freq[root->val]--;
            return;
        }

        if(root->left){
            solve(root->left,freq,ans);
        }
        if(root->right){
            solve(root->right,freq,ans);
        }

        freq[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int ans = 0;
        solve(root,freq,ans);
        return ans;
    }
};