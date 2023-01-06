class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ic = 0,i=0;
        while(coins>0 && ic<costs.size()){
            coins -= costs[i];
            i++;
            if(coins>=0){
                ic++;
            }
        }
        return ic;
    }
};