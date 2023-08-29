class Solution {
    public int bestClosingTime(String customers) {
        int cur = 0;
        for(char c : customers.toCharArray()){
            if(c=='Y'){
                cur++;
            }
        }
        int minPen = cur;
        int minH = 0;
        for(int i=0;i<customers.length();i++){
            char ch = customers.charAt(i);
            if(ch=='Y'){
                cur--;
            }
            else{
                cur++;
            }

            if(cur<minPen){
                minPen = cur;
                minH = i+1;
            }
        }
        return minH;
    }
}