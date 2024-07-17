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
    void dfs(TreeNode* &root,set<int> st, vector<TreeNode*>& ans){

        if(!root) return;

        dfs(root->left,st,ans);
        dfs(root->right,st,ans);

        if(st.find(root->val)!=st.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            
            if(root->right){
                ans.push_back(root->right);
            }
            root=NULL;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        set<int> st;
        for(auto i:to_delete){
            st.insert(i);
        }
        dfs(root,st,ans);
        if(root) ans.push_back(root);
        return ans;
    }
};