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
    TreeNode* lcaa(TreeNode* root, int p,int q){
        if(!root || root->val == p || root->val == q) return root;

        TreeNode* left = lcaa(root->left,p,q);
        TreeNode* right = lcaa(root->right,p,q);

        if(left && right) return root;
        else if(left) return left;
        else return right;
    }

    string dfsUp(TreeNode* root,int val,string& str){
        if(!root) return "";
        if(root->val == val) return str;

        str+="U";
        string left = dfsUp(root->left,val,str);
        if(left!="") return left;

        str.pop_back();
        str+="U";
        string right = dfsUp(root->right,val,str);
        str.pop_back();

        return right;
    }

    string dfsDown(TreeNode* root,int val,string& str){
        if(!root) return "";
        if(root->val == val) return str;

        str+="L";
        string left = dfsDown(root->left,val,str);
        if(left!="") return left;
        
        str.pop_back();
        str+="R";
        string right = dfsDown(root->right,val,str);
        str.pop_back();

        
        return right;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lcaa(root,startValue,destValue);
        string res = "";
        string source = dfsUp(lca,startValue,res);
        res = "";
        string dest = dfsDown(lca,destValue,res);
        return source+dest;
    }
};