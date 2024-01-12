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
    int ans=0;
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int sum = 0;

        q.push({root,root->val});

        while(!q.empty()){
            int n = q.size();
            while(n>0){
                pair<TreeNode*,int> temp = q.front();
                q.pop();
                TreeNode* front = temp.first;
                int cur = temp.second;
                if(!front->left && !front->right){
                    sum += cur;
                }

                if(front->left){
                    q.push({front->left,cur*10+front->left->val});
                }
                if(front->right){
                    q.push({front->right,cur*10+front->right->val});
                }
                n--;
            }
        }
        return sum;
    }
};