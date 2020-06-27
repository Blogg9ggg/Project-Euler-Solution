#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define Vector Point
typedef long long LL;
const int MAXN = 2e6 + 5;
const LL limit = 1e16 + 3;
const int MOD = 1e9 + 7;

char Inp[100][60];
int num[100][50];
int result[5005];
int main(){
// freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
    for(int i=0;i<100;i++){
        scanf("%s",Inp[i]);
        for(int j=0;j<50;j++)
            num[i][j]=Inp[i][49-j]-'0';
    }
    int flag,temp;
    for(int i=0;i<100;i++){
        flag=0;
        for(int j=0;j<50;j++){
            temp=result[j]+num[i][j]+flag;
            flag=0;
            if(temp>=10){
                flag=1;
                temp-=10;
            }
            result[j]=temp;
        }
        int ind=50;
        while(flag){
            result[ind]+=flag;
            flag=0;

            if(result[ind]>=10){
                flag=1;
                result[ind]-=10;
            }

            ind++;
        }
    }
    int ind=5004;
    while(!result[ind]) ind--;
    int t=10;
    while(t--){
        printf("%d",result[ind]);
        ind--;
    }



    return 0;
}
