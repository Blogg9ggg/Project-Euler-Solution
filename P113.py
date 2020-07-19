# -*- coding: utf-8 -*-
"""
Created on Sun Jul 19 15:10:30 2020

@author: blogg9ggg

算是 P112 的进化版，可以转化成格路径问题来求解，如果不熟悉可以翻一下 《组合数学》。
"""


C = [];
for i in range(120):
    C.append([])
    C[i].append(1)
    for j in range(i):
        C[i].append(C[i][j]*(i-j)//(j+1))
        
ans = 0;
n = 100;
for i in range(10):
    ans += C[i+(n-1)][n-1];
    ans += C[i+1+(n-1)][n-1];

ans -= 10*n + 1;

print(ans);