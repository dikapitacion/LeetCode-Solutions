class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        vector<int> ans(t.size(),0);
        for(int i=0;i<t.size();i++){
            while(!s.empty() && t[s.top()]<t[i]){
                int j=s.top();
                s.pop();
                ans[j] = i-j;
            }
            s.push(i);
        }
        return ans;
    }
};