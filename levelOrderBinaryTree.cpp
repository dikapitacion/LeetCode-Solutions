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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> sol;
        if(!root){
            return sol;
        }
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> ans;
            while(n>0){
                TreeNode* front = q.front();
                q.pop();
                if(!front){
                    n--;
                    continue;
                }
                ans.push_back(front->val);
                q.push(front->left);
                q.push(front->right);
                n--;
            }
            sol.push_back(ans);
        }
        sol.pop_back();
        return sol;
    }
};