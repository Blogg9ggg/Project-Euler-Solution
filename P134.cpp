/*
*   题解自行翻看 Analysis 文件夹.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 100;
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
LL ex_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    LL d=ex_gcd(b,a%b,x,y);
    LL temp=x;
    x=y;
    y=temp-a/b*y;
    return d;
}
bool liEu(LL a,LL b,LL c,LL &x, LL &y){
    LL d=ex_gcd(a,b,x,y);
    if(c%d!=0)  return 0;
    LL k=c/d;
    x*=k,y*=k;

    if(x>0){
        LL t=x/b;
        x=x-b*t;
        y=y+a*t;
    }
    else{
        LL t=(b-1-x)/b;
        x=x+b*t;
        y=y-a*t;
    }

    return 1;
}

int main(){
    init();

    LL ans=0;
    for(int i=2;;i++){
        int p1=Prim[i]; 
        if(p1>1000000)  break;
        int p2=Prim[i+1];

        LL tten=1;
        while(tten<=p1)    tten*=10;

        LL x,y;
        liEu(tten,p2,p2-p1,x,y);
          
        ans+=x*tten+p1;
    }
    printf("%lld\n",ans);

    return 0;
}



/*
*   一种暴力的做法, 需要一分多钟.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 100;
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
bool check(LL tS, int p1){
    while(p1){
        int a=tS%10;
        int b=p1%10;
        if(a!=b)    return 0;
        tS/=10; p1/=10;
    }

    return 1;
}

int main(){
    init();
    LL ans=0;
    for(int i=2;;i++){
        int p1=Prim[i]; if(p1>1000000)  break;
        LL tten=1;
        while(tten<=p1)    tten*=10;
        int p2=Prim[i+1];

        LL S=tten+p1;
        while(1){
            if(S%p2==0){
                ans+=S;
                break;
            }
            S+=tten;
        }
    }
    printf("%lld\n",ans);

    return 0;
}
*/