class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0,lcount=0;
        for(int i =0;i<s.size();i++){
            if(s[i]==' '){
                if(count!=0){
                    lcount = count;
                }
                count = 0;
            }
            else{
                count++;
                lcount = count;
            }
        }
        return lcount;
    }
};