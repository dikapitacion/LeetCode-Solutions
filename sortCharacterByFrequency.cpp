class Solution {
public:
    void reverse(string& str){
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
    string frequencySort(string s) {
        map<char,int> m1;
        map<int,string> m2;
        string ans;
        for(auto i:s){
            if(m1.find(i)==m1.end()){
                m1[i] = 1;
            }
            else{
                m1[i]++;
            }
        }
        for(auto i:m1){
            m2[i.second] += string(i.second,i.first);
        }
        for(auto i:m2){
            ans.append(i.second);
        }
        reverse(ans);
        return ans;
    }
};