/*
*   找出前面几项，看不出有什么规律，然后去 oeis 查，答案是 248155780267521。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool check(int num){
    int temp1=num,temp2=0;
    while(temp1){
        temp2+=temp1%10;
        temp1/=10;
    }
    if(temp2==1)    return 0;
    while(num%temp2==0)
        num/=temp2;
    
    if(num==1)  return 1;
    return 0;
}
int main(){
    for(int i=10;i<=614656;i++){
        if(check(i))    printf("%d\n",i);
    }
    return 0;
}