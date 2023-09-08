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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(left==right){
            return head;
        }
        // ListNode cur = head;
        // ListNode prev = head;
        // ListNode slow = head;
        // int i = 0;
        // if(right==2){
        //     cur = cur.next;
        //     slow = cur.next;
        //     cur.next = prev;
        //     prev.next = slow;
        //     return cur;
        // }
        // while(i<left){
        //     slow = prev;
        //     prev = cur;
        //     cur = cur.next;
        //     i++;
        // }
        // ListNode start = prev;
        // while(i>=left && i<right){
        //     if(cur.next!=null){
        //         ListNode ahead = cur.next;
        //         cur.next = prev;
        //         prev = cur;
        //         cur = ahead;
        //         i++;
        //     }
        //     else{
        //         slow.next = cur;
        //         cur.next = prev;
        //         prev.next = null;
        //         i++;
        //         return head;
        //     }
        // }
        // start.next = cur;
        // slow.next = prev;
        // return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev.next;
        }

        ListNode cur = prev.next;

        for (int i = 0; i < right - left; i++) {
            ListNode temp = cur.next;
            cur.next = temp.next;
            temp.next = prev.next;
            prev.next = temp;
        }

        return dummy.next;   
    }
}