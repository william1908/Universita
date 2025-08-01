def massimo(a, key=None):
    if len(a) == 0:
        return None
    if key==None:
        m=a[0]
        for e in a:
            if e>m:
                m=e
        return m
    if key==2:
        if len(a) == 1:
            return None
        m=a[0]
        m2=a[1]
        if m2>m:
            m2, m= m, m2
        for e in a:
            if e>m:
                m, m2= e, m
            if e>m2 and e<m:
                m2=e
        return m2
a=[4,1]
print(massimo(a, 2))