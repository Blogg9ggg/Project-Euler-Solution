/*
*   emmm, 有点坑..
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5;

LL d[MAXN];
bool dd[MAXN];
void init(){
    for(LL i=1;i<10000;i++){
        for(LL j=1;j*j<=i;j++){
            if(i%j==0){
                d[i]+=j;
                if((i/j)!=j)  d[i]+=(i/j);
            }
        }
        d[i]-=i;
    }
}

int main(){
    init();
    
    for(LL a=1;a<10000;a++){
        LL b=d[a];
        if(b<10000 && d[b]==a && a!=b)
            dd[a]=dd[b]=1;
    }
    LL ans=0;
    for(LL i=2;i<10000;i++){
        if(dd[i])
            ans+=i;
    }
    printf("ans = %lld\n",ans);

    return 0;
}