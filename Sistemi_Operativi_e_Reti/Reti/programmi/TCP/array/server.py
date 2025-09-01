from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print('Il Server è pronto a ricevere')
while (True):
    connectionSocket, addr = serverSocket.accept()
    n = connectionSocket.recv(1024).decode()
    n = int(n)
    for i in range (n):
        number = connectionSocket.recv(1024).decode()
        number = int(number)
        capitalizedNumber = number*10
        capitalizedNumber = str(capitalizedNumber)
        connectionSocket.send(capitalizedNumber.encode())
    connectionSocket.close()