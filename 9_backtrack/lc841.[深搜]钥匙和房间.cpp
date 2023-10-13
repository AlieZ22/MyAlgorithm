#include <iostream>
#include <vector>
using namespace std;

class Solution841 {
public:
    void getRoom(vector<vector<int>>& rooms, int idx, vector<bool>& canFind){
        // 访问idx号房间
        if(canFind[idx]) return;      // 访问过就不访问了
        canFind[idx] = true;

        // 拿到钥匙
        int m = rooms[idx].size();
        for(int i=0; i<m; ++i){
            int key = rooms[idx][i];
            getRoom(rooms, key, canFind);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> canFind(n, false);

        getRoom(rooms, 0, canFind);

        // 看canFind是否全为1
        for(const auto& sign: canFind){
            if(!sign){
                return false;
            }
        }
        return true;
    }
};