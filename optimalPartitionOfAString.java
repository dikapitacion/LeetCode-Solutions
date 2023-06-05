class Solution {
    public int partitionString(String s) {
        String sub = "";
        int count=0,i=0;
        while (i<s.length()){
            if(sub.contains(String.valueOf(s.charAt(i)))){
                count++;
                sub = "";
            }
            else{
                sub = sub.concat(String.valueOf(s.charAt(i)));
                i++;
            }
        }
        return count+1;
    }
}