#include <bits/stdc++.h>
using namespace std;

int C, N;                           // 基地中的无人机数，输入N行请求
int n, m;                           // 现有无人机数目n, 派遣数目m
typedef pair<int,int> PII;
queue<PII> reqs;                    // 请求队列<a,b>
queue<PII> failedReqs;              // 派遣失败的请求<a,b>
unordered_map<int, int> signedReq;  // 已派遣的请求<请求id, 无人机数目>
int isBackedReq=-1;                 // 已连续返回的最小请求号
map<int, int> sleepReq;             // 返回后，休眠的请求<请求id，无人机数目>
vector<int> res;                    // 每次请求新派遣的无人机数目

// 通过率：25%


int main(){
    scanf("%d %d", &C, &N);
    n = C;
    int a, b;
    for(int i=0; i<N; ++i){
        scanf("%d %d", &a, &b);
        reqs.push({a,b});
    }
    while(!reqs.empty()){
        PII req = reqs.front();
        reqs.pop();
        // 如果是返回请求
        if(req.first < 0){
            // 看是否需要加入休眠队列
            if(req.second == isBackedReq+1){       // 不需要加入休眠队列，无人机返回基地
                isBackedReq = req.second;
                n += signedReq[req.second];
                signedReq[req.second]=0;
                // 看看休眠队列中其他的是否可以唤醒
                for(auto iter=sleepReq.begin(); iter!=sleepReq.end(); ++iter){
                    if(iter->first == isBackedReq+1){
                        isBackedReq = iter->first;
                        n+=iter->second;
                    }
                }
                // 取之前派遣失败的请求，看看现在能否成功派遣
                PII f_req = failedReqs.front();
                int f_a = f_req.first;
                int f_b = f_req.second;
                if(f_b > C){
                    if(n == C){
                        C = f_b;
                        n = 0;
                        signedReq[f_a] = f_b;
                        res.push_back(f_b);
                        failedReqs.pop();
                    }else{
                        res.push_back(0);
                    }
                }else{
                    if(n >= f_b){
                        n -= f_b;
                        signedReq[f_a] = f_b;
                        res.push_back(f_b);
                        failedReqs.pop();
                    }else{
                        res.push_back(0);
                    }
                }
            }else{                                 // 需要加入休眠队列
                sleepReq[req.second]=signedReq[req.second];
                res.push_back(0);
            }  
        }else{
            // 如果是派遣，且派遣失败，就加入到失败请求队列
            if(req.second > C){
                if(n == C){   // 升级基地，直接派遣
                    C = req.second;
                    n = 0;
                    signedReq[req.first] = req.second;
                    res.push_back(req.second);
                }else if(n < C){    // 派遣失败
                    failedReqs.push({req.first,req.second});
                    res.push_back(0);
                }else{
                    cout<<"error"<<endl;
                }
            }else{       // 派遣的 m<=C, 判断n,m的关系
                if(n < req.second){
                    failedReqs.push({req.first,req.second});
                    res.push_back(0);
                }else{
                    n -= req.second;
                    signedReq[req.first] = req.second;
                    res.push_back(req.second);
                }
            }
        }
    }
    // 输出结果
    for(auto& item: res){
        cout<<item<<endl;
    }
    return 0;
}