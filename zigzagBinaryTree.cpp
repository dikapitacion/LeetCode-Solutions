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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        int cnt;
        bool dir=1;
        while(!q.empty()){
            cnt = q.size();
            vector<int> tmp;
            while(cnt > 0){
                root = q.front();
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
                tmp.push_back(root->val);
                cnt--;
            }
            ans.push_back(tmp);
            if(!dir) reverse(ans[ans.size()-1].begin(),ans[ans.size()-1].end());
            dir = !dir;
        }
        return ans;
    }
};