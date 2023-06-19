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
    public ListNode rotateRight(ListNode head, int k) {
        int count = 0;
        ListNode cur = new ListNode();
        ListNode prev = new ListNode();
        ListNode first = new ListNode();
        cur = head;
        while(cur!=null){
            count++;
            cur = cur.next;
        }
        if(count ==0 || count ==1){
            return head;
        }
        int rotate = k % count;
        cur = head;
        prev = cur;
        first = head;
        for(int i=0;i<rotate;i++){
            cur = first;
            prev = cur;
            while(cur.next!=null){
                if(cur.next == null){
                    cur.next = first;
                    prev.next = null;
                    first = cur;
                }
                else{
                    prev = cur;
                    cur = cur.next;
                }
            }
            if(cur.next == null){
                    cur.next = first;
                    prev.next = null;
                    first = cur;
                }
        }
        return first;
    }
}