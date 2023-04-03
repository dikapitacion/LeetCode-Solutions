class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        sort(people.begin(),people.end());
        int l = 0;
        int r = people.size()-1;
        while(l<=r){
            int sum = people[l]+people[r];
            if(sum<=limit){
                l++;
                r--;
                ans++;
            }
            else{
                ans++;
                r--;
            }
        }
        return ans;
    }
};