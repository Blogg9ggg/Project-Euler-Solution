#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 5;

LL length[MAXN];

struct BigNum{
    int len;
    int num[100000];

    BigNum operator +(const BigNum& b){
        BigNum ret;
        int tlen=max(len,b.len);
        int flag=0;
        for(int i=0;i<tlen;i++){
            int ta=0,tb=0;
            if(i<len)   ta=num[i];
            if(i<b.len) tb=b.num[i];

            ret.num[i]=ta+tb+flag;
            flag=0;

            if(ret.num[i]>=10){
                flag=1;
                ret.num[i]-=10;
            }
        }
        if(flag){
            ret.num[tlen]=1;
            tlen++;
        }
        ret.len=tlen;
        return ret;
    }
    bool check(){
        if(len<9)   return 0;

        bool vis[12];

        memset(vis,0,sizeof(vis));
        for(int i=0;i<9;i++)
            vis[num[i]]=1;
        for(int i=1;i<=9;i++){
            if(!vis[i]) return 0;
        }

//        return 1;

        memset(vis,0,sizeof(vis));
        for(int i=0;i<9;i++)
            vis[num[len-1-i]]=1;
        for(int i=1;i<=9;i++){
            if(!vis[i]) return 0;
        }

        return 1;
    }
    void print(){
        for(int i=len-1;i>=0;i--)   printf("%d",num[i]);
        puts("");
    }
}F[5];
int main(){
    F[0].len=1; F[0].num[0]=1;
    F[1].len=1; F[1].num[0]=1;

    int now=2;
    LL ind=3;
    while(1){
        F[now]=F[(now+2)%3]+F[(now+1)%3];

        if(F[now].check()){
            printf("%lld\n",ind);
            return 0;
        }
        now=(now+1)%3;
        ind++;
    }

    return 0;
}
