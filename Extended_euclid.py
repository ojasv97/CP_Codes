# -*- coding: utf-8 -*-
"""
Created on Sat Jan 30 21:09:40 2021

@author: ojas
"""
def extended_euclid(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = extended_euclid(b % a, a)
        return (g, y - (b // a) * x, x)

ans = extended_euclid(-7,3)
print("x = "+str(ans[1])+" y = "+str(ans[2])) 