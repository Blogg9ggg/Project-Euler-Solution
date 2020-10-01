/*
* 详情请看解析：https://github.com/Blogg9ggg/Project-Euler-Solution/blob/master/Analysis/P133.md
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000;

bool bePrim[MAXN];
int Prim[MAXN],cnt;
void init(){
    memset(bePrim,1,sizeof(bePrim));
    bePrim[0]=bePrim[1]=0;
    for(int i=2;i<MAXN;i++){
        if(bePrim[i]){
            Prim[cnt]=i;    cnt++;
            for(LL j=1ll*i*i;j<MAXN;j+=i)
                bePrim[j]=0;
        }
    }
}
int vis[10*MAXN], vis2[MAXN];
int main(){
//    freopen("out.txt","w",stdout);
    init();
    int ans=0;
    for(int i=0;i<cnt;i++){
        int now=1;
        int b=0,T=0;
        while(1){
            now=(now*10)%(9*Prim[i]);
            if(vis[now]==i+1)  break;
            T++;
            vis[now]=i+1;
            if(now==1)
                b=T;
        }
        if(!b){
            ans+=Prim[i];
            continue;
        }
        bool flag=0;
        now=1;
        b%=T;
        while(1){
            now=(now*10)%T;
            if(now==b){
                flag=1;
                break;
            }
            if(vis2[now]==i+1)  break;
            vis2[now]=i+1;
        }
        if(!flag)
            ans+=Prim[i];
    }
    printf("ans = %d\n",ans);

    return 0;
}