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

//Wrong solution it passes only 14 test cases

// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(!root){
//             return ans;
//         }
//         map<int,vector<int>> m;

//         queue<pair<TreeNode*,int>> q;

//         q.push({root,0});

//         while(!q.empty()){
//             int n = q.size();

//             while(n>0){
//                 pair<TreeNode*,int> temp = q.front();
//                 q.pop();
//                 int hd = temp.second;
//                 TreeNode* front = temp.first;
//                 m[hd].push_back(front->val);
//                 if (front->left){
//                     q.push({front->left,hd-1});
//                 }
//                 if (front->right){
//                     q.push({front->right,hd+1});
//                 }
//                 n--;
//             }
//         }

//         for(auto i:m){
//             // sort(i.second.begin(),i.second.end());
//             ans.push_back(i.second);
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root){
            return {};
        }

        map<int,map<int,vector<int>>> nodes;
        queue <pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;

        q.push({root,{0,0}});

        while(!q.empty()){
            int n = q.size();
            while(n>0){
                pair<TreeNode*,pair<int,int>> temp = q.front();
                q.pop();
                TreeNode* front = temp.first;
                int hd = temp.second.first;
                int lvl = temp.second.second;
                nodes[hd][lvl].push_back(front->val);
                if(front->left){
                    q.push({front->left,{hd-1,lvl+1}});
                }
                if(front->right){
                    q.push({front->right,{hd+1,lvl+1}});
                }
                n--;
            }
        }

        for(auto i:nodes){
            vector<int> level;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                level.insert(level.end(),j.second.begin(),j.second.end());
            }
            // sort(level.begin(),level.end());
            ans.push_back(level);
        }

        return ans;


    }
};