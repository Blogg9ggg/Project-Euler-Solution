/*
*   DP
*/
#include <bits/stdc++.h>
using namespace std;

int dp[200][200];
int inp[200][200];
int main(){
    freopen("in.txt","r",stdin);
    int n=15;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)   scanf("%d",&inp[i][j]);
    }
    for(int j=1;j<=n;j++)  dp[n][j]=inp[n][j];
    for(int i=n-1;i>0;i--){
        for(int j=1;j<=i;j++){
            dp[i][j]=inp[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    printf("%d\n",dp[1][1]);
}