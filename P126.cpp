/*
推导过程:
3*2*1: 22 -(+24)-> 46 -(+32)-> 78 -(+40)-> 118
1*1*1: 6  -(+12)-> 18 -(+20)-> 38

f[(a,b,c),1] = (a*b+a*c+b*c)*2+(a+b+c)*0+(-1)*0;
f[(a,b,c),2] = (a*b+a*c+b*c)*2+(a+b+c)*4+0*4;
f[(a,b,c),3] = (a*b+a*c+b*c)*2+(a+b+c)*4+(a+b+c+2)*4 
             = (a*b+a*c+b*c)*2+(2a+2b+2c+2)*4 
             = (a*b+a*c+b*c)*2+(a+b+c+1)*8;
             = (a*b+a*c+b*c)*2+(a+b+c)*8+1*8;
f[(a,b,c),4] = (a*b+a*c+b*c)*2+(a+b+c)*4+(a+b+c+2)*4+(a+b+c+2+2)*4 
             = (a*b+a*c+b*c)*2+(3a+3b+3c+6)*4 
             = (a*b+a*c+b*c)*2+(a+b+c+2)*12;
             = (a*b+a*c+b*c)*2+(a+b+c)*12+2*12;
             ......
f[(a,b,c),n] = (a*b+a*c+b*c)*2+(a+b+c)(n-1)*4+(n-2)*(n-1)*4

Let a+b+c=k,(a*b+a*c+b*c)*2=t:
f[(a,b,c),n] = t+4(n-1)(k+n-2)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5+5;

int C[MAXN];
LL f(int a,int b,int c,int n){
    LL k=a+b+c;
    LL t=2ll*(a*b+a*c+b*c);
    return t+4ll*(n-1)*(k+n-2);
}
int main(){
    for(int a=1;6ll*a*a<MAXN;a++){
        for(int b=a;2ll*(a*b*2+b*b)<MAXN;b++){
            for(int c=b;2ll*(a*b+a*c+b*c)<MAXN;c++){
                for(int n=1;;n++){
                    LL tf=f(a,b,c,n);
                    if(tf>=MAXN)    break;
                    C[tf]++;
                }
            }
        }
    }
    for(int i=1;i<MAXN;i++){
        if(C[i]==1000){
            printf("%d\n",i);
            break;
        }  
    }
    return 0;
}