/*
*   C(40,20)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL C40[50];
int main(){

    C40[0]=1;
    for(int i=1;i<=20;i++){
        C40[i]=C40[i-1]*(40-(i-1))/i;
    }
    printf("%lld\n",C40[20]);
}