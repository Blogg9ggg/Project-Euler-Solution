#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int lenth[110];
void init(){
    lenth[1]=3;
    lenth[2]=3;
    lenth[3]=5;
    lenth[4]=4;
    lenth[5]=4;
    lenth[6]=3;
    lenth[7]=5;
    lenth[8]=5;
    lenth[9]=4;
    lenth[10]=3;
    lenth[11]=6;
    lenth[12]=6;
    lenth[13]=8;
    lenth[14]=8;
    lenth[15]=7;
    lenth[16]=7;
    lenth[17]=9;
    lenth[18]=8;
    lenth[19]=8;
    lenth[20]=6;
    lenth[30]=6;
    lenth[40]=5;
    lenth[50]=5;
    lenth[60]=5;
    lenth[70]=7;
    lenth[80]=6;
    lenth[90]=6;
}
int cal(int num){
    bool flag=0;
    int ret=0;
    if(num>=100){
        ret+=lenth[num/100]+7;
        num%=100;
        flag=1;
    }
    if(num==0);
    else if(num<=20||num%10==0)
        ret+=(flag?3:0)+lenth[num];
    else{
        ret+=(flag?3:0)+lenth[num/10*10];
        num%=10;
        if(num) ret+=lenth[num];
    }

    return ret;
}

int main(){
    init();
    int ans=11;
    for(int i=1;i<1000;i++)
        ans+=cal(i);
    
    printf("%d\n",ans);
    return 0;
}