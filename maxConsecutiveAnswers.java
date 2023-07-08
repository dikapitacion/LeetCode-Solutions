class Solution {
    public int solve(String ans,int k,char c){
        int i=0,j=0,count=0,n=ans.length();
        int max=0;
        while(j<n){
            if(ans.charAt(j)==c){
                count++;
            }
            while(i<n && count>k){
                if(ans.charAt(i)==c){
                    count--;
                }
                i++;
            }
            max = Math.max(j-i+1,max);
            j++;
        }
        return max;
    }
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int m1 = solve(answerKey,k,'T');
        int m2 = solve(answerKey,k,'F');
        return Math.max(m1,m2);
    }
}