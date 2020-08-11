#include <bits/stdc++.h>
using namespace std;

int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool run(int year){
    if(year%4==0 && year%100!=0)  return 1;
    if(year%400==0) return 1;
    return 0;
}
int ans=0;
int y=1901,m=1,d=6;
void add1(){
    d++;
    if(m==2){
        int templ=28;
        if(run(y))  templ++;
        if(d>templ) m++,d=1;
    }
    else{
        if(d>month[m-1]){
            d=1;
            m++;
            if(m>12){
                y++;
                m=1;
            }
        }
    }
    if(y>2000){
        printf("%d\n",ans);
        exit(0);
    }
}

int main(){
    while(1){
        for(int i=0;i<7;i++)    add1();
//        printf("%d %d %d\n",y,m,d);
        if(d==1)
            ans++;
    }

    return 0;
}