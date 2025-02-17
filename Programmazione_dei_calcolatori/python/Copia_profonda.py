# -*- coding: utf-8 -*-
"""
Created on Wed Feb 12 16:16:35 2025

@author: damic
"""

def deep_copy(a):
    b=[]
    
    for e in a:
        if type(e)==list:
            b.append(deep_copy(e))
        else:
            b.append(e)
    return b
    
    #Complessità Temporale O(n) caso peggiore (n annidamenti quindi n chiamate ricorsive)

a=[1,2,3,[1,[4,5, [6], 8], 1 ,4], 10]
b=deep_copy(a)
print(b)