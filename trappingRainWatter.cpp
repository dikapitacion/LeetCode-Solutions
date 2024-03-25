class Solution {
public:
    int trap(vector<int>& height) {
        int m = 0,n=height.size();
        vector<int> pre;
        vector<int> suf(n,0);
        for(auto i:height){
            m = max(m,i);
            pre.push_back(m);
        }
        m=0;
        for(int i=n-1;i>=0;i--){
            m = max(m,height[i]);
            suf[i] = m;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int cap = min(pre[i],suf[i]) - height[i];
            if(cap>0){
                ans += cap;
            }
        }
        return ans;
    }
};