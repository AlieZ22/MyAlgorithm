#include <bits/stdc++.h>
#include <cstdint>
#include <sstream>
using namespace std;

// 通过：33%，时间复杂度过高

/*
给出n条规则，m个ip地址，输出m行，每行为对应ip地址符合的规则数。
规则一共三种：
1，ip地址
2，ip范围
3，ip网段
示例输入：n行规则的1，2，3为规则种类
3 5
1 10.10.10.1
2 10.10.10.0 10.10.10.10
3 10.10.0.0/16
10.10.10.1
10.10.10.2
10.11.1.1
10.10.10.11
10.9.10.0
输出：
3
2
0
1
0
*/

struct Rule1{
    uint32_t ip;
};

struct Rule2{
    uint32_t start;
    uint32_t end;
};

struct Rule3{
    uint32_t ip;
    uint32_t mask;
};

uint32_t ipToUnit32(string ip){
    stringstream ss(ip);
    int a, b, c, d;
    char ch;
    ss >> a >> ch >> b >> ch >> c >> ch >> d;
    return (a << 24) + (b << 16) + (c << 8) + d;
}

bool matchRule1(uint32_t query, Rule1 rule){
    return query == rule.ip;
}

bool matchRule2(uint32_t query, Rule2 rule){
    return query >= rule.start && query <= rule.end;
}

bool matchRule3(uint32_t query, Rule3 rule){
    return (query & rule.mask) == (rule.ip & rule.mask);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Rule1> rules1;
    vector<Rule2> rules2;
    vector<Rule3> rules3;
    for(int i=0; i<n; ++i){
        int op;
        string ip1, ip2;
        cin>>op;
        if(op == 1){
            cin >> ip1;
            rules1.push_back({ipToUnit32(ip1)});
        }else if(op == 2){
            cin >> ip1 >> ip2;
            rules2.push_back({ipToUnit32(ip1), ipToUnit32(ip2)});
        }else{
            cin >> ip1;
            auto pos = ip1.find('/');
            int prefix = stoi(ip1.substr(pos + 1));
            uint32_t mask = (prefix == 0) ? 0 : (~0 << (32 - prefix));
            rules3.push_back({ipToUnit32(ip1.substr(0, pos)), mask});
        }
    }

    while(m--){
        string query_ip;
        cin>>query_ip;
        uint32_t query = ipToUnit32(query_ip);

        int count = 0;
        for(const auto &rule : rules1){
            count += matchRule1(query, rule);
        }
        for(const auto &rule : rules2){
            count += matchRule2(query, rule);
        }
        for(const auto &rule : rules3){
            count += matchRule3(query, rule);
        }
        cout<< count << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")