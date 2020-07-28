/*
*   分数类。
*   支持的操作：
*       1. 分数+分数
*       2. 分数*分数
*       3. 分数*整数
*       4. 打印结果
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