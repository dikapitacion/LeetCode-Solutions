class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            int y = x;
            long long int p=0;
            while(y>0){
                int r;
                r = y%10;
                p = p*10 + r;
                y = y/10;
            }   
            if(p==x){
                return true;
            }
            else{
                return false;
            }
        }
    }
};