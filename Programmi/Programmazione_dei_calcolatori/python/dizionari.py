# In[Ordinamento di un dizionario in base al valore]

def ordinamento_biblioteca(d):
    lista_d=[]
    for k in d:
        lista_d.append((k, d[k]))
    lista_d.sort(key=lambda t: t[1], reverse=True)
    return lista_d

d={'prog': 5, 'zione': 1, 'python': 2}

lista=ordinamento_biblioteca(d)
print(lista)

# In[Anagramma]

def Anagramma (a,b):
    if len(a)!=len(b):
        return False
    da, db= {}, {}
    for x in a:
        da[x]=da.get(x,0)+1
    for x in b:
        db[x]=db.get(x,0)+1
    return da==db

a="gnomo"
b='omgno'

print(Anagramma(a, b))

# In[Intersezione dizionari]

def intersezione_dizionari( d0, d1, f = lambda x, y: x+y ):
    '''
    input: d0 e d1 dizionari che mappano stringhe in numeri
    output: un dizionario c tale che:
        - le chiavi di c sono quelle comuni in d0 che in d1
        - se k è una chiave di c allora c[k] = f(d0[k], d1[k]) 
    '''
    
    n, m = len(d0), len(d1)
    
    
    dt0, dt1 = (d1, d0) if n > m else (d0, d1) # alias costo O(1)
    

        
    c = {}
    
    for e in dt0: # n iterazioni
        if e in dt1:
            c[e] = f(dt0[e], dt1[e]) # O(1)
            
    return c

    # Complessità temporale: min( Theta(n), Theta(m) )
    
a = {'uno':1, 'due': 2, 'quattro':4, 'sei':6}
b = {'uno':10,  'quattro':40, 'zero':0}

c = intersezione_dizionari(a, b, f=max)

print(c)

# In[]

def minuscolo( x ):
    '''
    Parameters
    ----------
    x : lettera maiuscola

    Returns
    -------
    la miuscola di x
    '''
    return chr(ord(x) + ord('a') - ord('A'))




f = open('promessi_sposi.txt')
d = {}

for line in f:                                              
    for x in line:
        if x in ['è', 'é']:
            x = 'e'
        elif x in ['ò']:
            x = 'O'
        if (x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z'):
            if (x >= 'A' and x <= 'Z'):
                x = minuscolo(x)
            d[x] = d.get(x,0) + 1
lista_d = [ t for t in d.keys() ]


    



