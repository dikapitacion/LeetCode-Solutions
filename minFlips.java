class Solution {

    public int minFlips(int a, int b, int c) {
        
        // make sure all strings are equal
        int highest = Math.max(a,Math.max(b,c));
        String high = Integer.toBinaryString(highest);
        int desiredLength = high.length();
        String a1 = String.format("%" + desiredLength + "s", Integer.toBinaryString   (a)).replace(' ', '0');
        String b1 = String.format("%" + desiredLength + "s", Integer.toBinaryString   (b)).replace(' ', '0');
        String c1 = String.format("%" + desiredLength + "s", Integer.toBinaryString   (c)).replace(' ', '0');
        //calculate flips
        int flips = 0;
        for(int i = desiredLength-1;i>=0;i--){
            if(a1.charAt(i)=='1'){
                if(c1.charAt(i)=='0'){
                    if(b1.charAt(i)=='1'){
                        flips+=2;
                    }
                    else{
                        flips+=1;
                    }
                }
            }
            else{
                if(c1.charAt(i)=='0'){
                    if(b1.charAt(i)=='1'){
                        flips+=1;
                    }
                }
                else{
                    if(b1.charAt(i)=='0'){
                        flips+=1;
                    }
                }
            }
        }
        return flips;
    }
}