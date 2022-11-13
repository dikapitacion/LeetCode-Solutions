class Solution {
public:
    int firstUniqChar(string s) {
        int flag;
        for(int i=0;i<s.length();i++){
            flag = 0;
            for(int j=0;j<s.length();j++){
                if(s[i]==s[j] && i!=j){
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                return i;
            }
        }
        return -1;
    }
};