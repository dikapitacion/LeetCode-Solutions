class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set<string> st;
        for(auto i: wordList){
            st.insert(i);
        }
        st.erase(beginWord);
        while(!q.empty()){
            pair<string,int> front = q.front();
            q.pop();
            string temp = front.first;
            int count = front.second;

            if(temp == endWord){
                return count;
            }

            for(int i=0;i<temp.size();i++){
                char ori = temp[i];
                for(char j='a';j<='z';j++){
                    temp[i] = j;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp,count+1});
                    }
                }
                temp[i] = ori;
            }

        }
        return 0;
    }
};