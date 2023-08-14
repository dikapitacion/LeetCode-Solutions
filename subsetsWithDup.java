class Solution {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    void solve(int[] nums,List<Integer> arr,int index){
        if(index >= nums.length){
            ans.add(new ArrayList(arr));
            return;
        }
        else{
            //include
            int val = nums[index];
            arr.add(val);
            solve(nums,arr,index+1);
            //exclude
            while(index+1<nums.length && nums[index] == nums[index+1]){
                index++;
            }
            arr.remove(arr.size()-1);
            solve(nums,arr,index+1);
        }

    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<Integer> arr = new ArrayList<>();
        solve(nums,arr,0);
        return ans;
    }
}