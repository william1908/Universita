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

# In[frequenza]

def mode(list):
    dict={}
    for n in list:   #O(n)
        if n in dict:
            dict[n]+=1
        else:
            dict[n]=1
    m=max(dict.values()) #O(n) + Theta(n)
    list_m=[num for num, freq in dict.items() if freq==m] #O(n)
    return list_m
#complessità temporale:  O(n)
#complessità Spaziale:  O(n)

list=[1,4,1,4,6,3,7,4]

list_m=mode(list)

print(list_m)



