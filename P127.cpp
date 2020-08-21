/*
*   直接暴力的话 6s 多.
*   加了一点优化 3s 多.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 120000 + 3;

bool bePrim[MAXN];
int rad[MAXN];
int Prim[MAXN],cnt;
struct num_rad{
    int num,rad;
    bool operator <(const num_rad &b){
        if(rad!=b.rad)  return rad<b.rad;
        return num<b.num;
    }
}nr[MAXN];
void init(){
    memset(bePrim,1,sizeof(bePrim));
    bePrim[0]=bePrim[1]=0;
    rad[1]=1;
    for(int i=2;i<MAXN;i++){
        if(bePrim[i]){
            Prim[cnt]=i;    cnt++;
            rad[i]=i;
            for(int j=2*i;j<MAXN;j+=i){
                bePrim[j]=0;
                if(!rad[j]) rad[j]=i;
                else    rad[j]*=i;
            }
        }
    }
    for(int i=1;i<MAXN;i++){
        nr[i].num=i;
        nr[i].rad=rad[i];
    }
    sort(nr+1,nr+MAXN);
}
int cal(int lrad){
    int l=1,r=MAXN-1;
    int ret=MAXN;
    while(l<=r){
        int m=(l+r)/2;
        if(nr[m].rad<lrad)  l=m+1;
        else if(nr[m].rad==lrad){
            ret=min(ret,m);
            r=m-1;
        }
        else
            r=m-1;
    }
    return ret;
}
bool gcd3(int a,int b,int c){
    int temp=a*b*c;
    if(rad[temp]==temp) return 1;
    return 0;
}
int main(){
    init();
    LL ans=0;
    for(int i=1;i<120000;i++){
        if(rad[i]<i){
            int ct1=i/2;
            int lrad=i/rad[i];
            int ct2=cal(lrad);
            if(ct1<ct2){
                for(int a=1;;a++){
                    int b=i-a;
                    if(b<=a)    break;
                    if(1ll*rad[a]*rad[b]*rad[i]<i&&gcd3(rad[a],rad[b],rad[i]))
                        ans+=i;
                }
            }
            else{
                for(int j=1;j<=ct2;j++){
                    int a=nr[j].num;
                    int b=i-a;
                    if(b>a){
                        if(1ll*rad[a]*rad[b]*rad[i]<i&&gcd3(rad[a],rad[b],rad[i]))
                            ans+=i;
                    }
                }
            }
        }   
    }
    printf("%lld\n",ans);
    return 0;
}