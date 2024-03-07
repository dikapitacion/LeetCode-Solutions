class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int end = s.size()-1;
        int ans = end+1;
        while(start<end){
            if(s[start] != s[end]){
                return ans;
            }
            else{
                char cur = s[start];

                while(s[start] == cur){
                    if(start==end){
                        return 0;
                    }
                    start++;
                    ans--;
                }
                while(s[end] == cur){
                    end--;
                    ans--;
                }

            }
        }
        if(start==end){
            return 1;
        }
        return 0;
    }
};