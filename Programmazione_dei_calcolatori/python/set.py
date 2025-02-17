s={'William', 'Andrea', 'Simone', 'Valerio'} #Iniziallizzazione set
print(s)

s.add('Liviu')  #Inseriemnto nel set
print(s)

d={'William': {1,2}, 'Andrea':{1,4}, 'Simone': {5,6}, 'Valerio': {7, 8}} #dizionario con i set

d['Liviu']=set([4,7])  #aggiunta di un set nel dizionario
print(d)
d['Liviu'].add(6)  #aggiunta di un valore nel set in un dizionario
print(d)