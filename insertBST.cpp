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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        int cur = root->val;
        if(val>cur){
            if(root->right){
                TreeNode* temp = insertIntoBST(root->right,val);
            }
            else{
                root->right = new TreeNode(val);
                return root;
            }
        }
        else{
            if(root->left){
                TreeNode* temp = insertIntoBST(root->left,val);
            }
            else{
                root->left = new TreeNode(val);
                return root;
            }
        }
        return root;
    }
};