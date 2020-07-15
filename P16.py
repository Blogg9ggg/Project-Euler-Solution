# -*- coding: utf-8 -*-
"""
Created on Thu Jul 16 00:37:55 2020

@author: blogg9ggg
"""


a = 2**1000
ans = 0
while a > 0:
    ans = ans + a%10
    a = a//10

print(ans)
    