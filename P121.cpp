/*
*   用 dp 算出玩家获胜的概率，这个概率取倒数向下取整就是答案了（具体可以自己推一下）
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 用到 Library 中的分数类
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

int n = 15;
Fraction dp[52][30];
Fraction ans;
int main(){
    dp[0][0]=Fraction(1,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<=n/2;j++){
            if(dp[i][j].nume()>0){
                dp[i+1][j]=dp[i+1][j]+dp[i][j]*Fraction(1+i,2+i);
                dp[i+1][j+1]=dp[i+1][j+1]+dp[i][j]*Fraction(1,2+i);
            }
        }
        ans=ans+dp[i+1][n/2+1];
    }
    printf("%lf\n",(double)ans.deno()/ans.nume());

    return 0;
}