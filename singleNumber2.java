class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int num:nums){
            if(map.containsKey(num)){
                int val = map.get(num)+1;
                map.put(num,val);
            }
            else{
                map.put(num,1);
            }
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> e : map.entrySet()){
            if(e.getValue()==1){
                ans = e.getKey();
            }
        }
        return ans;
    }
}