/*
*   除了暴力直接算想不出别的方法, 去 MATHBLOG 看了一眼, 它也是暴力.
*   不过看见答案是可以用 int 的, 所以改成用 int, 可以稍微加速一点点. 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5+5;

int main(){
    int limit=1000000;
    for(int i=3;;i+=2){
        if(i%5==0)  continue;
        int k=1;
        int now=1;
        while(1){
            if(!now)    break;
            now=(now*10+1)%i;
            k++;
        }
        if(k>limit){
            printf("%d\n",i);
            break;
        }
    }

    return 0;
}