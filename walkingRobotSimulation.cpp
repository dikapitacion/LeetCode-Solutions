class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0;
        vector<bool> dirs = {true,false,false,false};// up,right,down,left
        vector<vector<int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
        set<pair<int,int>> s;

        for(auto obstacle:obstacles){
            s.insert({obstacle[0],obstacle[1]});
        }

        int index = 0;
        int ans = 0;

        for(auto command:commands){
            if(command>=0){
                for(int i=0;i<command;i++){
                    x+=moves[index][0];
                    y+=moves[index][1];
                    if(s.find({x,y}) != s.end()){ 
                        x-=moves[index][0];
                        y-=moves[index][1];
                        break;
                    }
                }

                ans = max(ans,(x*x + y*y));
            }
            else if(command == -1){
                dirs[index] = false;
                index = (index+1)%4;
                dirs[index] = true;
            }
            else if(command == -2){
                dirs[index] = false;
                index = (index+3)%4;
                dirs[index] = true;
            }
        }

        return ans;
    }
};