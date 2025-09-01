from socket import *
serverName = 'localHost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
n = input('Inserisci range di numeri: ')
clientSocket.send(n.encode())
n = int(n)
modifiedNumber = []
for i in range(1, n+1):
    number = i
    number = str(number)
    clientSocket.send(number.encode())
    modifiedNumber.append(clientSocket.recv(1024).decode())
    modifiedNumber[i-1] = int(modifiedNumber[i-1])

print('Dal Server:', modifiedNumber)
clientSocket.close()