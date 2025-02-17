# In[Lambda function]
def quadrato (a):
    return a**2

a=3

print(quadrato(3))

f = lambda x: x**2

print(f(a))

print((lambda x:x**2)(a))

# In[list comprehension]

l1=[1,2,3,4,5,6]
l2=[]
for x in l1:
    l2.append(x**2)
print(l2)
#può essere sostituito con

a=[1, 2, 3, 4, 5, 6]
b=[e ** 2 for e in a]
print(b)
#oppure
c=[i**2 for i in range(1,7)]
print(c)

