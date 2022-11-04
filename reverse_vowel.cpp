class Solution {
public:
    bool isVowel(char x){
        char vowels[] = {'a','A','e','E','i','I','o','O','u','U'};
        for(int i=0;i<10;i++){
            if(x==vowels[i]){
                return true;
            }
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<s.size() && !isVowel(s[i])){
                i++;
            }
            while(j>0 && !isVowel(s[j])){
                j--;
            }
            if(i<j){
                swap(s[i++],s[j--]);
            }
        }
        return s;
        
    }
};