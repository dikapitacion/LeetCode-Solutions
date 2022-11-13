class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        for(char ch : s)
            count[ch - 'a']++;
        
        for(char ch : t)
            if(count[ch - 'a']-- <= 0)
                return false;
        if(s.length()!=t.length()){
            return false;
        }
        return true;
    }
};