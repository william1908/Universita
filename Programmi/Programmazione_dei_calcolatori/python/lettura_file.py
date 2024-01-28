f=open('file.txt')

d={}
for line in f:
    for x in line:
        if (x>='a' and x<='z') or (x>='a' and x<='Z'):
            if x in d:
                d[x]+=1
            else:
                d[x]=1
print(d)