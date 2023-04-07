class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int start = values[0],n = values.size();
        int score = 0;
        for(int i=1;i<n;i++){
            int cur = values[i]-i+start;
            score = max(score,cur);
            start = max(start,values[i]+i);
        }
        return score;
    }
};