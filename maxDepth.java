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
    int solve(TreeNode root){
        if(root==null){
            return 0;
        }
        return Math.max(solve(root.right),solve(root.left))+1;
    }
    public int maxDepth(TreeNode root) {
        int ans = solve(root);
        return ans;
    }
}