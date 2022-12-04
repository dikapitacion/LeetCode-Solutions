class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long left=0,min=INT_MAX,right=0;
        long long lmin,rmin,dif,ans;
        if(nums.size()==1){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            right+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            left+=nums[i];
            right-=nums[i];
            if(i==nums.size()-1){
                lmin=left/(i+1);
                rmin=0;
            }
            else{
                lmin = left/(i+1);
                rmin = right/(nums.size()-1-i);
            }
            
            if(rmin>=lmin){
                dif = rmin-lmin;
            }
            else{
                dif = lmin-rmin;
            }
            if(dif<min){
                min = dif;
                ans = i;
            }
        }
        return ans;
    }
};