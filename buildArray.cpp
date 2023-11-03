class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int m = target.size();
        int cur = 1;
        for(int i=0;i<m;i++){
            while(cur < target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                cur++;
            }
            ans.push_back("Push");
            cur++;
        }
        
        return ans;
    }
};