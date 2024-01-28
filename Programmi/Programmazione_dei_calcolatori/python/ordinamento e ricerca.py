# In[Bubble-sort]
a=[1,6,3,9,6,2]
n=len(a)
ordinata=False
c=0
while not ordinata:
    ordinata=True
    for i in range (n-1-c):
        if a[i]>a[i+1]:
            ordinata=False
            a[i], a[i+1]= a[i+1], a[i]
    c+=1
print(a)

# In[Merge-sort]

def merge(a, sx, cx, dx):

    c = []
    i, j = sx, cx
    
    while i < cx and j < dx: # O(n+m)
        if a[i] < a[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(a[j])
            j += 1
    
    if i == cx: # O(n+m)
        c.extend(a[j:dx])
    else:
        c.extend(a[i:cx])
    
    for i in range(len(c)):
        a[sx+i] = c[i]

def merge_sort( a, sx=0, dx=None ):

    if dx == None:
        dx = len(a)
    
    n = dx-sx
    if n >= 2:
        cx = (sx+dx)//2
        merge_sort(a, sx, cx)
        merge_sort(a, cx, dx)
        merge(a, sx, cx, dx)
           
a = [3,7,3,9,8,1,4,2,1,0,9,3,1,4,5]
merge_sort(a)
print(a)

# In[Ricerca binaria]

def bin_search (a, k):
    sx, rx = 0, len(a)

   
    while rx > sx:
       cx = (sx+rx)//2
       if a[cx] == k:
           return cx
       if k < a[cx]:
           rx = cx
       else:
           sx = cx+1
           
    return -1

a=[1,2,3,4,5,6,7,8,9]  

print(bin_search(a, 2))
        

# In[Ricerca binaria di un valore non presente nella lista]

def bin_search (a, k):
    n=len(a)
    sx, rx = 0, len(a)
    
    if k<a[0]:
        return 0
    if k>=a[-1]:
        return n

   
    while True:
       cx = (sx+rx)//2
       if a[cx] > k and a[cx-1]<=k:
           return cx
       if k < a[cx]:
           rx = cx
       else:
           sx = cx+1
           
a=[1,2,4,5,6,7,8,9]  

print(bin_search(a, 3))
        

