/*
*   与 P120 类似, 可以看看 Project-Euler-Solution/Analysis/P120.md
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7;
const long long limit = 1e10;
bool bePrim[MAXN];
int Prim[MAXN]; int cnt;

void init(){
    memset(bePrim,1,sizeof(bePrim));
    bePrim[0]=bePrim[1]=0;
    for(int i=2;i<MAXN;i++){
        if(bePrim[i]){
            cnt++;  Prim[cnt]=i;
            for(long long j=1ll*i*i;j<MAXN;j+=i)    bePrim[j]=0;
        }
    }
}
int main(){
    init();
    for(int i=1;i<MAXN;i+=2){
        if(2ll*i*Prim[i]>limit){
            printf("%d\n",i);
            return 0;
        }
    }

    return 0;
}
