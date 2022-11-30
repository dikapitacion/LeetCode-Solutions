class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> val;
        set<int> check;
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(val[arr[i]]>=1){
                val[arr[i]]++;
            }
            else{
                val[arr[i]] = 1;
            }
        }
        for(auto it:val){
            check.insert(it.second);
            count++;
        }
        if(check.size() == count){
            return true;
        }
        else{
            return false;
        }
        
    }
};