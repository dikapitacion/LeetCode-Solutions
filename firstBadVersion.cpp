// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long firstBad;
        long long l=1,h=n;
        if(isBadVersion(n)){
            firstBad = n;
        }
        while(l<h){
            int mid = l+(h-l)/2;
            if(isBadVersion(mid)){
                firstBad = mid;
                h = mid;
            }
            else{
                l = mid+1;
            }
        }
        return firstBad;
    }
};