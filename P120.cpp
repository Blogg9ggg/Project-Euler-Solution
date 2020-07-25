/*
*   结论1: 若 n 为偶数，则 r = 2. // 将 [(a-1)^n + (a+1)^n] 二项展开后即可得到这个结论.
*   
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