# In[]
names = ['Tom','Mario','Luisa']
surnames = ['Rossi', 'Verdi', 'Gialli']
ages = [22,21,23]

contacts = []

for name, surname, age in zip(names,surnames,ages):
  contacts.append({'nome': name, 'cognome': surname, 'age': age})
  
print(contacts)

# In[]

list=['banana', 'albero', 'tubo', 'libro', 'marmitta']
list2=[]
for c in list:
    list2.append(len(c))
print(list2)

list3=[len(c) for c in list]
print(list3)

# In[]

a="programmazione dei compilatori"

d={}
for c in a:
    if c not in d.keys():
        d[c]=1
    else:
        d=d.get(c, 0)+1

