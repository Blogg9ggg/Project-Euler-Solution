/*
*   推推公式, 写写暴力.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans=0;
    for(int n=1;n<1000000;n++){
        int temp=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int j=n/i;
                if((j+i)%4==0){
                    int a=i;
                    int t=(i+j)/4;
                    if(i>t) temp++;
                    if(i!=j&&j>t)
                        temp++;
                }
            }
            if(temp>10) break;
        }
        if(temp==10)    ans++;
    }
    printf("%d\n",ans);

    return 0;
}