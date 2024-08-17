class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> m;
        m[5] = 0;
        m[10] = 0;
        m[20] = 0;
        for(auto bill:bills){
            m[bill]++;
            if(bill==10){
                if(m[5]<=0) return false;
                m[5]--;
            }
            if(bill==20){
                if(m[10]<=0){
                    if(m[5]<=2) return false;
                    else {m[5]-=3;continue;}
                }
                if(m[5]<=0) return false;

                m[10]--;
                m[5]--;
            }
        }
        return true;
    }
};