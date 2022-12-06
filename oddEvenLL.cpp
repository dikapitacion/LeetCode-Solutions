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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* p = odd;
        ListNode* q = even;
        while(p->next && q->next){
            p->next = p->next->next;
            p = p->next;
            q->next = q->next->next;
            q = q->next;
        }
        p->next = even;
        return odd;
    }
};