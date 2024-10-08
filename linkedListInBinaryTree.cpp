/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* head,TreeNode* node){
        if(!head) return true;
        if(!node) return false;

        bool res = false;

        if(node->val == head->val){
            res |= dfs(head->next,node->left);
            res |= dfs(head->next,node->right);
        }
        return res;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;

        bool res = dfs(head,root);

        res |= isSubPath(head,root->left);
        res |= isSubPath(head,root->right);

        return res;
    }
};