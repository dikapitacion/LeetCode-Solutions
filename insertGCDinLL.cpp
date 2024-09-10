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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        ListNode* next = head->next;

        while(next){
            int gcd = __gcd(cur->val,next->val);
            ListNode* GCD = new ListNode(gcd);
            cur->next = GCD;
            GCD->next = next;
            cur = next;
            next = next->next;
        }
        return head;
    }
};