#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 5;

LL length[MAXN];

LL f(LL n){
    if(n%2==0)  return n/2;
    else        return n*3+1;
}
int cal(LL n){
    if(n<MAXN&&length[n]!=-1)   return length[n];
    int ret=cal(f(n))+1;
    if(n<MAXN)  length[n]=ret;
    return ret;
}
int main(){
    memset(length,-1,sizeof(length));

    length[1]=1;
    int ans=0, ct = 0;
    for(LL i=2;i<=1000000;i++){
        int temp=cal(i);
        if(ct<temp){
            ans = i;
            ct = temp;
        }
    }
    printf("%d\n",ans);

    return 0;
}
