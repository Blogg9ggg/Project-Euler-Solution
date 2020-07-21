# -*- coding: utf-8 -*-
"""
Created on Tue Jul 21 22:24:37 2020

@author: blogg9ggg
"""

ans = 0
temp = 1
for i in range(100):
    temp *= (i+1)

while temp > 0:
    ans += temp%10
    temp //= 10

print(ans)