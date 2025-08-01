# In[intersezione di due liste]
def Intersezione(a, b):  
    c=[]
    d={}
    for e in a:
        if e not in d:
            d[e]=1
        else:
            d[e]+=1
    for e in b:
        if e in d:
            c.append(e)
    return c

a=[1,3,5,6,7,9, 10]
b=[1,2,4,6,7,8,10]
print(Intersezione(a, b))

# In[Anagramma]
def Anagramma(a,b):
    '''
    Parametri: a, b stringhe
    Return: True se  esolo se a e b sono anagrammi
    '''
    
    da={}
    db={}
    for e in a:
        if e not in da:
            da[e]=1
        else:
            da[e]+=1
    for e in b:
        if e not in db:
            db[e]=1
        else:
            db[e]+=1
    for e in da:
        if e not in db or da[e]!=db[e]:
            return False
    for e in db:
        if e not in da or da[e]!=db[e]:
            return False
    return True

a="ottos"
b="otsto"
print (Anagramma(a, b))

# In[Gestione registro della classe]

def Insert(a, b):
    a[b]=[]
    
    
def Elimina(a, b):
    if b in a:
        del(a[b])
        print("Studente eliminato con successo")
        return a
    else:
        print('Studente non trovato')

    
def Inserisci_voto(a, b, v):
    if b in a:
        a[b].append(v)
        return a
    else:
        print('Studente non trovato')
    
def Media(a, b):
    if b in a:
        if len(a[b])==0:
            return None
        return sum(a[b])/len(a[b])
    else:
        print('Studente non trovato')


def t1(a):
    return a[0]
def t2(a):
    return a[2]




classe={}

Insert(classe, ('William', 'D\'Amico'))
Insert(classe, ('Simone', 'Colombo'))
Insert(classe, ('Andrea', 'Riccardi'))
Insert(classe, ('Valerio', 'Malagesi'))
print(classe)



classe=Inserisci_voto(classe, ('William', 'D\'Amico'), 8)
classe=Inserisci_voto(classe, ('William', 'D\'Amico'), 9)
print(classe)

media=Media(classe, ('William', 'D\'Amico'))
print(media)

classe=Elimina(classe, ('Andrea', 'Riccardi'))
print(classe)

Insert(classe, ('Andrea', 'Riccardi'))
print(classe)





