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
    void PreOrder(TreeNode* root,vector<TreeNode*>& arr){
        if(!root){return;}
        arr.push_back(root);
        PreOrder(root->left,arr);
        PreOrder(root->right,arr);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> arr;
        PreOrder(root,arr);
        for(int i=0;i<arr.size();i++){
            arr[i]->left = NULL;
            if(i==arr.size()-1){
                arr[i]->right = NULL;
                break;
            }
            arr[i]->right = arr[i+1];
        }
    }
};