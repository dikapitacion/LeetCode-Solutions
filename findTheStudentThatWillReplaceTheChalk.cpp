class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int i = 0;
        long long sum = 0;
        for(auto c:chalk){
            sum+=c;
        }
        k = k%sum;
        while(chalk[i]<=k){
            k -= chalk[i];
            i++;
        }
        return i;
    }
};