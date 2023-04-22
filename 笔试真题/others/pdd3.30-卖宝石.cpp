#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
typedef pair<int, int> PII;
char typeArr[N];        // 关卡类型 1-n
int bsType[N];          // 关卡对应的宝石奖励
int money = 0;          // 最终获取的货币数
int n, m;               // 关卡数，宝石种类

// 注意，只能拥有一个宝石

int main(){
    scanf("%d %d", &n, &m);
    int shopNum = 0;
    char c;
    int a,b;
    vector<PII> shop;           // 商店需要宝石-货币, 保证顺序
    vector<int> baoShi(m+1);    // 拥有i类型宝石的数量
    for(int i=1; i<=n; ++i){
        cin>>c;
        typeArr[i] = c;
        if(c=='b'){
            cin>>bsType[i];
        }else{
            cin>>a>>b;
            shop.push_back({a,b});
        }
    }
    int j = 0;       // 标记商店顺序
    int totalbs= 0;
    unordered_map<int, int> umap;
    for(int i=1; i<=n; ++i){
        if(typeArr[i] == 'b'){      // 打败boss，获得宝石
            ++baoShi[bsType[i]];
            ++totalbs;
        }else{
            if(totalbs<1) continue;
            // 遇见一段商人
            umap.clear();
            while(i<=n && typeArr[i] == 'm'){
                if(umap.count(shop[j].first)){
                    umap[shop[j].first] = max(umap[shop[j].first], shop[j].second);
                }else{
                    umap[shop[j].first] = shop[j].second;
                }
                j++;
                i++;
            }
            // 卖哪一个
            int maxVal = 0;
            for(int k=1; k<=m; ++k){
                if(baoShi[k]>0){
                    maxVal = max(maxVal, umap[k]);
                }
            }
            money += maxVal;

            // 置空宝石
            for(int k=0; k<m+1; ++k){
                baoShi[k]=0;
            }
            totalbs=0;
        }
    }
    cout<<money<<endl;
    return 0;
}