class Solution {
public:
    int maximum69Number (int num) {
        vector<int> a;
        while(num>0){
            int r = num%10;
            a.push_back(r);
            num = num/10;
        }
        int i = a.size()-1;
        for(i;i>=0;i--){
            if(a[i]==6){
                a[i]=9;
                break;
            }
        }
        int res=0,n=1;
        for(int j=0;j<a.size();j++){
            res = res +a[j]*n;
            n = n*10;
        }
        return res;
    }
};