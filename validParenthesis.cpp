class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0){
            return false;
        }
        stack<char> stack;
        for(auto i:s){
            if(i=='(' || i=='[' || i=='{'){
                stack.push(i);
            }
            else if(i==')'){
                if(stack.empty()){
                    return false;
                }
                if(stack.top()=='('){
                        stack.pop();
                }
                else{
                    return false;
                }
            }
            else if(i=='}'){
                if(stack.empty()){
                    return false;
                }
                if(stack.top()=='{'){
                        stack.pop();
                }
                else{
                    return false;
                }
            }
            else if(i==']'){
                if(stack.empty()){
                    return false;
                }
                if(stack.top()=='['){
                        stack.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stack.empty();
    }
};