/*
对于一个 n ，有多少种不同的 (x,y) 满足要求呢？
基本思路是看看能不能转换成“XY = Z”这样的形式，将问题转化成计算 Z 的正因数个数，然后用约数定理解决。
1/x + 1/y = 1/n		=>
(x+y) / (xy) = 1/n		=>
xy = n(x+y)		=>
xy - (x+y)n + n^2 = n^2	=>
(x-n)(y-n)	= n^2
现在只需要计算 n^2 的正因数个数就行了，注意去重（结果要除以2再加1）。
*/

/*
用弱数据版本的代码（P108）跑了一下午也没跑出答案。要怎么优化呢？
拜读了这篇 blog: https://www.mathblog.dk/project-euler-110-efficient-diophantine-equation/
有2个可以优化的点：
1.  由于 3^14 > 4000000, 所以答案分解后最多只有 14 个不同的质因数
2.  答案一定是由前几个连续的质因数相乘而得，而且指数一定是递减的。
用 dfs 如果剪枝得足够优秀的话是可以秒出答案的。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100;
const int BORDER = 4000000;

bool bePrim[MAXN];
int Prim[MAXN]; int cnt;
void init(){
    memset(bePrim,1,sizeof(bePrim));
    bePrim[0]=bePrim[1]=0;

    for(int i=2;i<MAXN;i++){
        if(bePrim[i]){
            Prim[cnt]=i;
            cnt++;
            for(int j=i*i;j<MAXN;j+=i)
                bePrim[j]=0;
        }
        if(cnt >= 16)   break;
    }
}

LL ans = 1e18;
void dfs(int now, LL num, int sols, int last, int limit){
// now: 质数下标
// num: 当前的 n
// sols: 当前 n 的正因数个数
// last: 上一个质数的指数
// limit: 当前质数的指数上界

    if(sols/2 + 1 > BORDER){
        // 更新答案
        ans = num;
        return;
    }

    if(now >= 14)
    // 最多 14 个不同的质因数
        return ;

    int tsols,tlimit;
    for(int i = 1; i <= limit && i <= last; i++){
        num *= Prim[now];
        if(num >= ans)  break;  // 剪枝
        tsols = sols*(2*i+1);
        // 计算上界: 
        // tsols * (2*limit+1) / 2 + 1 > BORDER      =>
        // 2*limit + 1 > (BORDER-1) * 2 / tsols + 1  =>
        // limit > (BORDER-1) / tsols
        tlimit = (BORDER-1)/tsols + 1;      // +1 是最稳妥的 
        dfs(now+1, num, tsols, i, tlimit);
    }
}

int main(){
//    freopen("out.txt","w",stdout);
    init();
    dfs(0,1,1,100,100);
    printf("%lld\n", ans);
    return 0;
}