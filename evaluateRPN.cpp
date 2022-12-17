class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stack;
        int ans=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                stack.push(stoi(tokens[i]));
            }
            else if(tokens[i]=="+"){
                long long s1 = stack.top();
                stack.pop();
                long long s2 = stack.top();
                stack.pop();
                long long sum = s1+s2;
                stack.push(sum);
            }
            else if(tokens[i]=="-"){
                long long s1 = stack.top();
                stack.pop();
                long long s2 = stack.top();
                stack.pop();
                long long dif = s2-s1;
                stack.push(dif);
            }
            else if(tokens[i]=="/"){
                long s1 = stack.top();
                stack.pop();
                long  s2 = stack.top();
                stack.pop();
                long long div = s2/s1;
                stack.push(div);
            }
            else if(tokens[i]=="*"){
                long long s1 = stack.top();
                stack.pop();
                long long s2 = stack.top();
                stack.pop();
                long long mul = s1*s2;
                stack.push(mul);
            }
        }
        return stack.top();
    }
};