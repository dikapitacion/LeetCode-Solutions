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
    TreeNode* solve(vector<int>& nums,int start,int end){
        if(start>end){
            return NULL;
        }

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(nums,start,mid-1);
        root->right = solve(nums,mid+1,end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // vector<int> nums;
        // while(head!=NULL){
        //     nums.push_back(head->val);
        //     head = head->next;
        // }
        // return solve(nums,0,nums.size()-1);
        if (!head) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        if (slow == head) return root;
        prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};