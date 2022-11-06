class Solution {
public:
    int reverse(int x) {
        unsigned int y = x;
        long long int p=0;
        if(x>0){
            while(y>0){
            int r;
            r = y%10;
            p = p*10 + r;
            y = y/10;
            }
        }
        else{
            // y = (-1*x);
            if(x==-2147483648){
                while(y>0){
                    int r;
                    r = y%10;
                    p = p*10 + r;
                    y = y/10;
                }
                p = -1*p;
            }
            else{
                y=-x;
                while(y>0){
                    int r;
                    r = y%10;
                    p = p*10 + r;
                    y = y/10;
                }
                p = -1*p;
            }
        }
        if(p<2147483647 && p>-2147483648){
            return p;
        }
        else{
            return 0;
        }
    }
        
};