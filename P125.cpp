#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int limit = 100000000;
const int MAXN = 10005;
int ps[MAXN];

void init(){
    for(int i=1;i<MAXN;i++)    ps[i]=i*i;
}
int temp[20];
bool check(int num){
    int cnt=0;
    while(num){
        temp[cnt]=num%10;
        num/=10;
        cnt++;
    }
    for(int i=0,j=cnt-1;i<j;i++,j--){
        if(temp[i]!=temp[j])    return 0;
    }
    return 1;
}
set<int> vis;
int main(){
    init();
    LL ans1=0,ans2=0;
    for(int i=1;i<MAXN;i++){
        int now=ps[i];
        for(int j=i+1;j<MAXN;j++){
            now+=ps[j];
            if(now>limit)  break;
            if(check(now)&&!vis.count(now)){
                ans2+=now;
                ans1++;
                vis.insert(now);
            }  
        }
    }
    printf("%lld %lld\n",ans1, ans2);
    return 0;
}