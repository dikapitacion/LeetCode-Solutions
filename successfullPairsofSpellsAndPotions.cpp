class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> pairs(n);
        for(int i=0;i<n;i++){
            int ans=0;
            int low=0,high=m;{
            bool found = false;
                while(low<high){
                    int mid = (low+high)/2;
                    unsigned long long int val = (long long) potions[mid]* (long long)spells[i];
                    if(val<success){
                        low=mid+1;
                    }
                    else if(val>=success){
                        found=true;
                        ans = mid;
                        high = mid;
                    }
                }
                if(found){
                    pairs[i]=m-ans;
                }
                else{
                    pairs[i]=0;
                }
                
            }
        }
        return pairs;
    }
};