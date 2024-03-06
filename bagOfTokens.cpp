class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start = 0;
        int end = tokens.size()-1;
        int ans = 0;
        
        if(end<0 || tokens[start]>power){
            return ans;
        }
        while(start<=end){
            if(start==end){
                if(power>=tokens[start]){
                    ans++;
                }
                start++;
            }
            else if(tokens[start]<=power){
                power-=tokens[start];
                start++;
                ans++;
            }
            
            else{
                power+=tokens[end];
                end--;
                ans--;
            }
        }
        return ans;
    }
};