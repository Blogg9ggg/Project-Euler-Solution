/*
*   P152 的预处理代码.
*/ 

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// Library 中的分数类.
LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}
LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}
class Fraction{
    private:
        LL numerator,denominator;
    public:
        Fraction(){
            numerator = 0;
            denominator = 1;
        }
        Fraction(LL nume, LL deno){
            if(!nume){
                numerator = 0;
                denominator = 1;
            }
            else{
                LL temp = gcd(nume, deno);
                numerator = nume/temp;
                denominator = deno/temp;
            }
        }
        Fraction operator* (const Fraction& b){
            LL new_nume = numerator*b.numerator;
            LL new_deno = denominator*b.denominator;
            return Fraction(new_nume, new_deno);
        }
        Fraction operator* (const LL& b){
            LL new_nume = numerator*b;
            return Fraction(new_nume, denominator);
        }
        Fraction operator+ (const Fraction& b){
            LL new_deno = lcm(denominator, b.denominator);
            LL new_nume = new_deno/denominator*numerator + new_deno/b.denominator*b.numerator;
            return Fraction(new_nume, new_deno);
        }
        LL nume(){
            return numerator;
        }
        LL deno(){
            return denominator;
        }
        void print(){
            printf("%lld/%lld\n",numerator,denominator);
        }
};

LL p;
bool check1(int nid, Fraction now){
    if(nid*p>80){
        if(now.nume() && now.deno()%p!=0)
            return 1;
        return 0;
    }    
    if(check1(nid+1,now))    return 1;
    now = now + Fraction(1,(p*nid)*(p*nid));
    if(now.deno()%p!=0) return 1;
    if(check1(nid+1,now))    return 1;
    return 0;
}
// ask1 可用于查询质数 tp (及其倍数) 是否可以加入.
void ask1(LL tp){
    p=tp;
    Fraction a;
    printf("%d\n",check1(1,a));
}

bool temp[100];
void check2(int nid, Fraction now, LL vis){
    if(nid*p>80){
        if(now.nume() && now.deno()%p!=0){
            int ind=1;
            while(vis){
                if(vis&1)
                    temp[ind]=1;
                vis>>=1;
                ind++;
            }
        }
        return ;
    }
    check2(nid+1,now,vis);
    now = now + Fraction(1,(p*nid)*(p*nid));
    vis |= (1ll<<(nid-1));
    check2(nid+1,now,vis);
}
void ask2(LL tp){
    memset(temp,0,sizeof(temp));
    p=tp;
    Fraction a;
    check2(1,a,0);
}

bool can_use[100];
bool Prim[100];
void init(){
    memset(Prim,1,sizeof(Prim));
    memset(can_use,1,sizeof(can_use));
    Prim[0]=Prim[1]=0;
    for(int i=2;i<100;i++){
        if(Prim[i]){
            for(int j=i*i;j<100;j+=i)
                Prim[j]=0;
        }
    }
    for(int i=11;i<=80;i++){
        if(Prim[i]&&i!=13){
            for(int j=i;j<=80;j+=i)
                can_use[j]=0;
        }
    }
    for(int i=3;i<=13;i++){
        if(Prim[i]&&i!=11){
            ask2(i);
            for(int j=1;j*i<=80;j++){
                if(!temp[j])
                    can_use[j*i]=0;
            }
        }
    }
    int ct=0;
    for(int i=2;i<=80;i++){
        if(can_use[i]){
            ct++;
            printf("%d,",i);
        }
    }
    printf("\n%d\n",ct);
}  
int main(){
//    ask1(7);
   
    init();
/* 
 * 38
 * 2,3,4,5,6,7,8,9,10,12,13,14,15,16,18,20,21,24,27,28,30,32,35,36,39,40,42,45,48,52,54,56,60,63,64,70,72,80
 */

    return 0;
}