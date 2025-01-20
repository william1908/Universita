# In[Copia profonda]
def deep_cpy(a):
    b=[]
    for e in a:
        if type(e) == list:
            b.append(deep_cpy(e))
        else:
            b.append(e)
    return b

a=[1,4,2,[6,3]]
b=deep_cpy(a)
print(b)


# In[conteggio e somma interi in una lista e sottoliste]

def cont_int(a):
    c=0
    s=0
    for e in a:
        try:
            if type(e)==int:
                c+=1
                s+=e
            else:
                c, s = c+cont_int(e)[0], s+cont_int(e)[1]
        except TypeError:
            c, s= c, s
    return c, s

a=[1, 4, 2, [6, 3], [12, [5, 3], 7, 2], 8, 11.4]
c, s = cont_int(a)

print ("Nella lista ci sono", c, "interi e la loro somma e'", s)

# In[Intersezione liste]

def intersezione_liste( a, b ):
    '''
    input: a, b: liste
    output: lista c contenente gli elementi che sono sia in a che in b, senza ripetizioni
    '''
    d, c = {}, {} # O(1)
    
    for e in b:  # m iterazioni
        d[e] = None  # O(1)
    
    for e in a: # n iterazioni
        if e in d: # O(1) + O(1)
            c[e] = None # O(1)
            
    c = [ k for k in c ] # O( min(n, m) )
            
    return c

a = [2, 3, 4, 1, 6, 7, 6]
b = [5, 7, 8, 4, 0, 7, 4]

c = intersezione_liste( b, a )

print(c)

# In[Costruzione della lista con list comprehension]

list=[x for x in range (10) if x%2==0 and x!=0]
    #list=[]
    #for x in range(10):
    #   if x%2==0 and x!=0:
    #       list.append(x)
print(list)