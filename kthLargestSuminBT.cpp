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
    void solve(TreeNode* root , int level ,vector<long long>& sums){
        if(!root){return;}
        if(!sums[level]){
            sums.push_back(root->val);
        }
        else{
            sums[level]+=root->val;
        }
        solve(root->left,level+1,sums);
        solve(root->right,level+1,sums);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        vector<long long> sums;
        // solve(root,0,sums);
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            long long sum = 0;

            while(n>0){
                TreeNode* front = q.front();
                q.pop();
                sum+=front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                n--;
            }
            sums.push_back(sum);
            sum = 0;
        }
        if(k>sums.size()){
            return -1;
        }
        sort(sums.begin(),sums.end(),greater());
        return static_cast<long long>(sums[k - 1]);

    }
};