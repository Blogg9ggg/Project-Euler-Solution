/*
对于一个 n ，有多少种不同的 (x,y) 满足要求呢？
基本思路是看看能不能转换成“XY = Z”这样的形式，将问题转化成计算 Z 的正因数个数，然后用约数定理解决。
1/x + 1/y = 1/n		=>
(x+y) / (xy) = 1/n		=>
xy = n(x+y)		=>
xy - (x+y)n + n^2 = n^2	=>
(x-n)(y-n)	= n^2
现在只需要计算 n^2 的正因数个数就行了，注意去重（结果要除以2再加1）。
p.s.1.  在质因数分解那里有一个强优化，可以看一下。
p.s.2.  改成 int 会快很多。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6;

bool bePrim[MAXN];
int Prim[MAXN]; int cnt;
void init(){
    memset(bePrim,1,sizeof(bePrim));
    bePrim[0]=bePrim[1]=0;

    for(int i=2;i<MAXN;i++){
        if(bePrim[i]){
            Prim[cnt]=i;
            cnt++;
            for(LL j=1ll*i*i;j<MAXN;j+=i)
                bePrim[j]=0;
        }
        
    }
}

LL cal(LL num){
    // 优化思路：
    // 对于一个满足要求的最小的数 num = (a1)^(t1) * (a2)^(t2) * ... * (an)^(tn)
    // 若 ai < aj, 则必有 ti >= tj。否则一定可以找到更小的数满足要求。
    LL ret=1;
    int last=10000;
    for(int i=0;i<cnt&&num>1;i++){
        if(num%Prim[i]==0){
            int temp=0;
            while(num%Prim[i]==0){
                num/=Prim[i];
                temp++;
            }
            if(temp>last)   return 0;
            last=temp;
            ret*=(2*temp+1);
        }
    }
    return ret/2+1;
}
int main(){
//    freopen("out.txt","w",stdout);
    init();
    
    for(LL i=1;i<100000000000;i++){
        LL temp=cal(i);
        if(temp>1000){
            printf("ans = %lld\n",i);
            break;
        }    
    }
    
    return 0;
}