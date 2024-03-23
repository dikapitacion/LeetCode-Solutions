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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(cur && next){
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if(!head->next){
            return;
        }

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }


        ListNode* l2 = reverse(slow->next);
        slow->next = NULL;
        ListNode* l1 = head;
        while(l1 && l2){
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;
            l1->next = l2;
            l2->next = t1;
            l1 = t1;
            l2 = t2;
        }
    }
};