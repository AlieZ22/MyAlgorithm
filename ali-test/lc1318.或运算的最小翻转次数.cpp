class Solution1318 {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a||b||c){
            // 取每个数的最后一位
            int wa = a&1;
            int wb = b&1;
            int wc = c&1;
            if(wc==0){
                cnt += wa+wb;
            }else{
                if(wa+wb==0){
                    ++cnt;
                }
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return cnt;
    }
};