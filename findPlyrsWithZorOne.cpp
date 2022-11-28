class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> los;
        vector<int> no,one;
        for(auto i : matches){
            if(!los.count(i[0])){
                los[i[0]] = 0;
            }
            los[i[1]]++;
        }
        for(auto[k,l] : los){
            if(l==0){
                no.push_back(k);
            }
            if(l==1){
                one.push_back(k);
            }
        }
        return {no,one};
    }
};