import sys
def convert(myString):
    done = ''
    for c in myString:
        if c.islower():
            c = c.replace(c, c.upper())
            done = done + c
        elif c.isupper():
            done = done + c
        else:
            done = done + c

    return (done)

from socket import *
serverPort = int(sys.argv[1])
bufferSize = 1024
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print('The server is ready to receive')
while True:
    connectionSocket, addr = serverSocket.accept()
    message = connectionSocket.recv(bufferSize)
    print "Message received from client:", message
    message = convert(message)
    connectionSocket.send(message) # echo
    connectionSocket.close()
