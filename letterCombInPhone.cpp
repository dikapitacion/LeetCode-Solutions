class Solution {
public:
    void solve(vector<string>& keys,vector<string>& ans, string& cur,vector<int>& arr,int pos,int n){
        if(pos == n){
            ans.push_back(cur);
            return;
        }
        string check = keys[arr[pos]];
        for(int i=0;i<check.size();i++){
            cur+=check[i];
            solve(keys,ans,cur,arr,pos+1,n);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        int n = digits.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(digits[i]-'0');
        }
        string check = "";
        solve(keys,ans,check,arr,0,n);
        if(n==0){
            return {};
        }
        return ans;
    }
};