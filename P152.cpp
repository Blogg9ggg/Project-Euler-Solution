/*
* 详情请看解析：https://github.com/Blogg9ggg/Project-Euler-Solution/blob/master/Analysis/P152.md
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

LL num[] = {2,3,4,5,6,7,8,9,10,12,13,14,15,16,18,20,21,24,27,28,30,32,35,36,39,40,42,45,48,52,54,56,60,63,64,70,72,80};
Fraction remin[50];
int cal(int nid,Fraction now){
    if(now.nume()*2>now.deno()) return 0;
    if(now.nume()*2==now.deno())    return 1;
    if(nid>=38) return 0;
    Fraction tt=now+remin[nid];
    if(tt.nume()*2<tt.deno())   return 0;
    int ret=0;
    ret+=cal(nid+1,now);
    now=now+Fraction(1,num[nid]*num[nid]);
    ret+=cal(nid+1,now);
    return ret;
}
void init(){
    remin[37]=Fraction(1,num[37]*num[37]);
    for(int i=36;i>=0;i--)
        remin[i]=Fraction(1,num[i]*num[i])+remin[i+1];
}
int main(){
    init();
    Fraction a;
    printf("%d\n",cal(0,a));

    return 0;
}