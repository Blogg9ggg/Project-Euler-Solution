/*
*   跟 P135 好像并无区别. 可以直接用 P135 的做法, 但是很慢...
*   于是我再 P135 的讨论区找到了这条式子:
*   (m+x)(3m-x)=(x+2m)^2-(x+m)^2-x^2;
*   复杂度估计好像差不多, 但是跟 P135 的做法相比少了很多操作, 快了很多...
*/



#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 50000000;
int counts[MAXN];
int main(){
    for(int x=1;x<MAXN;x++){
        for(int m=(x+2)/3;m<MAXN;m++){
            LL temp=1ll*(m+x)*(3*m-x);
            if(temp<MAXN)   counts[temp]++;
            else    break;
        }
    }
    
    int ans=0;
    for(int i=1;i<MAXN;i++){
        if(counts[i]==1)    ans++;
    }
    printf("%d\n",ans);

    return 0;
}
