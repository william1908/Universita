#Le stringhe in python sono immutabili, quindi ogni operazione su di esse ne crea una nuova.

# In[concatenazione e ripetizione]
a='Programmazione dei Calcolatori '
b='con Laboratorio'

print(a+b)#crea una nuova stringa
print(a*2)#crea una nuova stinga



# In[Slicing]
a='Programmazione dei Calcolatori con Laboratorio'
#a[indice inzio: indice fine (escluso): passo (opzionale)]
#tutte queste operazione creano nuove stringhe

print(a[:4])
print(a[3:10])
print(a[::3])

#per ottenere una stinga al contrario 
print(a[::-1])

# In[Funzioni per le stringhe]

a='Programmazione dei Calcolatori con Laboratorio'

print(len(a))#O(1), restituisce il numero di caratteri della stringa. la lunghezza è un dato salvato, quindi non va calcolato attraverso cicli.

b=a.split()#l'argomento del metodo è il carattere di divisione, è opzionale. Il metodo restituisce una lista

print(b)

print(' '.join(b))#la funzione unisce più stringhe con il carattere di divisione prima del punto.

c='10'
print(c.isdigit())#restituisce True se la stringa è composta da numeri



