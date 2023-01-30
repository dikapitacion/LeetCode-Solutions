class Solution {
public:
    int tribonacci(int n) {
        int arr[n+1];
        arr[0]=0;
        if(n==0){
            return 0;
        }
        arr[1]=1;
        if(n==1){
            return 1;
        }
        arr[2]=1;
        if(n==2){
            return 1;
        }
        for(int i=3;i<=n;i++){
            int nth= arr[i-2]+arr[i-1]+arr[i-3];
            arr[i]=nth;
        }
        
        return arr[n];
    }
};