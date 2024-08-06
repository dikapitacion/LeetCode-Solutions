class Solution {
public:
    int minimumPushes(string word) {
        vector<int> map(26,0);

        for(auto ch:word){
            map[ch-'a']++;
        }

        sort(map.begin(),map.end(),greater<int>());
        // reverse(map.begin(),map.end());
        int ans = 0;
        for(int i=0;i<26;i++){
            if(i<8) ans+=map[i];
            else if (i>=8 && i<16) ans+=map[i]*2;
            else if(i>=16 && i<24) ans+=map[i]*3;
            else ans+=map[i]*4;
        }

        return ans;
    }
};