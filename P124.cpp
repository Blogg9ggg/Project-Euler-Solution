/*
*   数论
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 5;

bool bePrim[MAXN];
int Prim[MAXN]; int cnt;
int trad[MAXN];
struct Radical{
    int num;
    int rad;
    bool operator <(const Radical &b){
        if(rad!=b.rad)  return rad<b.rad;
        return num<b.num;
    }
}val[MAXN];
void init(){
    for(int i=0;i<MAXN;i++) trad[i]=1;
    memset(bePrim,1,sizeof(bePrim));
    bePrim[0]=bePrim[1]=0;

    for(int i=2;i<MAXN;i++){
        if(bePrim[i]){
            Prim[cnt]=i;    cnt++;
            trad[i]*=i;
            for(int j=2*i;j<MAXN;j+=i){
                bePrim[j]=0;
                trad[j]*=i;
            }
        }
    }
    for(int i=1;i<=100000;i++){
        val[i-1].num=i; val[i-1].rad=trad[i];
    }
    sort(val,val+100000);
}

int main(){
    init();
    printf("%d\n",val[10000-1].num);
    return 0;
}