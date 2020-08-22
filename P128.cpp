/*
*   其实每一圈只有两个数是需要检查的--第一个和最后一个.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e5+5;

bool bePrim[MAXN];
int Prim[MAXN],cnt;
LL t1[MAXN],t4[MAXN];
void init(){
    t1[0]=1,t1[1]=2;
    LL add1=6;
    for(int i=2;i<MAXN;i++,add1+=6){
        t1[i]=t1[i-1]+add1;
        t4[i-1]=t1[i]-1;
    }

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
    if(num<MAXN)
        return bePrim[num];
    for(int i=0;i<cnt;i++){
        if(num%Prim[i]==0)  return 0;
    }
    return 1;
}
int cal1(int now){
    int ct=0;
    LL tmp=t1[now];
    if(check(t1[now+1]+1-tmp)&&check(t4[now+1]-tmp)&&check(t4[now]-tmp))    return 1;
    return 0;
}

int cal4(int now){
    int ct=0;
    LL tmp=t4[now];
    if(check(tmp-t1[now-1])&&check(tmp-t1[now])&&check(t4[now+1]-1-tmp))    return 1;
    return 0;
}
void pnt(LL num,int now){
    printf("%lld\n",num);
    exit(0);
}
int main(){
    init();
    int ind=2;
    int now=1;
    int n=2000;
    while(1){
        if(cal1(now)){
            ind++;
            if(ind>n)
                pnt(t1[now],now);
        }
        if(now>1&&cal4(now)){
            ind++;
            if(ind>n)
                pnt(t4[now],now);
        }
        now++;
    }
    
    return 0;
}