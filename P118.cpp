/*
*   DFS
*   求解的步骤挺多的，看一下代码和注释吧。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5;
const int limit = 1e9;

bool be_prim[MAXN];         // 记录是否是质数。be_prim[i] = 1 代表 i 是质数；be_prim[i] = 0 代表 i 不是质数。
int prim[MAXN]; int cnt;    // 保存 [0,1e5) 中的所有质数
// 埃氏素数筛
void init(){
    memset(be_prim,1,sizeof(be_prim));
    be_prim[0]=be_prim[1]=0;
    for(int i=2;i<MAXN;i++){
        if(be_prim[i]){
            prim[cnt]=i;    cnt++;
            for(LL j=1ll*i*i;j<MAXN;j+=i)
                be_prim[j]=0;
        }
    }
}

// 判断 [1e5,1e9) 这部分的数是否是质数
bool check(int num){
    for(int i=0;i<cnt;i++){
        if(num%prim[i]==0)  return 0;
    }
    return 1;
}

int sprim[MAXN];int scnt;   // 保存 [0,1e9) 中的所有 “各个数字只出现一次” 的质数，有 43089 个。
bool vis[10];
// 用 dfs 找出所有的 sprim
void dfs(int now,int dep){
    if(dep==8){
        if(now<MAXN){
            if(be_prim[now])    sprim[scnt]=now,scnt++;
        }
        else{
            if(check(now))  sprim[scnt]=now,scnt++;
        }
        return;
    }
    if(!now)    dfs(now,dep+1);
    for(int i=1;i<=9;i++){
        if(!vis[i]){
            vis[i]=1;   // 用 vis[] 保证 “各个数字只出现一次”
            dfs(now*10+i,dep+1);
            vis[i]=0;
        }
    }
}

int shape[600];     // 保存各种数位分布的质数的个数，如 shape[...1011] 代表有数字 1,2,4 的质数的个数
// 计算质数 num 的 shape
int cal(int num){
    int ret=0;
    while(num){
        int temp=num%10;
        num/=10;
        ret|=(1<<(temp-1));
    }
    return ret;
}
// 计算 shape[]
void cnt_shape(){
    for(int i=0;i<scnt;i++)
        shape[cal(sprim[i])]++;
}

LL ans;
int full_shape = (1<<9)-1;
// 再用一个 dfs 计算结果，为了去重还需要做一点处理
void dfs2(int now,int last,LL tans){
    if(now==full_shape){
        ans+=tans;
        return;
    } 
    for(int i=last+1;i<=full_shape-now;i++){
        if((i|now)==(i^now)&&shape[i]){
            dfs2(now|i,i,tans*shape[i]);
        }
    }
}

int main(){
    init();
    dfs(0,0);
    cnt_shape();
    dfs2(0,0,1);
    printf("%lld\n",ans);
    return 0;
}
