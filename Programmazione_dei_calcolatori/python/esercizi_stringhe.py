# In[Ordinamento date in una lista con paramentro key]
def t1(l):
    return l[6:10], l[3:5], l[0:2]

l=['10/08/2004', '05/04/1987', '01/12/2020', '21/06/1999']

l.sort(key=t1)
print(l)