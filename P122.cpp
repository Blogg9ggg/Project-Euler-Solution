/*
*   查阅 WIKI(https://en.wikipedia.org/wiki/Addition-chain_exponentiation) 后可知：这是一个 NPC 问题，所以关键就是如何优雅地暴力。
*   自己没有想出来，看了题解(https://www.mathblog.dk/project-euler-122-efficient-exponentiation/#more-6003)。
*   但是，题解的正确性是基于这样的一个假设: 任何一个正确答案，它的路径上经过的任何一个点也都是最优点。不知道如何证明这个假设的成立，题解中也没有证明。
*   就这样吧，水过去了。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300;
const int LIMIT = 200;

int temp[MAXN];
int ans[MAXN];

void dfs(int dep,int now){
    if(now>LIMIT||dep>ans[now]) return;
    temp[dep]=now;
    ans[now]=dep;
    for(int i=dep;i>=0;i--)
        dfs(dep+1,now+temp[i]);
}
int main(){
//    freopen("out.txt","w",stdout);
    for(int i=1;i<=LIMIT;i++)   ans[i]=MAXN;
    temp[0]=1;
    dfs(0,1);
    int tot=0;
    for(int i=1;i<=200;i++) tot+=ans[i];

    printf("%d\n",tot);
    return 0;
}