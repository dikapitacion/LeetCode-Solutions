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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        if(!p){
            return head;
        }
        ListNode* q=p->next;
        while(p && q){
            if(p->val == q->val){
                q = q->next;
                if(!q){
                    p->next = nullptr;
                }
            }
            else{
                p->next = q;
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};