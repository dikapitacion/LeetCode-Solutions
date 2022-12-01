class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char,int> v1;
        int count1=0,count2=0;
        v1.insert({'a',0});v1.insert({'e',0});v1.insert({'i',0});v1.insert({'o',0});v1.insert({'u',0});
        v1.insert({'A',0});v1.insert({'E',0});v1.insert({'I',0});v1.insert({'O',0});v1.insert({'U',0});
        
        int mid = (s.length()/2)-1;
        for(int i=0;i<=mid;i++){
            if(v1.find(s[i])!=v1.end()){
                count1++;
            }
        }
        for(int i=mid+1;i<s.length();i++){
            if(v1.find(s[i])!=v1.end()){
                count2++;
            }
        }
        if(count1==count2){
            return true;
        }
        return false;
    }
};