class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> w1(26,0),w2(26,0);
        set<char> s1,s2;
        for(auto i:word1){
            w1[i-'a']++;
            s1.insert(i);
        }
        for(auto i:word2){
            w2[i-'a']++;
            s2.insert(i);
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        if(w1==w2&&s1==s2){
            return true;
        }
        return false;
    }
};