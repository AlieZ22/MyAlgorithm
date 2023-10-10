#include <iostream>
#include <vector>
using namespace std;

class Solution605 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<bool> canPlace(flowerbed.size(), true);
        for(int i=0; i<flowerbed.size(); ++i){
            if(flowerbed[i]){
                canPlace[i] = false;
                if(i-1 >= 0) canPlace[i-1] = false;
                if(i+1 <= flowerbed.size()) canPlace[i+1] = false;
            }
        }
        return place(canPlace, n, 0);
    }
    
    bool place(vector<bool>& canPlace, int n, int idx){
        if(n == 0) return true;
        for(int i=idx; i<canPlace.size(); ++i){
            if(canPlace[i] == true){
                canPlace[i] = false;
                if(i-1 >= 0) canPlace[i-1] = false;
                if(i+1 <= canPlace.size()) canPlace[i+1] = false;
                return place(canPlace, n-1, i+1);
            }
        }
        return false;
    }
};