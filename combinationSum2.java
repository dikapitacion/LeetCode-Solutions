class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    void solve(int[] nums,int target,int index,List<Integer> cur){
        if(target<0){
            return;
        }
        else if(target==0){
            ans.add(new ArrayList<>(cur));
            return;
        }
        else{
            for(int i=index;i<nums.length;i++){
                if(i>index && nums[i]==nums[i-1]) continue;
                cur.add(nums[i]);
                solve(nums,target-nums[i],i+1,cur);
                cur.remove(cur.size()-1);
            }
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<Integer> cur = new ArrayList<>();
        Arrays.sort(candidates);
        solve(candidates,target,0,cur);
        return ans;
    }
}