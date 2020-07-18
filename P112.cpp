/*
*   二分 + 数位 DP
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int limit[100]; 
int len;
LL pw10[20];

int check(LL);
bool test(LL,LL);

void init(LL lim){
    len=0;
    while(lim){
        limit[len]=lim%10;
        lim/=10;
        len++;
    }
}
LL dfs(int ind, bool less, int last, int tend){ //tend: -1,头; 0,平; 1,升; 2,降; 3,有升有降
    int dig=limit[ind];
    if(less)    dig=9;
    LL ret=0;

    if(!ind){
        if(tend<=0) return 0;
        if(tend==1){
            for(int i=0;i<last&&i<=dig;i++) ret++;
        }
        else if(tend==2)
            ret+=max(0,dig-last);
        else
            for(int i=0;i<=dig;i++) ret++;
        return ret;
    }

    for(int i=0;i<=dig;i++){
        if(tend==-1){
            if(!i)
                ret+=dfs(ind-1,1,-1,-1);
            else
                ret+=dfs(ind-1,less||(i<dig),i,0);
            
        }
        else if(tend==0){
            int ntend=0;
            if(i>last)  ntend=1;
            if(i<last)  ntend=2;
            ret+=dfs(ind-1,less||(i<dig),i,ntend);
        }
        else if(tend==1){
            if(i<last){
                if(less||i<dig) ret+=pw10[ind];
                else    ret+=dfs(ind-1,less||(i<dig),i,3);
            }  
            else
                ret+=dfs(ind-1,less||(i<dig),i,tend);
        }
        else if(tend==2){
            if(i>last){
                if(less||i<dig) ret+=pw10[ind];
                else ret+=dfs(ind-1,less||(i<dig),i,3);
            }  
            else
                ret+=dfs(ind-1,less||(i<dig),i,tend);
        }
        else{
            if(less||i<dig)   ret+=pw10[ind];
            else    ret+=dfs(ind-1,less||(i<dig),i,3);
        }
    }
    return ret;
}

int main(){
//    freopen("out.txt","w",stdout);
    pw10[0]=1;
    for(int i=1;i<20;i++)   pw10[i]=pw10[i-1]*10;


    LL ans=1e16;
    LL l=100,r=1e10;
    for(int i=0;i<100;i++){
        LL m=(l+r)/2;
        init(m);
        LL temp=dfs(len-1,0,-1,-1);

        if(temp*100/m>=99){
            ans=min(ans,m);
            r=m;
        }
        else
            l=m+1;

    }
    printf("%lld\n",ans);

    return 0;
}



int check(LL num){
    LL temp;
    int ret=2, last;

    temp=num,last=10;
    while(temp){
        if(temp%10>last){
            ret--;
            break;
        }
        last=temp%10;
        temp/=10;
    }
    if(ret==2)  return ret;

    temp=num,last=0;
    while(temp){
        if(temp%10<last){
            ret--;
            break;
        }
        last=temp%10;
        temp/=10;
    }

    return ret;
}
bool test(LL num,LL temp2){
    LL temp1=0;
    for(LL i=100;i<=num;i++){
        if(check(i)==0) temp1++;
    }
    return temp1==temp2;
    exit(0);
}