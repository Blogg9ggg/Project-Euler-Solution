#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5;

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
bool check(int num){
    if(num<MAXN)    return bePrim[num];
    for(int i=0;i<cnt;i++){
        if(num%Prim[i]==0)  return 0;
    }
    return 1;
}
int main(){
    init();
    int ct=0;
    LL ans=0;
    for(int i=3;;i+=2){
        if(i%5==0)  continue;
        int k=1;
        int now=1;
        while(1){
            if(!now)    break;
            now=(now*10+1)%i;
            k++;
        }
        if((i-1)%k==0&&!check(i)){
            ct++;
            ans+=i;
        }
        if(ct==25){
            printf("%lld\n",ans);
            return 0;
        }
    }
    return 0;
}