/*
*   DP
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[1000][1000]; //dp[i][j]: “前 i 个块中的最后连续 j 个块是红块” 这种情况的方案数。

LL F(int m,int n){
    memset(dp,0,sizeof(dp));

    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(dp[i-1][j]>0){
                dp[i][j+1]+=dp[i-1][j];
                if(j>=m||!j)    dp[i][0]+=dp[i-1][j];
            }
        }
    }

    LL ret=dp[n][0];
    for(int i=m;i<=n;i++)   ret+=dp[n][i];

    return ret;
}
int main(){
    int m=50;
    
    for(int i=m;;i++){
        if(F(m,i)>1000000){
            printf("%d\n",i);
            return 0;
        }
    }
    

    return 0;
}