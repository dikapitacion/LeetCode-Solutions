class Solution {
    public void sortColors(int[] nums) {
        int[] table = new int[3];
        for(int num:nums){
            table[num]++;
        }
        int zero = table[0];
        int one = table[1];
        int two = table[2];
        int i = 0;
        while(zero>0){
            nums[i]=0;
            i++;
            zero--;
        }
        while(one>0){
            nums[i] = 1;
            i++;
            one--;
        }
        while(two>one){
            nums[i] = 2;
            i++;
            two--;
        }
    }
}