/*
*   自己推了一个多小时推出了一条根本不能用的式子.
*   最后还是看题解(https://www.mathblog.dk/project-euler-131-primes-perfect-cube/#more-6220)才做出来的.
*   我太菜了..
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000;

bool bePrim[MAXN];
void init(){
    memset(bePrim,1,sizeof(bePrim));
    bePrim[0]=bePrim[1]=0;
    for(int i=2;i<MAXN;i++){
        if(bePrim[i]){
            for(LL j=1ll*i*i;j<MAXN;j+=i)
                bePrim[j]=0;
        }
    }
}
int main(){
    init();
    int ans=0;
    for(LL i=1;;i++){
        LL d=(i+1)*(i+1)*(i+1)-i*i*i;
        if(d>=MAXN) break;
        if(bePrim[d])   ans++;
    }
    printf("%d\n",ans);
    return 0;
}