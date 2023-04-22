#include <bits/stdc++.h>
using namespace std;

// 通过率:1.67%

typedef pair<int,int> PII;
typedef pair<int,double> PID;
typedef pair<PII,PII> PNN;
const int N = 1010;
const int X = 1024;
const int Y = 1024;
int edges[7] = {8,16,32,64,128,256,512};
PID pics[N];      // 边长,权重
// 贪心-最左上紧凑
vector<PNN> frames;      // 碎片, <x, y>, <f_x, f_y>
map<vector<PII>, bool> frames_map;      // 已有碎片的map
int n,w;
double s;
double sum = 0;

bool cmp(PID p1, PID p2){
    if(p1.second != p2.second){
        return p1.second > p2.second;
    }else{
        return p1.first > p2.first;
    }
}

int main(){
    scanf("%d", &n);
    frames.push_back({{0,0},{X,Y}});
    for(int i=0; i<n; ++i){
        cin>>pics[i].first>>pics[i].second;
    }
    sort(pics, pics+n, cmp);
    for(int i=0; i<n; ++i){
        w = pics[i].first;
        s = pics[i].second;
        // 在fram中找可以用的空间
        PNN f;
        bool isGetF = false;
        for(int j=0; j<frames.size(); ++j){
            int left_x = frames[j].second.first-frames[j].first.first;
            int left_y = frames[j].second.second-frames[j].first.second;
            //printf("frames[%d]: left_x: %d, left_y: %d\n", j,left_x, left_y);
            if(left_x >= w && left_y >= w){     // 该fram可用
                isGetF = true;
                f = frames[j];
                frames.erase(frames.begin()+j);
                break;
            }
        }
        if(isGetF){
            sum += s;
            //cout<<"add: "<<w<<" "<<s<<endl;
            int x = f.first.first;
            int y = f.first.second;
            int f_x = f.second.first;
            int f_y = f.second.second;
            frames.push_back({{x+w, y},{f_x, y+w}});
            frames.push_back({{x, y+w},{x+w, f_y}});
            frames.push_back({{x+w, y+w},{f_x, f_y}});
            //printf("++ frame: (%d, %d)--(%d, %d)\n", x+w,y,f_x,y+w);
            //printf("++ frame: (%d, %d)--(%d, %d)\n", x,y+w,x+w,f_y);
            //printf("++ frame: (%d, %d)--(%d, %d)\n", x+w,y+w,f_x,f_y);
        }else{
            // 缩小
            while(w >= 8){
                w = w/2;
                s = s/4;
                PNN sub_f;
                bool isGet = false;
                for(int j=0; j<frames.size(); ++j){
                    int left_x = frames[j].second.first-frames[j].first.first;
                    int left_y = frames[j].second.second-frames[j].first.second;
                    if(left_x >= w && left_y >= w){     // 该fram可用
                        isGet = true;
                        sub_f = frames[j];
                        frames.erase(frames.begin()+j);
                        break;
                    }
                }
                if(isGet){
                    sum += s;
                    //cout<<"sub add: "<<w<<" "<<s<<endl;
                    int x = sub_f.first.first;
                    int y = sub_f.first.second;
                    int f_x = sub_f.second.first;
                    int f_y = sub_f.second.second;
                    frames.push_back({{x+w, y},{f_x, y+w}});
                    frames.push_back({{x, y+w},{x+w, f_y}});
                    frames.push_back({{x+w, y+w},{f_x, f_y}});
                    break;
                }
            }
        }
    }
    printf("%.2lf\n", sum);
    return 0;
}
