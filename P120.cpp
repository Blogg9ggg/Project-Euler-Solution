/*
*   详情请看解析：https://github.com/Blogg9ggg/Project-Euler-Solution/blob/master/Analysis/P120.md
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

set<int> vis;
int main(){
    int aa,now,n;
    LL ans=0;
    for(int a=3;a<=1000;a++){
        int rmax=0;
        vis.clear();
        aa=a*a, n=1, now=2*a;
        while(1){
            if(vis.count(now)>0) break;
            vis.insert(now);
            rmax=max(rmax,now);
            n+=2;
            now=2*n*a%aa;
        }
        ans+=rmax;
        if(a==7){
            printf("rmas = %d\n",rmax);
        }
    }
    printf("%lld\n",ans);

    return 0;
}
