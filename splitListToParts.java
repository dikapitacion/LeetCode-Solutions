/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int count = 0;
        ListNode cur = head;
        while(cur!=null){
            cur = cur.next;
            count++;
        }
        cur = head;
        int size = count/k;
        int rem = count%k;
        ListNode[] ans = new ListNode[k];
        for(int i=0;i<k;i++){
            ListNode first = cur;
            for(int j=0;j<size+(i<rem ? 1:0)-1;j++){
                if(cur!=null){
                    cur = cur.next;
                }
            }
            if(cur!=null){
                ListNode prev = cur;
                cur = cur.next;
                prev.next = null;
            }
            ans[i] = first;
        }
        return ans;
    }
}