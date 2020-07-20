/*
*   DP
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[66][66]; //dp[i][j]: “前 i 个块中的最后连续 j 个块是红块” 这种情况的方案数。

int main(){
    int n=50;
    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(dp[i-1][j]>0){
                dp[i][j+1]+=dp[i-1][j];
                if(j>=3||!j)    dp[i][0]+=dp[i-1][j];
            }
        }
    }

    LL ans=dp[n][0];
    for(int i=3;i<=n;i++)   ans+=dp[n][i];
    printf("%lld\n",ans);

    return 0;
}