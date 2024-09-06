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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for(auto num:nums){
            s.insert(num);
        }

        ListNode* next = nullptr;
        ListNode* cur = head;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* prev = ans;

        while(cur){
            if(s.find(cur->val) != s.end()){
                next = cur->next;
                cur->next = nullptr;
                cur = next;
                prev->next = cur;
            }
            else{
                prev->next = cur;
                cur = cur->next;
                prev = prev->next;
            }
        }

        
        return ans->next;
    }
};