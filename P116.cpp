/*
*   DP
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[100];

int main(){
    int n = 50;
    LL ans = 0;
    for(int colour = 2; colour <= 4; colour++){
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            dp[i+1] += dp[i];
            if(i+colour <= n)   dp[i+colour] += dp[i];
        }
        ans += dp[n] - 1;
    }

    printf("%lld\n", ans);

    return 0;
}