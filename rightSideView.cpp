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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        map<int,int> m;//level and value;
        queue<TreeNode*> q;
        vector<int> ans;
        int level = 0;
        
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            while(n>0){
                TreeNode* front = q.front();
                q.pop();
                if(!front){
                    n--;
                    continue;
                }else{
                    int val = front->val;
                    m.insert({level+1,val});
                    q.push(front->right);
                    q.push(front->left);
                    n--;
                }
            }
            level++;
        }

        for(auto itr = m.begin(); itr!=m.end();itr++){
            ans.push_back(itr->second);
        }
        return ans;
    }
};