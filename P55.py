# -*- coding: utf-8 -*-
"""
Created on Sat Oct  3 11:58:14 2020

@author: blogg9ggg
"""

temp=[];
for i in range(50):
    temp.append(0);

def check(num):
    ind=0;
    while num>0:
        temp[ind]=num%10;
        ind+=1;
        num//=10;
    
    flag=1;
    l=0;
    r=ind-1;
    while l<r:
        if temp[l]!=temp[r]:
            flag=0;
            break;
        l+=1;
        r-=1;
        
    return flag;
    
    
def cal(num):
    ret=num;
    ind=0;
    while num>0:
        temp[ind]=num%10;
        ind+=1;
        num//=10;
    
    rnum=0;
    for i in range(ind):
        rnum=rnum*10+temp[i];
    ret+=rnum;
    
    return ret;
    
        
ans=0;
for i in range(1,10000):
    now=i;
    flag=1;
    for j in range(50):
        now=cal(now);
        if check(now)==1:
            flag=0;
            break;
    ans+=flag;

print(ans);
        