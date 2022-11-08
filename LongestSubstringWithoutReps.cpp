class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[127] = {0};
        int cur = 0,max = 0;
        for(int i=0;i<s.length();i++){
            arr[int(s[i])]++;
            if(arr[int(s[i])]>1){
                fill_n (arr, 127, 0);
                i = i-cur;
                cur = 0;
            }
            else{
                cur++;
                if(cur>max){
                    max = cur;
                }
            }
        }
        return max;
    }
};