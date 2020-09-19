/*
* 详情请看解析：https://github.com/Blogg9ggg/Project-Euler-Solution/blob/master/Analysis/P132.md
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e8;
bool bePrim[MAXN];
int Prim[MAXN],cnt;

void init(){
    memset(bePrim,1,sizeof(bePrim));
    bePrim[0]=bePrim[1]=0;
    for(int i=2;i<MAXN;i++){
        if(bePrim[i]){
            Prim[cnt]=i;
            cnt++;
            for(LL j=1ll*i*i;j<MAXN;j+=i)
                bePrim[j]=0;
        }
    }
}
bool binpow(int a,int b,int mod){
    int res = 1;
    while (b > 0) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res==1?1:0;
}

int main(){
    init();
    LL ans=0;
    int ct=0;
    int b=1e9;
    for(int i=0;i<cnt;i++){
        if(binpow(10,b,9*Prim[i])){
            ans+=Prim[i];
            ct++;
            if(ct>=40)  break;
        }
    }
    
    printf("ct = %d, %lld\n",ct,ans);

    return 0;
}