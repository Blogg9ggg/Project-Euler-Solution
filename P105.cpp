#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define Vector Point
typedef long long LL;
const int MAXN = 2e6 + 5;
const LL limit = 1e16 + 3;
const int MOD = 1e9 + 7;
char Inp[100];
int num[20];


int main(){
 freopen("p105_sets.txt","r",stdin);
// freopen("out.txt","w",stdout);
    LL ans=0;
    while(~scanf("%s",Inp)){
        memset(num,0,sizeof(num));

        int len=strlen(Inp);
        int ind=0;
        for(int i=0;i<len;i++){
            if(Inp[i]==',') ind++;
            else
                num[ind]=num[ind]*10+Inp[i]-'0';
        }
        int ful=(1<<(ind+1))-1;
        int l,r;
        bool flag=1;
        for(l=1;l<ful&&flag;l++){
            for(r=1;r<ful&&flag;r++){
                if((l^r)==l+r){
                    int suml=0,ctl=0,tl=l;
                    int sumr=0,ctr=0,tr=r;

                    int id=0;
                    while(tl){
                        if(tl&1){
                            suml+=num[id];
                            ctl++;
                        }
                        tl>>=1;
                        id++;
                    }

                    id=0;
                    while(tr){
                        if(tr&1){
                            sumr+=num[id];
                            ctr++;
                        }
                        tr>>=1;
                        id++;
                    }

                    if(suml==sumr)  flag=0;
                    if(ctl>ctr){
                        if(suml<=sumr)  flag=0;
                    }
                    else if(ctl<ctr){
                        if(suml>=sumr)  flag=0;
                    }
                }
            }
        }
        if(flag){
            for(int i=0;i<=ind;i++) ans+=num[i];
        }
    }
    cout<<ans<<endl;



    return 0;
}
