#Lungo un’autostrada ci sono diverse stazioni di servizio, ciascuna identificata da un nome e dalla sua
#posizione in chilometri dalla partenza.
#Implementare una funzione denominata max_gap che restituisce la lunghezza del tratto più lungo
#dell’autostrada in cui non è presente alcuna stazione di servizio.
#L'input della funzione è costituito da una lista di coppie (nome_stazione, km) ordinata
#alfabeticamente per nome


def max_gap(a):

    def t1(a):
        return a[1]

    a.sort(key=t1)
    max_len=t1(a[1])-t1(a[0])
    j=0
    for i in range(1,len(a)-1):
        if t1(a[i+1])>t1(a[i]):
            j=i
            max_len=t1(a[i+1])-t1(a[i])
    return max_len
    #Complessità temporale O(n), COmplessità spaziale O(1)


a=[('Stazione Albero', 10),('Stazione Chiesa',120),('Stazione Fiori', 54),('Stazione Villa',80)]

print("La lunghezza del tratto più lungo dell’autostrada in cui non è presente alcuna stazione di servizio e' di ", max_gap(a), ' km')