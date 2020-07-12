/*
*   最小生成树
*   (自行将 txt 中的 "," 替换成空格)
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

char Inp[50];
int char2int(){
    if(Inp[0]=='-') return INF;
    int ret=0;
    for(int i=0;Inp[i]!='\0';i++)
        ret=ret*10+Inp[i]-'0';
    return ret;
}

int n=40;
int cost[50][50];
int lowc[50];
bool vis[50];

int Prim(){
    int ans=0;
    vis[1]=1;
    for(int i=2;i<=n;i++)   lowc[i]=cost[1][i];
    for(int i=2;i<=n;i++){
        int minc=INF;
        int p=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j] && minc>lowc[j]){
                minc=lowc[j];
                p=j;
            }
        }
        if(minc==INF)   return -1;
        ans+=minc;
        vis[p]=1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&lowc[j]>cost[p][j])
                lowc[j]=cost[p][j];
    }
    return ans;
}

int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    freopen("p107_network.txt","r",stdin);
    int tot=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%s",Inp);
            cost[i][j]=char2int();
            if(i==j)    cost[i][j]=0;
            else if(cost[i][j]<INF)
                tot+=cost[i][j];
        }
    }
    tot/=2;
    printf("%d\n",tot-Prim());

    
}