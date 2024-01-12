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
    vector<vector<int>> sol;
    void help(TreeNode* root,int target,vector<int>& arr){
        if(!root){return;}
        arr.push_back(root->val);
        
        if(target-(root->val)==0 && !root->left && !root->right){
            sol.push_back(arr);
        }

        help(root->left,target-root->val,arr);
        help(root->right,target-root->val,arr);
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){return sol;}
        vector<int> arr;
        help(root,targetSum,arr);
        return sol;
    }
};