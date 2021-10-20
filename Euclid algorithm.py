# -*- coding: utf-8 -*-
"""
Created on Sat Jan 30 21:06:08 2021

@author: ojas
"""
def gcd(m,n):
    if m< n: 
        (m,n) = (n,m)
    if(m%n) == 0:
        return n 
    else:
        return (gcd(n, m % n))

a = 72
b = 27
print("GCD is "+ str(gcd(a,b)))