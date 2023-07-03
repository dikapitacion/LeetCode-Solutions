class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void solve(List<Integer> nums, int index){
        if(index==nums.size()-1){
            if(!ans.contains(nums)){
                ans.add(new ArrayList(nums));
                return;
            }
        }
        for(int i=index;i<nums.size();i++){
            Collections.swap(nums,i,index);
            solve(nums,index+1);
            Collections.swap(nums,i,index);
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        List<Integer> temp = new ArrayList<>();
        for(int num:nums){
            temp.add(num);
        }
        solve(temp,0);
        return ans;
    }
}