class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int min = 1000;
        int req = target-'a';
        for(int i=0;i<letters.size();i++){
            if(letters[i]-'a'>req && letters[i]-'a'<min){
                min = letters[i]-'a';
                return min+'a';
            }
        }
        return letters[0];
    }
};