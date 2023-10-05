class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<Integer>();
        HashMap<Integer, Integer> map = new HashMap<>();
        int min = nums.length/3;
        if(nums.length<3){
            for(int i: nums){
                if(map.containsKey(i)){
                    continue;
                }
                map.put(i,1);
                ans.add(i);
            }
            
            return ans;
        }
        for(int i:nums){
            if(map.containsKey(i)){
                int cur = map.get(i);
                cur++;
                map.put(i,cur);
            }
            else{
                map.put(i,1);
            }
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
    // Get the key and value from the entry
    Integer key = entry.getKey();
    Integer value = entry.getValue();

    // Check if the value is greater than 3
    if (value > min) {
        // Add the value to the list
        ans.add(key);
    }
}
        return ans;
    }
}