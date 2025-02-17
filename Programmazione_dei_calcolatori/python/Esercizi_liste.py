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
    n=len(a)
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
    #Complessità temporale T(n)= n+1+1 quindi O(n)
    #complessità spaziale O(1)


a=[1,5,3,8,10,9]

m, M = f(a,5)

print(m)
print(M)

# In[Gestione registro della classe]

def Insert(a, b):
    a.append(b)
    
def Cerca_Studente(a, b):
    i=0
    trovato = 0
    while i<len(a):
        if a[i][0] == b[0] and a[i][1] == b[1]:
            trovato = 1
            break
        i+=1
    if trovato == 1:
        return i
    else:
        return -1
    
def Elimina(a, b):
    if Cerca_Studente(classe, b)==-1:
        print('Studente non trovato')
    else:
        i = Cerca_Studente(classe, b)
        del(a[i])
        print("Studente eliminato con successo")

    
def Modifica(a, b, v):
    if Cerca_Studente(classe, b)==-1:
        print('Studente non trovato')
    else:     
        i = Cerca_Studente(classe, b)
        a[i][2]=v
def Stampa(a):
    for x in a:
        print(x, end=' ')
    print()

def t1(a):
    return a[0]
def t2(a):
    return a[2]

def Media(a):
    if len(a)==0:
        return 0
    m= 0
    i=0
    for x in a:
        i+=1
        m+=x[2]
    return m/i    

classe=[]

Insert(classe, ['William', 'D\'Amico', 9])
Insert(classe, ['Simone', 'Colombo', 8])
Insert(classe, ['Andrea', 'Riccardi', 10])
Insert(classe, ['Valerio', 'Malagesi', 6])
Stampa(classe)

Elimina(classe, ['Andrea', 'Riccardi', 10])
Stampa(classe)

Modifica(classe, ['Valerio', 'Malagesi', 6], 7)
Stampa(classe)

c=sorted(classe, key=t1)
Stampa(c)
d=sorted(classe, key=t2, reverse=True)
Stampa(d)

media=Media(classe)
print('La media della classe è: ', media)







    
    
