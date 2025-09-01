from socket import *
serverName = 'localHost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
sentence = input('Frase in minuscolo: ')
clientSocket.send(sentence.encode())
modifiedSentence = clientSocket.recv(1024)
print('Dal Server:', modifiedSentence.decode())
clientSocket.close()