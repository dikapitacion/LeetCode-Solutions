class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        vector<int> chars(26,0);
        for(int i=0;i<s.size();i++){
            chars[s[i]-'a']++;
        }
        for(auto str:order){
            int pos = str-'a';
            while(chars[pos]>0){
                ans+=str;
                chars[pos]--;
            }
        }

        for(int i=0;i<26;i++){
            while(chars[i]>0){
                ans+=i+'a';
                chars[i]--;
            }
        }
        return ans;
    }
};