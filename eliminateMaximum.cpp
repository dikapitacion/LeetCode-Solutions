class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);
        for(int i=0;i<n;i++){
            time[i] = static_cast<double>(dist[i]) / speed[i];
        }
        sort(time.begin(),time.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            if(time[i]<=i){
                return i;
            }
            ans++;
        }
        return n;
        
    }
};