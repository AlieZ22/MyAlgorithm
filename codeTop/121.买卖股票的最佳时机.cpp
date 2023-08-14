#include <iostream>
#include <vector>
using namespace std;

/*
* @method: 一遍遍历，每天记录当前最低点，每天计算获利
*/

class Solution_hot121 {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int maxProf = 0;
        for(int i=0; i<prices.size(); ++i){
            if(minVal > prices[i]){
                minVal = prices[i];
            }
            maxProf = max(maxProf, prices[i] - minVal);
        }
        return maxProf;
    }
};