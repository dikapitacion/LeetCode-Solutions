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
    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;
        ListNode ans = new ListNode();
        PriorityQueue<ListNode> pq = new PriorityQueue<>(Comparator.comparingInt(node -> node.val));
        int i = 0;
        while(i<k){
            ListNode cur = lists[i];
            while(cur!=null){
                pq.add(cur);
                ListNode next = cur.next;
                cur.next = null;
                cur = next;
            }
            i++;
        }
        ListNode tr = ans;
      while(!pq.isEmpty()){
          tr.next = pq.poll();
          tr = tr.next;
      }
      return ans.next;
    }
}