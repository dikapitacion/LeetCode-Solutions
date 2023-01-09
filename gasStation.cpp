class Solution {
public:
    int sum(vector<int> arr){
        int s=0;
        for(auto i:arr){
            s+=i;
        }
        return s;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur=0,g=0,c=0;
        int start = 0;
        if(sum(cost)<=sum(gas)){
            for(int i;i<gas.size();i++){
                if(cur<0){
                    cur = 0;
                    start = i;
                }
                cur += gas[i]-cost[i];
            }
            return start;
        }
        else{
            return -1;
        }
    }
};