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

    TreeNode* solve(vector<int>& in,vector<int>& post,int& index, int inStart, int inEnd ){
        if(index<0 || inStart>inEnd){
            return NULL;
        }

        int el = post[index--];
        TreeNode* root = new TreeNode(el);
        int pos = findPos(in,el);
        
        root->right = solve(in,post,index,pos+1,inEnd);
        root->left = solve(in,post,index,inStart,pos-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = inorder.size()-1;
        return solve(inorder,postorder,index,0,inorder.size()-1);
    }
};