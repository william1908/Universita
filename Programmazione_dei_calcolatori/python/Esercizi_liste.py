# In[]
def del_item(a, v):
    i=0
    while i<len(a):
        if a[i]==v:
            break
        i+=1
        
    while i<len(a)-1:
        a[i]=a[i+1]
        i+=1
    del(a[i])
            
        
L = [4, 1, 7, 6, 5, 6, 8, 2, 3, 1, 2, 7, 8]
del_item(L, 1)
print(L)

# In[]
def f(a, v):
    n=len(a)  #O(1)
    if v not in a:  #O(n)
        return None
    m=[]
    M=[]
    i=0  #O(1)
    
    while i<n:  #O(n)
        if a[i]<=v:
            m.append(a[i])  #O(1)
        else:
            M.append(a[i])  #O(1)
        i+=1
    return m, M
    #Complessità temporale  O(n)
    #complessità spaziale O(1)


a=[1,5,3,8,10,9]

m, M = f(a,5)

print(m)
print(M)