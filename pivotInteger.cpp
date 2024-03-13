class Solution {
public:
    int pivotInteger(int n) {
        int s=1,f=n;
        int sum1=0,sum2=0;
        while(s<=n){
            if(sum1==sum2 && s==n){
                return s;
            }
            if(sum1>sum2){
                sum2+=n--;
            }
            else{
                sum1+=s++;
            }
        }
        return -1;
    }
};