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
    int ans = 0;
    vector<int> solve(TreeNode* root, int target){
        if(!root) return {0};
        if(!root->left && !root->right) return {1};

        vector<int> leftArr = solve(root->left,target);
        vector<int> rightArr = solve(root->right,target);

        vector<int> res;
        for(int i=0;i<leftArr.size();i++){
            for(int j=0;j<rightArr.size();j++){
                if((leftArr[i] && rightArr[j]) && leftArr[i]+rightArr[j]<=target) ans++;
            }
        }

        for(auto i:leftArr){
            if(i && i+1<target) res.push_back(i+1);
        }

        for(auto i:rightArr){
            if(i && i+1<target) res.push_back(i+1);
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        vector<int> temp = solve(root,distance);
        return ans;
    }
};