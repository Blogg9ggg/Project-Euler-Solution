/*
*   DP
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[100];

int main(){
    int n = 50;
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int colour = 1; colour <= 4; colour++){
            if(i+colour <= n)   dp[i+colour] += dp[i];
        }
    }
    
    printf("%lld\n", dp[n]);

    return 0;
}