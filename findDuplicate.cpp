class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,0);

        for(int i=0;i<n;i++){
            arr[nums[i]]++;
            if(arr[nums[i]]>=2){
                return nums[i];
            }
        }
        return 0;
    }
};