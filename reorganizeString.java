class Solution {
    class Pair {
        int freq;
        char ch;
        
        Pair(int freq, char ch) {
            this.freq = freq;
            this.ch = ch;
        }
    }
    public String reorganizeString(String s) {
        int[] map = new int[26];
        int n = s.length();
        Arrays.fill(map,0);
        for(int i=0;i<n;i++){
            map[s.charAt(i)-'a']++;
            if(map[s.charAt(i)-'a']>((n+1)/2)){
                return "";
            }
        }
        PriorityQueue<Pair> p = new PriorityQueue<>((a, b) -> b.freq - a.freq);
        for(int i=0;i<26;i++){
            if(map[i]!=0){
                p.offer(new Pair(map[i],(char) (i+'a')));
            }
        }
        StringBuilder ans = new StringBuilder();
        while(p.size()>=2){
            Pair p1 = p.poll();
            Pair p2 = p.poll();
            ans.append(p1.ch);
            ans.append(p2.ch);
            if(p1.freq>1){
                p.offer(new Pair(p1.freq-1,p1.ch));
            }
            if (p2.freq > 1) {
                p.offer(new Pair(p2.freq - 1, p2.ch));
            }
        }
        if (!p.isEmpty()) {
            ans.append(p.poll().ch);
        }
        return ans.toString();
    }
}