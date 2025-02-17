d={'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7}
print(d.items())#restituisce tutti gli ogetti del dizionario O(n)
print(d.keys()) #restituisce tutte le chiavi del dizionario O(n)
print(d.values()) #restituisce tutti i valori del dizionario O(n)
print(d.get('B'))  #restituisce il valore associato alla chiave O(1)
print(d.get('M', -1)) #restituisce il valore associato alla chiave O(1)
print(len(d))  #restituisce la lunghezza del dizioanrio O(1)

d['B']=8  #se la chiave esiste modifica il valore, altrimenti aggiunge un nuovo oggetto nel dizionario O(1)
d['H']=9

print(d.items())   

d2={'I': 10, 'L': 11, 'M': 12}
d.update(d2)  #combina 2 dizionari  O(n)
print(d.items())

# In[da lista a dizionario]

a=['a', 'b', 'c', 'd', 'd', 'b', 'g', 'b']
d={}
for e in a:
    if e not in d:
        d[e]=1
    else:
        d[e]+=1
print(d)

a=['a', 'b', 'c', 'd', 'd', 'b', 'g', 'b']
d={}
for e in a:
    if d.get(e)==0:
        d[e]=1
    else:
        d[e]+=1
print(d)
        
        