class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(n<=numRows || numRows==1) return s;
        bool flag = false;
        vector<string> rows(numRows,"");
        int curRow = 0;
        
        for(auto i:s){
            rows[curRow]+=i;

            if(curRow==0 || curRow==numRows-1) flag = !flag;

            curRow += flag?1:-1;
        }

        string ans;
        for(auto& s:rows){
            ans+=s;
        }
        return ans;
    }
};