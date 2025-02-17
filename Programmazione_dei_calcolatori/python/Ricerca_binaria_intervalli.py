# In[Ricerca Binaria]
def RicercaBinaria(a, v):
    lx, rx= 0, len(a)-1
    if v < a[lx]:
        return None
    if v> a[rx]:
        return None
    
    while lx<=rx:
        cx=(lx+rx)//2
        if v==a[cx]:
            return cx
        elif v<a[cx]:
            rx=cx-1
        else:
            lx=cx+1
    return None

    #Complessità Temporale O(log_2(n))
    #Complessità Spaziale O(1)
a=[1, 5, 7, 10, 100]
print(RicercaBinaria(a, 1))
# In[Ricerca Intervallo]
def ricerca_intervallo(a, k):
    '''
    Input: a, una lista di numeri ordinati in modo crescente, valori consecutivi
        in a rappresentano un intervallo chiuso a sinistra e aperto a destra;
        k, un numero
    Output: se k>=a[0] e k < a[-1], una coppia (a[i], a[i+1]) che rappresenta
        l'intervallo contenente k; se k < a[0] la funzione ritorna ('-inf', a[0]);
        se k >= a[-1] la funzione ritorna (a[-1], '+inf')
    '''
    lx, rx = 0, len(a)-1
    
    if k < a[0]:
        return ('-inf', a[0])
    
    if k >= a[-1]:
        return (a[-1], '+inf')
    
    while lx <= rx:
        cx = int( (lx+rx)/2 )
        if k == a[cx]:
            return ( a[cx], a[cx+1])
        elif k < a[cx]:
            rx = cx-1
        else:
            lx = cx+1
     
    if k < a[cx]:
        return ( a[cx-1], a[cx]) 
    elif k > a[cx]:
        return ( a[cx], a[cx+1] )
    

# complessità spaziale: O(1)
# complessità temporale: O(log_2 n)
    
a = [-2, 3, 9, 12, 13]
k = 4

print( ricerca_intervallo(a, k) )