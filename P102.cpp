/*
*   用叉积判断点是否在三角形内部。
*/
//Warning: 请自行将txt中的逗号替换成空格！！！


#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define Vector Point
typedef long long LL;
const int MAXN = 1e6 + 5;
const LL limit = 1e16 + 3;
const LL MOD = 1ll<<52+1;

class Point{
private:
    int x,y;
public:
    Point(){
        x=0,y=0;
    }
    Point(int _x, int _y){
        x=_x,y=_y;
    }
    Point Input(){
        scanf("%d%d",&x,&y);
    }
    void print(){
        printf("(%d,%d)\n",x,y);
    }

    Point operator- (const Point& b){
        return Point(x-b.x,y-b.y);
    }
    int Cross(Vector b){
        return x*b.y-y*b.x;
    }
};
Point p[5];
Point O;

int sgn(int x){
    if(x<0) return -1;
    if(x>0) return 1;
    return 0;
}

int check(){
    int cnt=0;
    for(int i=0;i<3;i++){
        int j=(i+1)%3;
        Vector a=p[j]-p[i];
        Vector b=O-p[i];
        int temp=a.Cross(b);
        cnt+=sgn(temp);
    }
    if(cnt==-3||cnt==3) return 1;
    return 0;
}
int main(){
 freopen("p102_triangles.txt","r",stdin);
// freopen("out.txt","w",stdout);
    int t=1000;
    int ans=0;
    while(t--){
        for(int i=0;i<3;i++)
            p[i].Input();
        if(check()) ans++;
    }
    printf("%d\n",ans);

    return 0;
}
