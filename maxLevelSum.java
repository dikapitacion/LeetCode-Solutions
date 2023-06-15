/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxLevelSum(TreeNode root) {
        int max = Integer.MIN_VALUE;
        int sum = 0;
        int level = 1;
        int maxLevel = 1;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        while(!q.isEmpty()){
            TreeNode cur = q.poll();
            if(cur==null){
                if(q.isEmpty()){
                    if(max<sum){
                    max = sum;
                    maxLevel = level;
                }
                    break;
                }
                q.add(null);
                if(max<sum){
                    max = sum;
                    maxLevel = level;
                }
                sum=0;
                level++;
            }
            else{
                sum+=cur.val;
            if(cur.left!=null){
                q.add(cur.left);
            }
            if(cur.right!=null){
                q.add(cur.right);
            }
            }
            
        }
        return maxLevel;
    }
}