#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long LL;
const int MAXN = 1e6 + 5;
const LL limit = 1e16 + 3;
const LL MOD = 1ll<<52+1;

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
            numerator = 1;
            denominator = 1;
        }
        Fraction(LL nume, LL deno){
//            printf("nume = %lld, deno = %lld\n", nume, deno);
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
        void print(){
            printf("%lld/%lld\n",numerator,denominator);
        }
};

namespace Lagrange_Interpolation_Polynomial {
    const int D = 100;  //要用到的最高次幂（尽量取稍大）
    int n;
    LL y[D];
    Fraction L(LL x,int j){
        Fraction ret;
        for(int i=0;i<=n;i++){
            if(i!=j)
                ret=ret*Fraction(x-i,j-i);
        }
        return ret;
    }
    Fraction cal(LL x){
        Fraction ret = Fraction(0ll,1ll);
        Fraction temp;

        for(int i=0;i<=n;i++){
            temp = L(x,i);
            ret = ret + temp*y[i];

        }
        return ret;
    }
}

LL seq[20];
void test(){

}
void init(){
    for(int i=1;i<20;i++){
        LL temp = 1;
        LL ind=-1;
        for(int j=1;j<=10;j++,ind*=-1){
            LL t1=1;
            for(int k=0;k<j;k++)    t1*=i;
            temp=temp+ind*t1;
        }
        seq[i-1]=temp;
    }
}
int main(){
// freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
    init();
    LL fans=0;
    for(int i=0;i<10;i++){
        Lagrange_Interpolation_Polynomial::n=i;
        Lagrange_Interpolation_Polynomial::y[i]=seq[i];
        Fraction ans = Lagrange_Interpolation_Polynomial::cal(i+1);
        ans.print();
        fans+=ans.nume();
    }
    printf("%lld\n",fans);

    return 0;
}
