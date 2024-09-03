class Solution {
public:

    int help(string nums){
        int sum = 0;
        for(auto n:nums){
            sum += (n-'0');
        }
        return sum;
    }
    int getLucky(string s, int k) {
        string nums;
        for(auto i:s){
            nums += to_string(i - 'a' + 1);
        }
        
        for(int i=0;i<k;i++){
            int cur = help(nums);
            nums = to_string(cur);
        }

        return stoi(nums);
    }
};