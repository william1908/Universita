# In[]
a=(1,2,3,4,5)
b=(6,7,8,9,10)
print(*zip(a,b))

#equivale a
#a=(1,2,3,4,5)
#b=(6,7,8,9,10)
#for c in zip(a,b):
#    print (c , end=' ')
#print()

# In[]

def concatena(*args):
    return ' '.join(args)

print(concatena('uno', 'due', 'tre', 'quattro'))

#equivale a
#
#def concatena(a):
#    return ' '.join(a)
#print(concatena(['uno', 'due', 'tre', 'quattro']))

# In[Operazioni equivalenti]

b = ['uno', 'due', 'tre', 'quattro']

print(' '.join(b))

for x in b:
    print(x, end=' ')
print()

print(*b)  # unpacking

print('uno', 'due', 'tre', 'quattro')

# In[]
a=['a', 'b', 'c', 'd', 'd', 'b', 'g', 'b']
d={}
for e in a:
    if e not in d:
        d[e]=1
    else:
        d[e]+=1

i=d.items();
print(i)
print(sorted(d.items()))
print(*sorted(d.items()))
X, Y=zip(*sorted(d.items()))
print(X, Y)
print(tuple(zip(*sorted(d.items()))))
