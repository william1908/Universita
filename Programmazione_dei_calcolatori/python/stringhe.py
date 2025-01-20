# In[slicing]
x="programmazione con i calcolatori"
y=x[21:]
print(y)
y=x[::-1]
print(y)

# In[Palindroma]

x=input("Inserire parola: ")
i=0
while i<len(x)//2:
    if x[i]!=x[len(x)-1-i]:
        print("Non palindroma")
        break
    i+=1
if i==len(x)//2:
    print("Palindroma")
    
# In[Anagramma]

def anagrammi(a, b):
    
    if len(a) != len(b):
        return False
    
    return ''.join(sorted(a)) == ''.join(sorted(b))

# In[]

def minuscolo( x ):

    return chr(ord(x) + ord('a') - ord('A'))
