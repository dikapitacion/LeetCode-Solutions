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
    int findPos(vector<int>in ,int el){
        int n = in.size();
        for(int i=0;i<n;i++){
            if(in[i]==el){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& pre, vector<int>& in,int& index,int inStart,int inEnd){

        if(index>=pre.size() || inStart>inEnd){
            return NULL;
        }
        int el = pre[index++];
        TreeNode* root = new TreeNode(el);
        int pos = findPos(in,el);

        root->left = solve(pre,in,index,inStart,pos-1);
        root->right = solve(pre,in,index,pos+1,inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return solve(preorder,inorder,index,0,inorder.size()-1);
    }
};