/*
*   ...
*/
#include <bits/stdc++.h>
using namespace std;

int doubles_out[30];
int dp[200];
void init(){
    for(int i=1;i<=20;i++)  doubles_out[i]=2*i;
    doubles_out[0]=50;

    dp[0]=1;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=3;j++)
            dp[i*j]++;
    }
    dp[25]++;   dp[50]++;
}

int cal(int n){//考虑用前两镖达到 n 分的方案数，为了去重，规定第一镖的分数不能小于第二镖
    if(!n)  return 1;
    int ret=0;

    for(int fir=1;fir<=n;fir++){
        int sed=n-fir;
        if(fir>sed)             //第一镖的分数大于第二镖
            ret+=dp[fir]*dp[sed];
        else if(fir==sed){      //第一镖的分数等于第二镖
            ret+=dp[fir]*(dp[fir]+1)/2;
        }
    }

    return ret;
}

int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    init();

    int ans=0;
    for(int i=1;i<100;i++){
        for(int j=0;j<=20;j++){
            if(doubles_out[j]<=i){
                ans+=cal(i-doubles_out[j]);
            }
        }
    }

    printf("ans = %d\n",ans);
    return 0;
}