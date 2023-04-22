#include <bits/stdc++.h>
using namespace std;

// 9%

const int N = 110;
int n, x, y;       // n件商品，x元，y张折扣券
typedef pair<int, int> PII; 
pair<PII,bool> obj[N];    // 商品的原价-折扣价,是否使用过
int maxCnt=0, money=0;    // 最多购买的商品，最少花费的钱

// 按照min(原价，折扣价排序)
bool cmp(pair<PII,bool> p1, pair<PII,bool> p2){
    int min1 = min(p1.first.first, p1.first.second);
    int min2 = min(p2.first.first, p2.first.second);
    if(min1 <= min2){
        return true;
    }else{
        return false;
    }
}

// 按照原价排序
bool cmp2(pair<PII,bool> p1, pair<PII,bool> p2){
    int min1 = p1.first.first;
    int min2 = p2.first.first;
    if(min1 <= min2){
        return true;
    }else{
        return false;
    }
}

int main(){
    scanf("%d %d %d", &n, &x, &y);
    for(int i=1;i<=n;++i){
        scanf("%d %d", &obj[i].first.first, &obj[i].first.second);
    }
    sort(obj+1, obj+1+n,cmp);
    // 使用折扣券
    for(int i=1; i<=n; ++i){
        if(y>0){
            int price = min(obj[i].first.first, obj[i].first.second);
            if(x - price < 0){
                break;
            }
            x -= price;
            maxCnt++;
            money+=price;
            obj[i].second = true; // 标记使用过
            y--;
        }else{
            break;
        }
    }
    // 重新排序，按原价排
    sort(obj+1, obj+1+n,cmp2);
    for(int i=1;i<=n;++i){
        if(obj[i].second == 0){      // 没有使用过
            int price = obj[i].first.first;
            if(x - price < 0){
                break;
            }
            x -= price;
            maxCnt++;
            money+=price;
        }
    }
    cout<<maxCnt<<" "<<money<<endl;
    return 0;
}