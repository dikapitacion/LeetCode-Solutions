class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    void solve(int[] nums,int target,List<Integer> cur,int index){
        if(target<0){
            return;
        }
        else if (target==0){
            ans.add(new ArrayList<>(cur));
        }
        else{
            for(int i=index;i<nums.length;i++){
                cur.add(nums[i]);
                solve(nums,target-nums[i],cur,i);
                cur.remove(cur.size()-1);
            }
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> cur = new ArrayList<>();
        solve(candidates,target,cur,0);
        return ans;
    }
}