class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> map(58,0);
        for(auto i:s){
            map[i-'A']++;
        }
        bool odd = false;
        int ans=0;

        for(int i=0;i<58;i++){
            if(map[i]%2==0){
                ans += map[i];
            }
            else if(map[i]%2==1){
                    ans += (map[i]/2)*2;
                    odd = true;
            }
        }
        if(odd){ans++;}
        return ans;
    }
};