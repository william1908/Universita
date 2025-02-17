# In[BubbleSort]
a = [ 6, 1, 9, 0, -4, 5, 8, 10, 4 ]

n = len(a)

for c in range(n-1):
    # se non effettua scambi, la lista è ordinata
    terminato = True
    for i in range(n-1-c):
        if a[i] > a[i+1]:
            a[i], a[i+1] = a[i+1], a[i]
            terminato = False
    if terminato:
        # la lista è ordinata
        break
    
# Complessità temporale O(n**2) nel caso peggiore   
# Complessità spaziale O(1)

# In[BubbleSort con key]
def t1(e):
    return e[1]
def BubbleSort(a, key=None):
    
    
    def identity(e):
        return e
    
    if key==None:
        key=identity

    n = len(a)
    
    for c in range(n-1):
        terminato = True
        for i in range(n-1-c):
            if key(a[i]) > key(a[i+1]):
                a[i], a[i+1] = a[i+1], a[i]
                terminato = False
        if terminato:
            break
    return a
a = [ ('A', 6), ('B', 1), ('C', 9), ('D', 0), ('E',-4), ('F',5), ('G', 8), ('H', 10), ('I', 4) ]
print(BubbleSort(a, t1))

# In[Merge Sort]

def merge(a, lx, cx, rx):
    '''
        Input: a una lista di elementi
            lx, cx e rx indici in a t.c. lx <= cx <= rx
            con la proprietà che a[lx:cx] e a[cx:rx] sono ordinate
        Output: None
        
        Effetto collaterale a[lx:rx] è ordinata
    '''
    i, j = lx, cx
    c = []
    while i < cx and j < rx:
        if a[i] <= a[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(a[j])
            j += 1
    
    while i < cx:
        c.append(a[i])
        i+=1
        
    while j < rx:
        c.append(a[j])
        j += 1
        
    i = lx
    for e in c:
        a[i] = e
        i += 1
        
    # complessità temporale: O(n) dove n è la lunghezza
    #    della sottosequenza da ordinare
    # complessità spaziale: O(n) per via della lista c    

def merge_sort( a, lx = 0, rx = None ):
    '''
        Input: a una sequenza di elementi che possono essere
            confrontati
            lx < rx: indice sinistro e destro di a
        Output: None
        
        Effetto collaterale: ordinare in loco gli elementi di
            a[lx:rx]
    ''' 
    if rx == None:
        rx = len(a)

    if lx+1 >= rx:
        return None
    
    cx = int((lx+rx)/2)
    
    merge_sort(a, lx, cx)
    merge_sort(a, cx, rx)
    merge(a, lx, cx, rx)
    
    # complessità temporale: O(n log_2 n)
    # complessità spaziale: O(log_2 n) + O(n) = O(n)
    #
    # vedere dispense

a = [10, 21, 30, 34, 34, 38, 11, 13, 16, 17, 19, 0, 0, 10, 10]
merge_sort(a)
print(a)
