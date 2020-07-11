/*
*   “需要检查的子集对”所必须满足的第一个条件：两个子集元素个数相等且都大于1。
*   Part 1 的代码就是在筛选满足第一个条件的子集对。
*
*   在第一个条件的基础上还需要进一步筛选：
*   若对于子集 A 中的任意一个元素 a，都能在子集 B 中找到一个元素 b，满足 a < b（这个 b 是没有跟 A 中其他元素配对过的），那么有 S(A) < S(B)
*   满足这种情形的子集对也是不需要检查条件 i 的。
*   Part 2 的代码就是在去掉满足第二种情形的子集对。
*   为什么要用卡特兰数呢？
*   想象一下：子集 A 和子集 B 所有的元素按照大小顺序排成一个数列，将子集 A 的元素看成是左括号，将子集 B 的元素看成右括号，那么原数列就可以
*   看成一个括号序列，如果这个括号序列正确匹配，那是否就代表子集 A 和子集 B 满足第二种情形？
*/



#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

//C是组合数，S是卡特兰数
LL C[20][20],S[20];
void init(){
    C[0][0]=1;
    for(int i=1;i<20;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i][j-1]*(i-j+1)/j;
        }
    }
    S[0]=S[1]=1;
    for(int i=2;i<20;i++){
        for(int j=0;j<i;j++)
            S[i]+=S[j]*S[i-1-j];
    }
}
int main(){
    //预计算卡特兰数和组合数
    init();

    LL ans=0;

    /* Part 1 */
    for(int i=4;i<=12;i+=2)
        ans+=C[12][i]*C[i][i/2];
    ans /= 2;

    /* Part 2 */
    for(int i=2;i<=6;i++)   ans-=C[12][2*i]*S[i];

    printf("%lld\n",ans);
    return 0;
}
