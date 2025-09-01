from socket import *

serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print("Il server è pronto a riceere il messaggio")
while (True):
    n, clientAddress = serverSocket.recvfrom(2048)
    n =  int(n)
    for i in range(n):
        number, _ = serverSocket.recvfrom(2048)
        number.decode()
        number = int(number)
        modifiedNumber = number * 10
        modifiedNumber = str(modifiedNumber)
        serverSocket.sendto(modifiedNumber.encode(), clientAddress)