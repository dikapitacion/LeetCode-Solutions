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
    int findPos(vector<int>& in,int cur){
        for(int i=0;i<in.size();i++){
            if(in[i]==cur){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& pre,vector<int>& in ,int& index,int start,int end){
        if(index>=in.size() || start>end){
            return NULL;
        }
        int cur = pre[index++];
        int pos = findPos(in,cur);

        TreeNode* root = new TreeNode(cur);

        root->left = solve(pre,in,index,start,pos-1);
        root->right = solve(pre,in,index,pos+1,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int index = 0;

        return solve(preorder,inorder,index,0,inorder.size());
        
    }
};