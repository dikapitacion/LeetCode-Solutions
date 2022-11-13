class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string temp,ans;
        int i=0,j,n=s.length();
        while(i<n){
            if(s[i]==' ' && i<n){
                i++;
            }
            else{
                j=i;
                while(s[j]!=' ' && j<n){
                    j++;
                }
                temp = s.substr(i,j-i);
                arr.push_back(temp);
                i = j;
            }
        }
        n = arr.size()-1;
        ans = arr[n] +' ';
        n--;
        while(n>=0){
            ans+=arr[n];
            ans+=' ';
            n--;
        }
        ans.pop_back();
        return ans;
    }
};