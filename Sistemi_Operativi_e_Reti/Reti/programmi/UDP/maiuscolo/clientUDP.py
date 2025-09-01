from socket import *

serverName = 'localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input('Frase in minuscolo: ')
clientSocket.sendto(message.encode(), (serverName, serverPort))
modifiedMessage, _ = clientSocket.recvfrom(2048)
print('Dal Server: ', modifiedMessage.decode())
clientSocket.close()

