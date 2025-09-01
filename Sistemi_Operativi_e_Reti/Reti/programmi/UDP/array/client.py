from socket import *

serverName = 'localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
n = input('Inserisci range: ')
clientSocket.sendto(n.encode(), (serverName, serverPort))
n = int(n)
modifiedNumber = []
for i in range(1, n+1):
    i = str(i)
    clientSocket.sendto(i.encode(), (serverName, serverPort))
    appoggio, _ = clientSocket.recvfrom(2048)
    appoggio.decode()
    modifiedNumber.append(int(appoggio))
print('Dal Server: ', modifiedNumber)
clientSocket.close()

