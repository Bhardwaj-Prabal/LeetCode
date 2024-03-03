class Solution {
public:

    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        vector<bool> visited(rooms.size(),0);
        queue<int> mp;
        mp.push(0);
        

        while(!mp.empty()){
            int top=mp.front();
            mp.pop();
            visited[top]=true;

            for(auto x:rooms[top]){
                if(visited[x]==false){
                    mp.push(x);
                }
            }
        }

        for(int i=0;i<visited.size();i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};