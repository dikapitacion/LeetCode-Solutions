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
        map<int,int> m;
        ListNode* h1 = head;
        ListNode* h=head;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(h1){
            m[h1->val]++;
            h1 = h1->next;
        }

        while(h){
            if(m[h->val]==1){
                cur->next = new ListNode(h->val);
                cur = cur->next;
            }
            h = h->next;
        }
        
        return dummy->next;
    }
};