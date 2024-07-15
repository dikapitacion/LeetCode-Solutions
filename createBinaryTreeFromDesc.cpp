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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> m;
        set<int> parents;
        set<int> children;
        for(auto it:descriptions){
            parents.insert(it[0]);
            TreeNode* parent = new TreeNode(it[0]);
            if(m.find(it[0])!= m.end()){
                parent = m[it[0]];
            }
            children.insert(it[1]);
            TreeNode* child = new TreeNode(it[1]);
            if(m.find(it[1])!= m.end()){
                child = m[it[1]];
            }
            
            m[it[0]] = parent;
            m[it[1]] = child;
            if(it[2]==1){
                parent->left = child;
            }
            else{
                parent->right = child;
            }        
        }
        
        for(auto i:parents){
            if(children.find(i)==children.end()){
                return m[i];
            }
        }
        return nullptr;
    }
};