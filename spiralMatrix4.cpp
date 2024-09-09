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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int>(n,-1));

        int right = n-1,left = 0;
        int bottom = m-1,top = 0;


        // while(head && right>=left && top<=bottom){
        //     for(int i=left;i<=right && head;i++){
        //         int val = -1;
        //         if(head){
        //             val = head->val;
        //             head = head->next;
        //         }
        //         res[top][i] = val;
        //     }
        //     top++;

        //     for(int i=top;i<=bottom;i++){
        //         int val = -1;
        //         if(head){
        //             val = head->val;
        //             head = head->next;
        //         }
        //         res[i][right] = val;

        //     }
        //     right--;
            
        //     for(int i=right;i>=left;i--){
        //         int val = -1;
        //         if(head){
        //             val = head->val;
        //             head = head->next;
        //         }
        //         res[bottom][i] = val;

        //     }
        //     bottom--;

        //     for(int i=bottom;i>=top;i--){
        //         int val = -1;
        //         if(head){
        //             val = head->val;
        //             head = head->next;
        //         }
        //         res[i][left] = val;

        //     }
        //     left++;
        // }
        while(right >= left && top <= bottom) {
            for(int i = left; i <= right && head; i++) {
                res[top][i] = head->val;
                head = head->next;
            }
            top++;

            for(int i = top; i <= bottom && head; i++) {
                res[i][right] = head->val;
                head = head->next;
            }
            right--;
            
            for(int i = right; i >= left && head; i--) {
                res[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;

            for(int i = bottom; i >= top && head; i--) {
                res[i][left] = head->val;
                head = head->next;
            }
            left++;
        }


        return res;
    }
};