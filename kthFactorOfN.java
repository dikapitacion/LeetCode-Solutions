class Solution {
    public int kthFactor(int n, int k) {
        int count = 0;
        ArrayList<Integer> factors = new ArrayList<Integer>();
        for(int i=1;i<=n/2;i++){
            if(n%i==0 && count<k){
                factors.add(i);
                count++;
                if(count==k){
                    return(factors.get(k-1));
                }
            }
        }
        factors.add(n);
        count++;
        if(count==k){
            return(factors.get(k-1));
        }
        return(-1);
    }
}