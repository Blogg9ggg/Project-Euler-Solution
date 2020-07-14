/*
*   一开始是正向暴力计算的，需要算很久。
*   后来想了想：好像经常看见一些重复的数字很多的质数啊，会不会 M(10,d) 都是很大的啊？不妨反着来试试？然后就秒了...
*   我觉得这个可以作为一个经验性的结论记一下。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6;

bool bePrim[MAXN];
int Prim[MAXN]; int cnt;
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

bool check(LL num){
    for(int i=0;i<cnt;i++){
        if(num%Prim[i]==0)  return 0;
    }
    return 1;
}


LL dfs(int ind,LL now,int d,int M,int dM){
    if(ind==10){
        if(check(now))  return now;
        return 0;
    }

    LL ret=0;
    for(int i=0;i<10;i++){
        if(ind==0&&i==0)    continue;
        if(i!=d&&dM)    ret+=dfs(ind+1,now*10+i,d,M,dM-1);
        else if(i==d&&M)    ret+=dfs(ind+1,now*10+i,d,M-1,dM);
    }
    return ret;
}


int main(){
    init();
    LL ans=0;
    for(int d=0;d<10;d++){
        for(int M=9;M>5;M--){
            LL S=dfs(0,0,d,M,10-M);
            if(S>0){
                ans+=S;
                break;
            }
        }
    }
    printf("%lld\n",ans);

    return 0;
}